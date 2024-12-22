#include <gtest/gtest.h>
#include <chrono>
#include <future>

#include <string>

#include "../src/SinglyLinkedList.hpp"

struct SinglyLinkedListStudentTest : public ::testing::Test {
    SinglyLinkedList* list;
    const int TIMEOUT = 200;

    virtual void SetUp() override {
        list = new SinglyLinkedList();
    }

    virtual void TearDown() override {
        list->clear();

        delete list;
    }

    SinglyLinkedList* getList() { return list; }

};

TEST_F(SinglyLinkedListStudentTest, TestInitialization) {
    SinglyLinkedList* list = getList();

    ASSERT_EQ(0, list->getSize());
    ASSERT_EQ(nullptr, list->getHead());
    ASSERT_EQ(nullptr, list->getTail());
}

TEST_F(SinglyLinkedListStudentTest, TestAddAtIndex) {
    SinglyLinkedList* list = getList();

    list->addAtIndex(0, "2a");   // 2a
    list->addAtIndex(0, "1a");   // 1a, 2a
    list->addAtIndex(2, "4a");   // 1a, 2a, 4a
    list->addAtIndex(2, "3a");   // 1a, 2a, 3a, 4a
    list->addAtIndex(0, "0a");   // 0a, 1a, 2a, 3a, 4a

    ASSERT_EQ(5, list->getSize());

    SinglyLinkedList::SinglyLinkedListNode* current = list->getHead();
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("0a", current->data);

    current = current->next;
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("1a", current->data);

    current = current->next;
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("2a", current->data);

    current = current->next;
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("3a", current->data);

    current = current->next;
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("4a", current->data);
    ASSERT_EQ(list->getTail(), current);

    current = current->next;
    ASSERT_EQ(nullptr, current);
}

TEST_F(SinglyLinkedListStudentTest, TestAddToFront) {
    SinglyLinkedList* list = getList();

    list->addToFront("4a");  // 4a
    list->addToFront("3a");  // 3a, 4a
    list->addToFront("2a");  // 2a, 3a, 4a
    list->addToFront("1a");  // 1a, 2a, 3a, 4a
    list->addToFront("0a");  // 0a, 1a, 2a, 3a, 4a
    
    ASSERT_EQ(5, list->getSize());

    SinglyLinkedList::SinglyLinkedListNode* current = list->getHead();
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("0a", current->data);

    current = current->next;
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("1a", current->data);

    current = current->next;
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("2a", current->data);

    current = current->next;
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("3a", current->data);

    current = current->next;
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("4a", current->data);
    ASSERT_EQ(list->getTail(), current);

    current = current->next;
    ASSERT_EQ(nullptr, current);
}

TEST_F(SinglyLinkedListStudentTest, TestAddToBack) {
    list->addToBack("0a");   // 0a
    list->addToBack("1a");   // 0a, 1a
    list->addToBack("2a");   // 0a, 1a, 2a
    list->addToBack("3a");   // 0a, 1a, 2a, 3a
    list->addToBack("4a");   // 0a, 1a, 2a, 3a, 4a

    ASSERT_EQ(5, list->getSize());

    SinglyLinkedList::SinglyLinkedListNode* current = list->getHead();
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("0a", current->data);

    current = current->next;
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("1a", current->data);

    current = current->next;
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("2a", current->data);

    current = current->next;
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("3a", current->data);

    current = current->next;
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("4a", current->data);
    ASSERT_EQ(list->getTail(), current);

    current = current->next;
    ASSERT_EQ(nullptr, current);
}

TEST_F(SinglyLinkedListStudentTest, TestRemoveAtIndex) {
    std::string temp = "2a";

    list->addAtIndex(0, "0a");   // 0a
    list->addAtIndex(1, "1a");   // 0a, 1a
    list->addAtIndex(2, temp);   // 0a, 1a, 2a
    list->addAtIndex(3, "3a");   // 0a, 1a, 2a, 3a
    list->addAtIndex(4, "4a");   // 0a, 1a, 2a, 3a, 4a
    list->addAtIndex(5, "5a");   // 0a, 1a, 2a, 3a, 4a, 5a
    ASSERT_EQ(6, list->getSize());

    ASSERT_EQ(temp, list->removeAtIndex(2));    // 0a, 1a, 3a, 4a, 5a

    ASSERT_EQ(5, list->getSize());

    SinglyLinkedList::SinglyLinkedListNode* current = list->getHead();
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("0a", current->data);

    current = current->next;
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("1a", current->data);

    current = current->next;
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("3a", current->data);

    current = current->next;
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("4a", current->data);

    current = current->next;
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("5a", current->data);
    ASSERT_EQ(list->getTail(), current);

    current = current->next;
    ASSERT_EQ(nullptr, current);
}

TEST_F(SinglyLinkedListStudentTest, TestRemoveFromFront) {
    std::string temp = "0a";

    list->addAtIndex(0, temp);   // 0a
    list->addAtIndex(1, "1a");   // 0a, 1a
    list->addAtIndex(2, "2a");   // 0a, 1a, 2a
    list->addAtIndex(3, "3a");   // 0a, 1a, 2a, 3a
    list->addAtIndex(4, "4a");   // 0a, 1a, 2a, 3a, 4a
    list->addAtIndex(5, "5a");   // 0a, 1a, 2a, 3a, 4a, 5a
    ASSERT_EQ(6, list->getSize());

    ASSERT_EQ(temp, list->removeFromFront());   // 1a, 2a, 3a, 4a, 5a

    ASSERT_EQ(5, list->getSize());

    SinglyLinkedList::SinglyLinkedListNode* current = list->getHead();
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("1a", current->data);

    current = current->next;
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("2a", current->data);

    current = current->next;
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("3a", current->data);

    current = current->next;
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("4a", current->data);

    current = current->next;
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("5a", current->data);
    ASSERT_EQ(list->getTail(), current);

    current = current->next;
    ASSERT_EQ(nullptr, current);
}

