#include "LinkedQueue.hpp"

/**
 * Adds the data to the back of the queue.
 * 
 * Must be O(1).
 * 
 * @param data the data to add to the back of the queue
 * @throws std::invalid_argument if data is null
 */
void LinkedQueue::enqueue(std::string data)
{
    if (data.size() == 0)
        throw new std::invalid_argument("The data argument passed in is null (empty).");
    
    Node* newNode = new LinkedListNode(data);

    if (this->size == 0) this->head = newNode;
    else this->tail->next = newNode;

    this->tail = newNode;
    this->size++;
}

/**
 * Removes and returns the data from the front of the queue.
 * 
 * Must be O(1).
 * 
 * @return the data formerly located at the front of the queue
 * @throws std::out_of_range if the queue is empty
 */
std::string LinkedQueue::dequeue()
{
    if (this->size == 0)
        throw std::out_of_range("The queue is empty - nothing to remove.");

    std::string removed = this->head->data;
    if (this->size == 1)
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    else this->head = this->head->next;

    this->size--;
    return removed;
}

/**
 * Returns the data from hte front of the queue without removing it.
 * 
 * Must be O(1).
 * 
 * @return the data located at the front of the queue
 * @throws std::out_of_range if the queue is empty
 */
std::string LinkedQueue::peek()
{
    if (this->size == 0)
        throw std::out_of_range("The queue is empty - nothing to see.");

    return this->head->data;
}