/*
  MIT License

  Copyright (c) 2022 raddari

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/
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
