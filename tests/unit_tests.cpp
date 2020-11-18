#include "gtest/gtest.h"

#include "vector_tests.hpp"
#include "sort_tests.hpp"
#include "list_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
