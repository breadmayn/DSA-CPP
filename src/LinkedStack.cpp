#include "LinkedStack.hpp"

/**
 * Adds the data to the top of the stack.
 * 
 * Must be O(1).
 * 
 * @param data the data to add to the top of the stack
 * @throws std::invalid_argument if data is null
 */
void LinkedStack::push(std::string data)
{
    if (data.size() == 0)
        throw std::invalid_argument("The data argument passed in is null (empty)!");

    Node* newNode = new Node(data);

    if (this->size == 0) this->head = newNode;
    else
    {
        newNode->next = this->head;
        this->head = newNode;
    }

    this->size++;
}

/**
 * Removes and returns the data from the top of the stack.
 * 
 * Must be O(1).
 * 
 * @return the data formerly located at the top of the stack
 * @throws std::out_of_range if the stack is empty
 */
std::string LinkedStack::pop()
{
    if (this->size == 0)
        throw std::out_of_range("The stack is empty - nothing to remove.");

    std::string removed = this->head->data;

    if (this->size == 1) this->head = nullptr;
    else this->head = this->head->next;

    size--;
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
std::string LinkedStack::peek()
{
    if (this->size == 0)
        throw std::out_of_range("The stack is empty - nothing to look at.");

    return this->head->data;
}