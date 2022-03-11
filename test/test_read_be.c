#include "radian/radian.h"

#include "unity.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


static uint8_t buffer[] = {0xDE, 0xAD, 0xBE, 0xEF, 0x0B, 0xAD, 0xC0, 0xDE};
static FILE *test_file;


void test_read_be_u8() {
  uint8_t de, ad, be, ef;
  RADIAN_READ_BE(test_file, de);
  TEST_ASSERT_EQUAL_UINT8(0xDE, de);

  RADIAN_READ_BE(test_file, ad);
  TEST_ASSERT_EQUAL_UINT8(0xAD, ad);

  RADIAN_READ_BE(test_file, be);
  TEST_ASSERT_EQUAL_UINT8(0xBE, be);

  RADIAN_READ_BE(test_file, ef);
  TEST_ASSERT_EQUAL_UINT8(0xEF, ef);
}

void test_read_be_u16() {
  uint16_t dead, beef;
  RADIAN_READ_BE(test_file, dead);
  TEST_ASSERT_EQUAL_UINT16(0xDEAD, dead);

  RADIAN_READ_BE(test_file, beef);
  TEST_ASSERT_EQUAL_UINT16(0xBEEF, beef);
}

void test_read_be_u32() {
  uint32_t deadbeef;
  RADIAN_READ_BE(test_file, deadbeef);
  TEST_ASSERT_EQUAL_UINT32(0xDEADBEEF, deadbeef);
}

void test_read_be_u64() {
  uint64_t deadbeef;
  RADIAN_READ_BE(test_file, deadbeef);
  TEST_ASSERT_EQUAL_UINT64(0xDEADBEEF0BADC0DE, deadbeef);
}

int main() {
  UNITY_BEGIN();

  RUN_TEST(test_read_be_u8);
  RUN_TEST(test_read_be_u16);
  RUN_TEST(test_read_be_u32);
  RUN_TEST(test_read_be_u64);

  return UNITY_END();
}

void setUp() {
  test_file = fmemopen(buffer, sizeof buffer, "rb");
  if (!test_file) {
    perror("opening deadbeef stream");
    exit(EXIT_FAILURE);
  }
}

void tearDown() {
  fclose(test_file);
}
