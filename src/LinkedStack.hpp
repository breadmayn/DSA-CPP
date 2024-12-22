#pragma once

#include "LinkedListNode.hpp"

class LinkedStack {
private:
    Node* head;
    int size;

public:
    LinkedStack():
        head(nullptr), size(0) {}

    /**
     * Adds the data to the top of the stack.
     * 
     * Must be O(1).
     * 
     * @param data the data to add to the top of the stack
     * @throws 
     */
    void push(std::string data);

    /**
     * Removes and returns the data from the top of the stack.
     * 
     * Must be O(1).
     * 
     * @return the data formerly located at the top of the stack
     * @throws std::out_of_range if the stack is empty
     */
    std::string pop();

    /**
     * Returns the data from the top of the stack without removing it.
     * 
     * Must be O(1).
     * 
     * @return the data from the top of the stack
     * @throws std::out_of_range if the stack is empty
     */
    std::string peek();

    /**
     * Returns the head node of the queue.
     * 
     * @return the node at the head of the queue
     */
    Node* getHead() { return this->head; }

    /**
     * Returns the size of the queue.
     * 
     * @return the size of the queue
     */
    int getSize() { return this->size; }
};