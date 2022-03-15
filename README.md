# radian
![license](https://img.shields.io/github/license/raddari/radian)
![linux](https://github.com/raddari/radian/workflows/linux/badge.svg)
![macos](https://github.com/raddari/radian/workflows/macos/badge.svg)
![windows](https://github.com/raddari/radian/workflows/windows/badge.svg)

Header-only library of macros to assist with reading and writing big/little endian values.

## Adding to your project
### CMake
I recommend using [**FetchContent**](https://cmake.org/cmake/help/latest/module/FetchContent.html) to download and populate this library in your CMake project.

```cmake
cmake_minimum_required(VERSION 3.20)
project(example_project LANGUAGES C)

include(FetchContent)
FetchContent_Declare(
  radian
  GIT_REPOSITORY https://github.com/raddari/radian.git
  GIT_TAG main
)
FetchContent_MakeAvailable(radian)

add_executable(example_exe main.c)
target_link_libraries(example_exe PRIVATE
    radian::radian
)
```

### Other
Copy the **include/radian** folder into your include directory. Define `RADIAN_HOST_BE` or `RADIAN_HOST_LE` before including **radian/radian.h**.

## Usage
Example program:
```c
#define RADIAN_HOST_LE // Not required if building with CMake
#include "radian/radian.h"

#include <stdint.h>
#include <stdio.h>


int main() {
  struct {
    uint64_t a;
    uint32_t b;
    uint16_t c;
  } data;
  
  FILE *file = fopen("somefile.bin", "r");
  RADIAN_READ_BE(file, data.a);
  RADIAN_READ_LE(file, data.b);
  RADIAN_READ_LE(file, data.c);
  fclose(file);
  
  FILE *output = fopen("output.bin", "w");
  RADIAN_WRITE_BE(output, data.a);
  RADIAN_WRITE_LE(output, data.b);
  RADIAN_WRITE_LE(output, data.c);
  fclose(output);
  
  return 0;
}
```

## TODO
- [ ] Documentation
