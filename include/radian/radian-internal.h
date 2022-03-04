#pragma once

#include <stdio.h>


#if !(defined(RADIAN_HOST_BE) || defined(RADIAN_HOST_LE))
  #error "Host endianness is not defined"
#endif


#define _RADIAN_S_(x) #x
#define _RADIAN_S(x) _RADIAN_S_(x)
#define _RADIAN_DIAG _RADIAN_S(__FILE__) ":" _RADIAN_S(__LINE__) ": "

#define _RADIAN_BSWAP(target)

#define _RADIAN_READ_MANY(file, dest, n)                                   \
    {                                                                      \
      size_t nread = fread((dest), sizeof *(dest), (n), (file));           \
      if (nread < (n)) {                                                   \
        if (feof(file)) {                                                  \
          fprintf(stderr, _RADIAN_DIAG "End of file reading " #dest "\n"); \
        }                                                                  \
        if (ferror(file)) {                                                \
          fprintf(stderr, _RADIAN_DIAG "Error reading file " #dest "\n");  \
        }                                                                  \
      }                                                                    \
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
