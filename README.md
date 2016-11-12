#### Install

With [clib](https://github.com/clibs/clib):
```
clib install isty001/copy
```

..or
```
git clone https://github.com/isty001/copy
```


#### Usage

```C
#include "copy.h"
```

Copy one file:

```C
copy_file("./dir/file.txt", "./target_dir/file.txt");
```

Copy a directory recursively:

```C
copy_dir("./dir/sub_dir", "./target_dir/sub_dir");
```

Both `"./target_dir/file.txt"` and `"./target_dir/sub_dir"` will be created if needed. 
