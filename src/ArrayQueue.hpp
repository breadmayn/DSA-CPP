#pragma once

#include <string>

class ArrayQueue {
public:
    const int INITIAL_CAPACITY = 9;
private:
    std::string* backingArray;
    int front;
    int capacity;
    int size;

public:
    ArrayQueue():
        backingArray(new std::string[INITIAL_CAPACITY]), front(0),
        capacity(INITIAL_CAPACITY), size(0) {}

    /**
     * Adds the data to the back of the queue.
     * 
     * If sufficient space is not available in the backing array, resize it to
     * double the current length. When resizing, copy elements to the
     * beginning of the new array and reset front to 0.
     * 
     * Must be amortized O(1).
     * 
     * @param data the data to add to the back of the queue
     * @throws std::illegal_argument if the data is null
     */
    void enqueue(std::string data);

    /**
     * Removes and returns the data from the front of the queue.
     * 
     * Do not shrink the backing array.
     * 
     * Replace any spots that you dequeue from with null.
     * 
     * If the queue becomes empty as a result of this call, do not reset
     * front to 0.
     * 
     * Must be O(1). 
     * 
     * @return the data fromerly located at the front of the queue
     * @throws std::out_of_bounds if the queue is empty
     */
    std::string dequeue();

    /**
     * Returns the data from the front of the queue without removing it.
     * 
     * Must be O(1).
     * 
     * @returns the data located at the front of the queue
     * @throws
     */
    std::string peek();

    /**
     * Returns the backing array of the queue.
     * 
     * @return the backing array of the queue
     */
    std::string* getBackingArray() { return this->backingArray; }

    /**
     * Returns the current size of the queue
     * 
     * @returns the size of the ArrayQueue
     */
    int getSize() { return this->size; }

    /**
     * Returns the current capacity of the queue
     * 
     * @returns the current capacity of the queue
     */
    int getCapacity() { return this->capacity; }
};
