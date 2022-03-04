#include "radian/radian.h"

#include "unity.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


static FILE *test_file;


void test_read_be_bytes() {
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


int main() {
  UNITY_BEGIN();
  RUN_TEST(test_read_be_bytes);
  return UNITY_END();
}

void setUp() {
  test_file = fopen("deadbeef.bin", "rb");
  if (!test_file) {
    perror("opening deadbeef.bin file");
    exit(EXIT_FAILURE);
  }
}

void tearDown() {
  fclose(test_file);
}
