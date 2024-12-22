#include <gtest/gtest.h>
#include <chrono>
#include <future>

#include <string>

#include "../src/ArrayStack.hpp"
#include "../src/LinkedStack.hpp"

struct StackStudentTest : public ::testing::Test {
    const int TIMEOUT = 200;
    ArrayStack* array;
    LinkedStack* linked;

    virtual void SetUp() override {
        array = new ArrayStack();
        linked = new LinkedStack();
    }

    virtual void TearDown() override {
        delete array;
        delete linked;
    }
};

TEST_F(StackStudentTest, TestInitialization) {
    ASSERT_EQ(0, array->getSize());
    // assertArrayEquals(new Object[ArrayQueue.INITIAL_CAPACITY], array->getBackingArray());

    ASSERT_EQ(0, linked->getSize());
    ASSERT_EQ(nullptr, linked->getHead());
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

TEST_F(StackStudentTest, TestLinkedPush) {
    linked->push("0a");  // 0a
    linked->push("1a");  // 1a, 0a
    linked->push("2a");  // 2a, 1a 0a
    linked->push("3a");  // 3a, 2a, 1a 0a
    linked->push("4a");  // 4a, 3a, 2a, 1a 0a

    ASSERT_EQ(5, linked->getSize());

    Node* current = linked->getHead();
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("4a", current->data);

    current = current->next;
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("3a", current->data);

    current = current->next;
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("2a", current->data);

    current = current->next;
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("1a", current->data);

    current = current->next;
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("0a", current->data);

    current = current->next;
    ASSERT_EQ(nullptr, current);
}

TEST_F(StackStudentTest, TestLinkedPop) {
    std::string temp = "5a";

    linked->push("0a");  // 0a
    linked->push("1a");  // 1a, 0a
    linked->push("2a");  // 2a, 1a, 0a
    linked->push("3a");  // 3a, 2a, 1a, 0a
    linked->push("4a");  // 4a, 3a, 2a, 1a, 0a
    linked->push(temp);  // 5a, 4a, 3a, 2a, 1a, 0a
    ASSERT_EQ(6, linked->getSize());

    ASSERT_EQ(temp, linked->pop()); // 4a, 3a, 2a, 1a, 0a

    ASSERT_EQ(5, linked->getSize());

    Node* current = linked->getHead();
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("4a", current->data);

    current = current->next;
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("3a", current->data);

    current = current->next;
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("2a", current->data);

    current = current->next;
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("1a", current->data);

    current = current->next;
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("0a", current->data);

    current = current->next;
    ASSERT_EQ(nullptr, current);
}

TEST_F(StackStudentTest, TestLinkedPeek) {
    std::string temp = "4a";

    linked->push("0a");  // 0a
    linked->push("1a");  // 1a, 0a
    linked->push("2a");  // 2a, 1a, 0a
    linked->push("3a");  // 3a, 2a, 1a, 0a
    linked->push(temp);  // 4a, 3a, 2a, 1a, 0a
    ASSERT_EQ(5, linked->getSize());

    ASSERT_EQ(temp, linked->peek());
}