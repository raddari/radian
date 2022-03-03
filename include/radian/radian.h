#pragma once

#include "radian-internal.h"


#define RADIAN_READ_MANY(file, dest, n) _RADIAN_READ_MANY(file, dest, n)
#define RADIAN_READ(file, dest)         _RADIAN_READ(file, dest)
#define RADIAN_READ_BE(file, dest)      _RADIAN_READ_BE(file, dest)
#define RADIAN_READ_LE(file, dest)      _RADIAN_READ_LE(file, dest)

#define RADIAN_WRITE_MANY(file, src, n) _RADIAN_WRITE_MANY(file, src, n)
#define RADIAN_WRITE(file, src)         _RADIAN_WRITE(file, src)
#define RADIAN_WRITE_BE(file, src)      _RADIAN_WRITE_BE(file, src)
#define RADIAN_WRITE_LE(file, src)      _RADIAN_WRITE_LE(file, src)
