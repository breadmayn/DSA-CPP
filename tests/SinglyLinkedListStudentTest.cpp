#include <gtest/gtest.h>
#include <chrono>
#include <future>

#include <string>

#include "../src/SinglyLinkedList.hpp"

struct SinglyLinkedListStudentTest : public ::testing::Test {
    SinglyLinkedList<std::string>* list;
    const int TIMEOUT = 200;

    virtual void SetUp() override {
        list = new SinglyLinkedList<std::string>();
    }

    virtual void TearDown() override {
        
    }

    SinglyLinkedList<std::string>* getList() { return list; }

};

TEST_F(SinglyLinkedListStudentTest, TestInitialization) {
    SinglyLinkedList<std::string>* list = getList();

    ASSERT_EQ(0, list->getSize());
    ASSERT_EQ(nullptr, list->getHead());
    ASSERT_EQ(nullptr, list->getTail());
}

TEST_F(SinglyLinkedListStudentTest, TestAddAtIndex) {
    SinglyLinkedList<std::string>* list = getList();

    list->addAtIndex(0, "2a");   // 2a
    list->addAtIndex(0, "1a");   // 1a, 2a
    list->addAtIndex(2, "4a");   // 1a, 2a, 4a
    list->addAtIndex(2, "3a");   // 1a, 2a, 3a, 4a
    list->addAtIndex(0, "0a");   // 0a, 1a, 2a, 3a, 4a

    ASSERT_EQ(5, list->getSize());

    SinglyLinkedList<std::string>::SinglyLinkedListNode* current = list->getHead();
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("0a", current->getData());

    current = current->getNext();
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("1a", current->getData());

    current = current->getNext();
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("2a", current->getData());

    current = current->getNext();
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("3a", current->getData());

    current = current->getNext();
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("4a", current->getData());
    ASSERT_EQ(list->getTail(), current);

    current = current->getNext();
    ASSERT_EQ(nullptr, current);
}

TEST_F(SinglyLinkedListStudentTest, TestAddToFront) {
    SinglyLinkedList<std::string>* list = getList();

    
}