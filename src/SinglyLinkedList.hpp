#pragma once

#include <cstdint>

template <typename T>
class SinglyLinkedList {

public:
    class SinglyLinkedListNode {
    private:
        T data;
        SinglyLinkedListNode* next;

    public:
        SinglyLinkedListNode(T data, SinglyLinkedListNode next):
            data(data), next(next) {}

        SinglyLinkedListNode(T data):
            data(data), next(nullptr) {}

        SinglyLinkedListNode():
            data(), next(nullptr) {}

        // Node methods
        T getData() { return this->data; }
        void setData(T newData) { this->data = newData; }

        SinglyLinkedListNode* getNext() { return this->next; }
        void setNext(SinglyLinkedList* newNext) { this->next = newNext; }
    };

private:
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;
    uint64_t size;

public:
    SinglyLinkedList():
        head(nullptr), tail(nullptr), size(0) {}
    
    void addAtIndex(int index, T newData);
    void addToFront(T newData);
    void addToBack(T newData);

    T removeAtIndex(int index);
    T removeFromFront();
    T removeFromBack();

    T get(int index);
    bool isEmpty();
    void clear();

    T removeLastOccurence(T data);
    // T* toArray();

    SinglyLinkedListNode* getHead();
    SinglyLinkedListNode* getTail();
    uint64_t getSize();
};
