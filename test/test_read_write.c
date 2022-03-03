#include "radian/radian.h"

#include "unity.h"


void test_always_true() {
  TEST_ASSERT(1);
}


int main() {
  UNITY_BEGIN();
  RUN_TEST(test_always_true);
  return UNITY_END();
}

void setUp() {
}

void tearDown() {
}
