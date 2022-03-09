#pragma once

#include <stdint.h>
#include <stdio.h>


#if !(defined(RADIAN_HOST_BE) || defined(RADIAN_HOST_LE))
  #error "Host endianness is not defined" \
         " - please build with CMake or manually define RADIAN_HOST_BE or RADIAN_HOST_LE"
#endif


#define _RADIAN_S_(x) #x
#define _RADIAN_S(x) _RADIAN_S_(x)
#define _RADIAN_DIAG _RADIAN_S(__FILE__) ":" _RADIAN_S(__LINE__) ": "


#define _RADIAN_BSWAP(target) (_Generic((target), \
    uint16_t: _RADIAN_BSWAP_16(target),           \
    uint32_t: _RADIAN_BSWAP_32(target),           \
    uint64_t: _RADIAN_BSWAP_64(target),           \
    default:  _RADIAN_BSWAP_NOP(target)))

#define _RADIAN_BSWAP_NOP(target) target

#define _RADIAN_BSWAP_16(target) \
    ((((target) & 0xFF) << 8) | ((target) >> 8))

#define _RADIAN_BSWAP_32(target)                       \
    ((_RADIAN_BSWAP_16(((target) & 0xFFFF)) << 16)     \
    | _RADIAN_BSWAP_16(((target) >> 16)))

#define _RADIAN_BSWAP_64(target)                       \
    ((_RADIAN_BSWAP_32(((target) & 0xFFFFFFFF)) << 32) \
    | _RADIAN_BSWAP_32(((target) >> 32)))


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
        dest = _RADIAN_BSWAP(dest);   \
      }
#else
  #define _RADIAN_READ_BE(file, dest) _RADIAN_READ(file, dest)
  #define _RADIAN_READ_LE(file, dest) \
      {                               \
        _RADIAN_READ(file, dest);     \
        dest = _RADIAN_BSWAP(dest);   \
      }
#endif

#define _RADIAN_WRITE_MANY(file, src, n)
#define _RADIAN_WRITE(file, src)
#define _RADIAN_WRITE_BE(file, src)
#define _RADIAN_WRITE_LE(file, src)
