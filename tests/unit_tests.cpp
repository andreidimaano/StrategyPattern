#include "gtest/gtest.h"

#include "list_test.hpp"
#include "vector_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
