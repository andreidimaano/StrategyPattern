#include "gtest/gtest.h"
 
#include "../composite/header/add.hpp"
#include "../composite/header/div.hpp"
#include "../composite/header/mult.hpp"
#include "../composite/header/op.hpp"
#include "../composite/header/pow.hpp"
#include "../composite/header/rand.hpp"
#include "../composite/header/sub.hpp"
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
TEST(VectorContainerTestSet, vectorAtOpTest) {
    // Setup the elements under test
    Op* seven = new Op(7);
    VectorContainer* test_container = new VectorContainer();

    // Exercise some functionality of hte test elements
    test_container->add_element(seven);

    // Assert that the container has at least a single element
    // otherwise we are likely to cause a segfault when accessing
    ASSERT_EQ(test_container->size(), 1);
    EXPECT_EQ(test_container->at(0)->evaluate(), 7);
}
TEST(VectorContainerTestSet, vectorAtAddTest) {
    // Setup the elements under test
    Base* seven = new Op(7);
    Base* three = new Op(3);
    Base* sum = new Add(seven, three);

    VectorContainer* test_container = new VectorContainer();

    // Exercise some functionality of hte test elements
    test_container->add_element(sum);

    // Assert that the container has at least a single element
    // otherwise we are likely to cause a segfault when accessing
    ASSERT_EQ(test_container->size(), 1);
    EXPECT_EQ(test_container->at(0)->evaluate(), 10);
}


//add element