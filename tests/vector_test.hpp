#include "gtest/gtest.h"
 
#include "../VectorContainer.hpp"

//Default constructor test
TEST(ClassVectorContainerTest, vectorDefaultConstructor) {
    VectorContainer* test = new VectorContainer();
    EXPECT_EQ(test->size(), 0);
}

//Swap

//Print

//Size

//at

//add element