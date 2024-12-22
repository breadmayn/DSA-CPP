#pragma once

#include <string>

typedef struct LinkedListNode {
    std::string data;
    LinkedListNode* next;

    LinkedListNode():
        data(""), next(nullptr) {}

    LinkedListNode(std::string newData):
        data(newData), next(nullptr) {}

    LinkedListNode(std::string newData, LinkedListNode* newNext):
        data(newData), next(newNext) {}
} Node;