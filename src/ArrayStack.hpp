#pragma once

#include <string>

class ArrayStack {
public:
    const int INITIAL_CAPACITY = 9;

private:
    std::string* backingArray;
    int capacity;
    int size;

public:
    ArrayStack():
        backingArray(new std::string[this->INITIAL_CAPACITY]),
        capacity(this->INITIAL_CAPACITY), size(0) {}

    /**
     * Adds the data to the top of that stack.
     * 
     * If sufficient space is not available in the backing array, resize it to
     * double the current length.
     * 
     * Must be amortized O(1).
     * 
     * @param data the data to add to the top of the stack
     * @throws std::invalid_argument if data is null
     */
    void push(std::string data);

    /**
     * Removes and returns the data from the top of the stack.
     * 
     * Do not shrink the backing array.
     * 
     * Replace any spots that you pop from with ""
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
     * Returns the backing array of the stack
     * 
     * @return the backing array of the stack
     */
    std::string* getBackingArray() { return this->backingArray; }

    /**
     * Returns the capacity of the stack.
     * 
     * @returns the capacity of the stack
     */
    int getCapacity() { return this->capacity; }

    /**
     * Returns the size of the stack.
     * 
     * @returns the size of the stack
     */
    int getSize() { return this->size; }
};