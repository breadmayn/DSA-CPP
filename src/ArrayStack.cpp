#include "ArrayStack.hpp"

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
void ArrayStack::push(std::string data)
{
    if (data.size() == 0)
        throw std::invalid_argument("The data argument passed in is null(empty).");

    if (this->size < this->capacity) this->backingArray[this->size] = data;
    else
    {
        std::string* newArr = new std::string[this->capacity * 2];
        for (int i = 0; i < this->capacity; i++) newArr[i] = this->backingArray[i];

        delete[] this->backingArray;
        this->backingArray = newArr;
        backingArray[size] = data;
    }

    this->size++;
}

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
std::string ArrayStack::pop()
{
    if (this->size == 0)
        throw std::out_of_range("The stack is empty - nothing to remove.");

    std::string removed = this->backingArray[this->size - 1];
    this->backingArray[this->size - 1] = "";
    this->size--;

    return removed;
}

/**
 * Returns the data from the top of the stack without removing it.
 * 
 * Must be O(1). 
 * 
 * @return the data from the top of the stack
 * @throws std::out_of_range if the stack is empty
 */
std::string ArrayStack::peek()
{
    if (this->size == 0)
        throw std::out_of_range("The stack is empty - nothing to remove.");

    return this->backingArray[this->size - 1];
}