TEST_F(SinglyLinkedListStudentTest, TestRemoveFromBack) {
    std::string temp = "5a";

    list->addAtIndex(0, "0a");   // 0a
    list->addAtIndex(1, "1a");   // 0a, 1a
    list->addAtIndex(2, "2a");   // 0a, 1a, 2a
    list->addAtIndex(3, "3a");   // 0a, 1a, 2a, 3a
    list->addAtIndex(4, "4a");   // 0a, 1a, 2a, 3a, 4a
    list->addAtIndex(5, temp);   // 0a, 1a, 2a, 3a, 4a, 5a
    ASSERT_EQ(6, list->getSize());

    ASSERT_EQ(temp, list->removeFromBack());    // 0a, 1a, 2a, 3a, 4a

    ASSERT_EQ(5, list->getSize());

    SinglyLinkedList::SinglyLinkedListNode* current = list->getHead();
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("0a", current->data);

    current = current->next;
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("1a", current->data);

    current = current->next;
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("2a", current->data);

    current = current->next;
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("3a", current->data);

    current = current->next;
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("4a", current->data);
    ASSERT_EQ(list->getTail(), current);

    current = current->next;
    ASSERT_EQ(nullptr, current);
}

TEST_F(SinglyLinkedListStudentTest, TestGet) {
    list->addAtIndex(0, "0a");   // 0a
    list->addAtIndex(1, "1a");   // 0a, 1a
    list->addAtIndex(2, "2a");   // 0a, 1a, 2a
    list->addAtIndex(3, "3a");   // 0a, 1a, 2a, 3a
    list->addAtIndex(4, "4a");   // 0a, 1a, 2a, 3a, 4a
    ASSERT_EQ(5, list->getSize());

    ASSERT_EQ("0a", list->get(0));
    ASSERT_EQ("1a", list->get(1));
    ASSERT_EQ("2a", list->get(2));
    ASSERT_EQ("3a", list->get(3));
    ASSERT_EQ("4a", list->get(4));
}

TEST_F(SinglyLinkedListStudentTest, TestIsEmpty) {
    ASSERT_TRUE(list->isEmpty());

    list->addAtIndex(0, "0a");   // 0a
    list->addAtIndex(1, "1a");   // 0a, 1a
    list->addAtIndex(2, "2a");   // 0a, 1a, 2a
    list->addAtIndex(3, "3a");   // 0a, 1a, 2a, 3a
    list->addAtIndex(4, "4a");   // 0a, 1a, 2a, 3a, 4a
    ASSERT_EQ(5, list->getSize());

    ASSERT_FALSE(list->isEmpty());
}

TEST_F(SinglyLinkedListStudentTest, TestClear) {
    list->addAtIndex(0, "0a");   // 0a
    list->addAtIndex(1, "1a");   // 0a, 1a
    list->addAtIndex(2, "2a");   // 0a, 1a, 2a
    list->addAtIndex(3, "3a");   // 0a, 1a, 2a, 3a
    list->addAtIndex(4, "4a");   // 0a, 1a, 2a, 3a, 4a
    ASSERT_EQ(5, list->getSize());

    list->clear();

    ASSERT_EQ(0, list->getSize());
    ASSERT_EQ(nullptr, list->getHead());
}

TEST_F(SinglyLinkedListStudentTest, TestLastOccurence) {
    std::string temp = "2a";

    list->addAtIndex(0, "0a");   // 0a
    list->addAtIndex(1, "1a");   // 0a, 1a
    list->addAtIndex(2, "2a");   // 0a, 1a, 2a
    list->addAtIndex(3, temp);   // 0a, 1a, 2a, 2a
    list->addAtIndex(4, "3a");   // 0a, 1a, 2a, 2a, 3a
    list->addAtIndex(5, "4a");   // 0a, 1a, 2a, 2a, 3a, 4a
    ASSERT_EQ(6, list->getSize());

    ASSERT_EQ(temp, list->removeLastOccurence("2a")); // 0a, 1a, 2a, 3a, 4a
    ASSERT_EQ(5, list->getSize());

    SinglyLinkedList::SinglyLinkedListNode* current = list->getHead();
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("0a", current->data);

    current = current->next;
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("1a", current->data);

    current = current->next;
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("2a", current->data);

    current = current->next;
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("3a", current->data);

    current = current->next;
    ASSERT_NE(nullptr, current);
    ASSERT_EQ("4a", current->data);
    ASSERT_EQ(list->getTail(), current);

    current = current->next;
    ASSERT_EQ(nullptr, current);
}

TEST_F(SinglyLinkedListStudentTest, TestToArray) {
    list->addAtIndex(0, "0a");   // 0a
    list->addAtIndex(1, "1a");   // 0a, 1a
    list->addAtIndex(2, "2a");   // 0a, 1a, 2a
    list->addAtIndex(3, "3a");   // 0a, 1a, 2a, 3a
    list->addAtIndex(4, "4a");   // 0a, 1a, 2a, 3a, 4a
    ASSERT_EQ(5, list->getSize());

    std::vector<std::string> expected(5);
    expected[0] = "0a";
    expected[1] = "1a";
    expected[2] = "2a";
    expected[3] = "3a";
    expected[4] = "4a";

    std::vector<std::string> studentArray = list->toArray();

    for (int i = 0; i < expected.size(); i++) EXPECT_EQ(expected[i], studentArray[i]) << "i: " << i;
}
