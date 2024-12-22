#include <gtest/gtest.h>
#include <chrono>
#include <future>

#include <string>

#include "../src/ArrayQueue.hpp"

struct QueueStudentTest : public ::testing::Test {
    const int TIMEOUT = 200;
    ArrayQueue* array;

    virtual void SetUp() override {
        array = new ArrayQueue();
    }

    virtual void TearDown() override {
        delete array;
    }
};

TEST_F(QueueStudentTest, TestInitialization) {
    ASSERT_EQ(0, array->getSize());
    // assertArrayEquals(new Object[ArrayQueue.INITIAL_CAPACITY], array->getBackingArray());
    // std::string other[array->INITIAL_CAPACITY];
    // ASSERT_TRUE(std::memcmp(other, array, sizeof(other)) == 0);
}

TEST_F(QueueStudentTest, TestArrayEnqueue) {
    array->enqueue("0a");    // 0a
    array->enqueue("1a");    // 0a, 1a
    array->enqueue("2a");    // 0a, 1a, 2a
    array->enqueue("3a");    // 0a, 1a, 2a, 3a
    array->enqueue("4a");    // 0a, 1a, 2a, 3a, 4a

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

TEST_F(QueueStudentTest, TestArrayPop) {
    std::string temp = "0a";

    array->enqueue(temp);    // 0a
    array->enqueue("1a");    // 0a, 1a
    array->enqueue("2a");    // 0a, 1a, 2a
    array->enqueue("3a");    // 0a, 1a, 2a, 3a
    array->enqueue("4a");    // 0a, 1a, 2a, 3a, 4a
    array->enqueue("5a");    // 0a, 1a, 2a, 3a, 4a, 5a
    ASSERT_EQ(6, array->getSize());

    // assertSame(temp, array->dequeue());  // 1a, 2a, 3a, 4a, 5a
    ASSERT_EQ(temp, array->dequeue());

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

TEST_F(QueueStudentTest, TestArrayPeek) {
    std::string temp = "0a";

    array->enqueue(temp);    // 0a
    array->enqueue("1a");    // 0a, 1a
    array->enqueue("2a");    // 0a, 1a, 2a
    array->enqueue("3a");    // 0a, 1a, 2a, 3a
    array->enqueue("4a");    // 0a, 1a, 2a, 3a, 4a
    ASSERT_EQ(5, array->getSize());

    ASSERT_EQ(temp, array->peek());
}