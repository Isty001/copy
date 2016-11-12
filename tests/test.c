#include <string.h>
#include <malloc.h>
#include "rimraf/rimraf.h"
#include "copy.h"
#include "minunit/minunit.h"
#include "fs/fs.h"


MU_TEST(test_file)
{
    char *from = "./tests/fixture/file2.txt";
    char *to = "./tests/target/file2.txt";

    mu_assert_int_eq(0, copy_file(from, to));

    mu_assert(0 == fs_exists(to), "File does not exist");

    char *from_content = fs_read(from);
    char *to_content = fs_read(to);
    mu_assert(0 == strcmp(from_content, to_content), "File contents are not equal");

    free(from_content);
    free(to_content);

    unlink(to);

    mu_assert_int_eq(-1, copy_file("invalid-file", "to"));
}

MU_TEST(test_dir)
{
    mu_assert_int_eq(0, copy_dir("./tests/fixture", "./tests/target/fixture"));

    mu_assert(0 == fs_exists("./tests/target/fixture/file2.txt"), "File does not exist");
    mu_assert(0 == fs_exists("./tests/target/fixture/nested/file.txt"), "File does not exist");

    rimraf("./tests/target/fixture");
}


int main(void)
{
    MU_RUN_TEST(test_file);
    MU_RUN_TEST(test_dir);

    MU_REPORT();
}
