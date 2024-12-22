#include "../src/ArrayQueue.hpp"

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
void ArrayQueue::enqueue(std::string data)
{
    if (data.size() == 0)
        throw new std::invalid_argument("The data argument passed in is empty.");

    if (this->size < this->capacity) this->backingArray[(front + size) % this->capacity] = data;
    else
    {
        std::string newArr[this->capacity * 2];
        for (int i = 0; i < this->capacity; i++)
            newArr[i] = this->backingArray[(this->front + this->size) % this->capacity];

        delete[] this->backingArray;
        this->backingArray = newArr;
        this->backingArray[size] = data;
        this->front = 0;
    }

    size++;
}

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
 * @throws std::out_of_range if the queue is empty
 */
std::string ArrayQueue::dequeue()
{
    if (this->size == 0)
        throw new std::out_of_range("The queue is empty so there is nothing to remove/dequeue.");

    std::string removed = this->backingArray[front];
    this->backingArray[front] = "";
    front = (front + 1) & this->capacity;
    size--;
    return removed;
}

/**
 * Returns the data from the front of the queue without removing it.
 * 
 * Must be O(1).
 * 
 * @returns the data located at the front of the queue
 * @throws
 */
std::string ArrayQueue::peek()
{
    if (size == 0)
        throw std::out_of_range("The queue is empty - nothing to return");

    return this->backingArray[front];
}