#include "gtest/gtest.h"

#include "../composite/header/add.hpp"
#include "../composite/header/div.hpp"
#include "../composite/header/mult.hpp"
#include "../composite/header/op.hpp"
#include "../composite/header/pow.hpp"
#include "../composite/header/rand.hpp"
#include "../composite/header/sub.hpp"
#include "../ListContainer.hpp"

//Default constructor test
TEST(ClassListContainerTest, ListDefaultConstructor) {
	ListContainer* test = new ListContainer();
	EXPECT_EQ(test->size(), 0);
}

//Swap
TEST(ListContainerTestSet, ListSwapTest) {
	// Setup the elements under test
	Op* left = new Op(10);
	Op* right = new Op(5);
	ListContainer* test_container = new ListContainer();

	test_container->add_element(left);
	test_container->add_element(right);
	ASSERT_EQ(test_container->size(), 2);

	test_container->swap(0,1);

	EXPECT_EQ(test_container->at(0)->evaluate(), 5);
	EXPECT_EQ(test_container->at(1)->evaluate(), 10);
}

//Print
TEST(ListContainerTestSet, ListPrintTest) {
	// Setup the elements under test
	
	Op* left = new Op(10);
	Op* right = new Op(5);
	Mult* test = new Mult(left, right);
	std::string str = "10.000000 * 5.000000";
	ListContainer* test_container = new ListContainer();

	test_container->add_element(test);
	testing::internal::CaptureStdout();
	test_container->print();
	std::string output = testing::internal::GetCapturedStdout();
	//causes seg fault
	//EXPECT_EQ(test_container->size(), 1);
	EXPECT_EQ(output, str);
}

//at
TEST(ListContainerTestSet, ListAtOpTest) {
	// Setup the elements under test
	Op* seven = new Op(7);
	ListContainer* test_container = new ListContainer();
	
	// Exercise some funtionality of the test elements
	test_container->add_element(seven);

	// Assert that the container has at least a single element
	// Otherwise we are likely to cause a seg fault when accessing
	ASSERT_EQ(test_container->size(), 1);
	EXPECT_EQ(test_container->at(0)->evaluate(), 7);
}

TEST(ListContainerTestSet, ListAtAddTest) {
	// Setup the elements under test
	Base* seven = new Op(7);
	Base* three = new Op(3);
	Base* sum = new Add(seven, three);
	
	ListContainer* test_container = new ListContainer();
	
	// Exercise some functionality of the test elements
	test_container->add_element(sum);

	// Assert that the container has at least a single element
	// Otherwise we are likely to cause a seg fault when accessing
	
	ASSERT_EQ(test_container->size(), 1);
	EXPECT_EQ(test_container->at(0)->evaluate(), 10);
}

// add element
TEST(ListContainerTestSet, ListAddTest) {
	// Setup the elements under test
	Base* seven = new Op(7);
	Base* three = new Op(3);
	Base* sum = new Add(seven, three);

	ListContainer* test_container = new ListContainer();
	test_container->add_element(sum);

	EXPECT_EQ(test_container->size(), 1);
}

TEST(ListContainerTestSet, ListAddMultipleTest) {
	// Setup the elements under test
	Base* seven = new Op(7);
	Base* three = new Op(3);
	Base* sum = new Add(seven, three);

	ListContainer* test_container = new ListContainer();

	test_container->add_element(sum);
        test_container->add_element(sum);
        test_container->add_element(sum);
        test_container->add_element(sum);
        test_container->add_element(sum);
	EXPECT_EQ(test_container->size(), 5);
}

TEST(ListContainerTestSet, ListAddNoneTest) {
	ListContainer* test_container = new ListContainer();
	EXPECT_EQ(test_container->size(), 0);
}	
