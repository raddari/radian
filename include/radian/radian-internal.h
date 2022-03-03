#pragma once

#include <stdio.h>


#if !defined(RADIAN_HOST_BE) && !defined(RADIAN_HOST_LE)
  #error Host endianness is undefined
#endif


#define _RADIAN_BSWAP(target)

#define _RADIAN_READ_MANY(file, dest, n)                         \
    {                                                            \
      size_t nread = fread((dest), sizeof *(dest), (n), (file)); \
      if (nread < (n)) {                                         \
        if (feof(file)) {                                        \
          fprintf(stderr, "End of file reading " #dest);         \
        }                                                        \
        if (ferror(file)) {                                      \
          fprintf(stderr, "Error reading file " #dest);          \
        }                                                        \
      }                                                          \
    }

#define _RADIAN_READ(file, dest) _RADIAN_READ_MANY(file, &dest, 1)

#ifdef RADIAN_HOST_LE
  #define _RADIAN_READ_LE(file, dest) _RADIAN_READ(file, dest)
  #define _RADIAN_READ_BE(file, dest) \
      {                               \
        _RADIAN_READ(file, dest);     \
        _RADIAN_BSWAP(dest);          \
      }
#else
  #define _RADIAN_READ_BE(file, dest) _RADIAN_READ(file, dest)
  #define _RADIAN_READ_LE(file, dest) \
      {                               \
        _RADIAN_READ(file, dest);     \
        _RADIAN_BSWAP(dest);          \
      }
#endif

#define _RADIAN_WRITE_MANY(file, src, n)
#define _RADIAN_WRITE(file, src)
#define _RADIAN_WRITE_BE(file, src)
#define _RADIAN_WRITE_LE(file, src)
