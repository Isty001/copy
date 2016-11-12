CC = cc
CFLAGS := -g -Wall -Wno-deprecated-declarations -I deps -I src -l curl
TEST_SRC = $(shell find src tests deps -name '*.c')

compile:
	$(CC) $(CFLAGS) $(TEST_SRC) -o test.o

test:
	make compile
	 ./test.o

valgrind:
	make compile
	valgrind --track-origins=yes --leak-check=full --show-reachable=yes ./test.o

