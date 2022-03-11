#include "radian/radian.h"

#include "unity.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static uint8_t buffer[9];
static FILE *test_file;


void test_write_be_u8() {
  uint8_t de = 0xDE;
  uint8_t ad = 0xAD;
  uint8_t be = 0xBE;
  uint8_t ef = 0xEF;

  RADIAN_WRITE_BE(test_file, de);
  fflush(test_file);
  TEST_ASSERT_EQUAL(0, memcmp((uint8_t[]) {0xDE}, buffer, 1));

  RADIAN_WRITE_BE(test_file, ad);
  fflush(test_file);
  TEST_ASSERT_EQUAL(0, memcmp((uint8_t[]) {0xAD}, buffer + 1, 1));

  RADIAN_WRITE_BE(test_file, be);
  fflush(test_file);
  TEST_ASSERT_EQUAL(0, memcmp((uint8_t[]) {0xBE}, buffer + 2, 1));

  RADIAN_WRITE_BE(test_file, ef);
  fflush(test_file);
  TEST_ASSERT_EQUAL(0, memcmp((uint8_t[]) {0xEF}, buffer + 3, 1));
}

void test_write_be_u16() {
  uint16_t dead = 0xDEAD;
  uint16_t beef = 0xBEEF;

  RADIAN_WRITE_BE(test_file, dead);
  fflush(test_file);
  TEST_ASSERT_EQUAL(0, memcmp((uint8_t[]) {0xDE, 0xAD}, buffer, 2));

  RADIAN_WRITE_BE(test_file, beef);
  fflush(test_file);
  TEST_ASSERT_EQUAL(0, memcmp((uint8_t[]) {0xBE, 0xEF}, buffer + 2, 2));
}

void test_write_be_u32() {
  uint32_t deadbeef = 0xDEADBEEF;

  RADIAN_WRITE_BE(test_file, deadbeef);
  fflush(test_file);
  TEST_ASSERT_EQUAL(0, memcmp((uint8_t[]) {0xDE, 0xAD, 0xBE, 0xEF}, buffer, 4));
}

void test_write_be_u64() {
  uint64_t deadbeef = 0xDEADBEEF0BADC0DE;

  RADIAN_WRITE_BE(test_file, deadbeef);
  fflush(test_file);
  TEST_ASSERT_EQUAL(0, memcmp((uint8_t[]) {0xDE, 0xAD, 0xBE, 0xEF, 0x0B, 0xAD, 0xC0, 0xDE}, buffer, 8));
}

int main() {
  UNITY_BEGIN();

  RUN_TEST(test_write_be_u8);
  RUN_TEST(test_write_be_u16);
  RUN_TEST(test_write_be_u32);
  RUN_TEST(test_write_be_u64);

  return UNITY_END();
}

void setUp() {
  memset(buffer, 0, sizeof buffer);
  test_file = fmemopen(buffer, sizeof buffer, "w");
  if (!test_file) {
    perror("opening memory stream");
    exit(EXIT_FAILURE);
  }
}

void tearDown() {
  fclose(test_file);
}
