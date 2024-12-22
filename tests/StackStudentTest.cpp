#include <gtest/gtest.h>
#include <chrono>
#include <future>

#include <string>

#include "../src/ArrayStack.hpp"

struct StackStudentTest : public ::testing::Test {
    const int TIMEOUT = 200;
    ArrayStack* array;

    virtual void SetUp() override {
        array = new ArrayStack();
    }

    virtual void TearDown() override {
        delete array;
    }
};

TEST_F(StackStudentTest, TestInitialization) {
    ASSERT_EQ(0, array->getSize());
    // assertArrayEquals(new Object[ArrayQueue.INITIAL_CAPACITY], array->getBackingArray());
    // std::string other[array->INITIAL_CAPACITY];
    // ASSERT_TRUE(std::memcmp(other, array, sizeof(other)) == 0);
}

TEST_F(StackStudentTest, TestArrayPush) {
    array->push("0a");    // 0a
    array->push("1a");    // 0a, 1a
    array->push("2a");    // 0a, 1a, 2a
    array->push("3a");    // 0a, 1a, 2a, 3a
    array->push("4a");    // 0a, 1a, 2a, 3a, 4a

    ASSERT_EQ(5, array->getSize());

    std::string* expected = new std::string[array->INITIAL_CAPACITY];
    expected[0] = "0a";
    expected[1] = "1a";
    expected[2] = "2a";
    expected[3] = "3a";
    expected[4] = "4a";

    // assertArrayEquals(expected, array->getBackingArray());
    ASSERT_TRUE(std::memcmp(expected, array, sizeof(expected) * sizeof(std::string)));
}

TEST_F(StackStudentTest, TestArrayPop) {
    std::string temp = "5a";

    array->push(temp);    // 0a
    array->push("1a");    // 0a, 1a
    array->push("2a");    // 0a, 1a, 2a
    array->push("3a");    // 0a, 1a, 2a, 3a
    array->push("4a");    // 0a, 1a, 2a, 3a, 4a
    array->push("5a");    // 0a, 1a, 2a, 3a, 4a, 5a
    ASSERT_EQ(6, array->getSize());

    // assertSame(temp, array->pop());  // 1a, 2a, 3a, 4a, 5a
    ASSERT_EQ(temp, array->pop());

    ASSERT_EQ(5, array->getSize());

    std::string* expected = new std::string[array->INITIAL_CAPACITY];
    expected[1] = "1a";
    expected[2] = "2a";
    expected[3] = "3a";
    expected[4] = "4a";
    expected[5] = "5a";

    // assertArrayEquals(expected, array->getBackingArray());
    ASSERT_TRUE(std::memcmp(expected, array, sizeof(expected) * sizeof(std::string)));
}

TEST_F(StackStudentTest, TestArrayPeek) {
    std::string temp = "4a";

    array->push(temp);    // 0a
    array->push("1a");    // 0a, 1a
    array->push("2a");    // 0a, 1a, 2a
    array->push("3a");    // 0a, 1a, 2a, 3a
    array->push("4a");    // 0a, 1a, 2a, 3a, 4a
    ASSERT_EQ(5, array->getSize());

    ASSERT_EQ(temp, array->peek());
}