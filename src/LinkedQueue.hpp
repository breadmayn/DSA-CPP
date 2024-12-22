#pragma once

#include "LinkedListNode.hpp"

class LinkedQueue {
private:
    Node* head;
    Node* tail;
    int size;

public:
    LinkedQueue():
        head(nullptr), tail(nullptr), size(0) {}

    /**
     * Adds the data to the back of the queue.
     * 
     * Must be O(1).
     * 
     * @param data the data to add to the back of the queue
     * @throws std::invalid_argument if data is null
     */
    void enqueue(std::string data);

    /**
     * Removes and returns the data from the front of the queue.
     * 
     * Must be O(1).
     * 
     * @return the data formerly located at the front of the queue
     * @throws std::out_of_range if the queue is empty
     */
    std::string dequeue();

    /**
     * Returns the data from hte front of the queue without removing it.
     * 
     * Must be O(1).
     * 
     * @return the data located at the front of the queue
     * @throws std::out_of_range if the queue is empty
     */
    std::string peek();

    /**
     * Returns the head node of the queue.
     * 
     * @return the node at the head of the queue
     */
    Node* getHead() { return this->head; }

    /**
     * Returns the tail node of the queue.
     * 
     * @return the node at the tail of the queue
     */
    Node* getTail() { return this->tail; }

    /**
     * Returns the size of the queue.
     * 
     * @return the size of the queue
     */
    int getSize() { return this->size; }
};