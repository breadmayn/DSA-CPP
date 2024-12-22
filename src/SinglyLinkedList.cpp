#include "SinglyLinkedList.hpp"
#include <stdexcept>

/**
 * Adds the element to the specified index
 * 
 * Must be O(1) for indices 0 and size and O(n) for all other cases.
 * 
 * @param index the index that we want to add the new element
 * @param newData the data to add to our linked list
 * @throws std::out_of_range if the index is less than 0 or greater than size
 * @throws std::invalid_argument if data is null
 */
void SinglyLinkedList::addAtIndex(int index, std::string newData)
{
    if (index < 0 || index > this->size)
        throw std::out_of_range("The value of the index parameter is out of bounds.");

    if (index == 0) this->addToFront(newData);
    else if (index == this->size) this->addToBack(newData);
    else
    {
        if (newData.size() == 0)
            throw std::invalid_argument("The data arg passed in is null(empty).");

        SinglyLinkedListNode* newNode = new SinglyLinkedListNode(newData);
        SinglyLinkedListNode* current = this->head;

        for (int i = 0; i < (index - 1); i++)
        {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;

        this->size++;
    }
}

/**
 * Adds the element to the front of the list.
 * 
 * Must be O(1)
 * 
 * @param newData the data to add at the front of the list
 * @throws std::invalid_arguement if the data is null
 */
void SinglyLinkedList::addToFront(std::string newData)
{
    if (newData.size() == 0)
        throw std::invalid_argument("The data arg passed in is null(empty).");

    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(newData);

    if (this->isEmpty()) this->tail = newNode;
    else newNode->next = this->head;

    this->head = newNode;
    this->size++;
}

/**
 * Adds the element to the back of the list.
 * 
 * Must be O(1)
 * 
 * @param newData the data to add to the back of the list
 * @throws std::invalid_argument if the data is null
 */
void SinglyLinkedList::addToBack(std::string newData)
{
    if (newData.size() == 0)
        throw std::invalid_argument("The data arg passed in is null.");

    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(newData);

    if (this->isEmpty()) this->head = newNode;
    else this->tail->next = newNode;

    this->tail = newNode;
    this->size++;
}

/**
 * Removes and returns the element at the specified index
 * 
 * Must be O(1) for index 0 and O(n) for all other cases
 * 
 * @param index the index of the element to remove
 * @return the data that was removed
 * @throws std::out_of_range if index < 0 or index >= size
 */
std::string SinglyLinkedList::removeAtIndex(int index)
{
    if (index < 0 || index >= this->size)
        throw std::out_of_range("The value of the index parameter is out of bounds.");

    if (index == 0) return this->removeFromFront();
    else if (index == (size - 1)) return this->removeFromBack();
    else
    {
        if (this->isEmpty())
            throw std::out_of_range("The list is empty so we cannot remove anything.");

        SinglyLinkedListNode* current = this->head;

        for (int i = 0; i < (index - 1); i++)
        {
            current = current->next;
        }

        std::string toRemove = current->next->data;
        SinglyLinkedListNode* removedNode = current->next;
        current->next = current->next->next;
        delete removedNode;

        this->size--;
        return toRemove;
    }
}

/**
 * Removes and returns the first data element in the list
 * 
 * Must be O(1)
 * 
 * @return the data formerly located at the front of the list
 * @throws std::out_of_range if the list is empty
 */
std::string SinglyLinkedList::removeFromFront()
{
    if (this->isEmpty())
        throw std::out_of_range("The list is empty so we cannot remove anything.");

    std::string toRemove = this->head->data;

    if (this->size == 1) this->tail = nullptr;

    SinglyLinkedListNode* next = this->head->next;
    delete this->head;

    this->head = next;

    this->size--;
    return toRemove;
}

/**
 * Removes and returns the last data element in the list.
 * 
 * Must be O(n)
 * 
 * @return the data formerly located at the back of the list
 * @throws std::out_of_range if the list is empty
 */
std::string SinglyLinkedList::removeFromBack()
{
    if (this->isEmpty())
        throw std::out_of_range("The list is empty so we cannot remove anything.");

    std::string toRemove = this->tail->data;

    if (this->size == 1)
    {
        delete this->tail;

        head = nullptr;
        tail = nullptr;
    }
    else
    {
        SinglyLinkedListNode* current = head;

        while (current->next->next)
        {
            current = current->next;
        }

        delete this->tail;

        this->tail = current;
        this->tail->next = nullptr;
    }

    this->size--;
    return toRemove;
}

/**
 * Returns the element at the specified index.
 * 
 * Must be O(1) for indices 0 and <size - 1> and O(n) for all other cases
 * 
 * @param index the index of the element to get
 * @return the data stored at the index in the list
 * @throws std::out_of_range if index < 0 or index >= size
 */
std::string SinglyLinkedList::get(int index)
{
    if (index < 0 || index >= this->size)
        throw std::out_of_range("The index arg passed in is out of bounds.");
    
    SinglyLinkedListNode* current = this->head;

    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }

    return current->data;
}

/**
 * Returns whether or not the list is empty.
 * 
 * Must be O(1)
 * 
 * @return true if empty, false otherwise
 */
bool SinglyLinkedList::isEmpty()
{
    return !this->head && !this->tail && this->size == 0;
}

/**
 * Clears the list.
 * 
 * Clears all data and resets the size.
 * 
 * Must be O(1)
 */
void SinglyLinkedList::clear()
{
    SinglyLinkedListNode* current = this->head;
    SinglyLinkedListNode* next = nullptr;

    while (current)
    {
        next = current->next;

        delete current;

        current = next;
    }

    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

/**
 * Removes and returns the last copy of the given data form the list
 * 
 * Do not return the same data that was passed in. Return the data that was stored in the list
 * 
 * Must be O(n)
 * 
 * @param data the data to be removed from the list
 * @return the data that was removed
 * @throws std::invalid_argument if the data is null
 * @throws std::out_of_range if the data was not found in the list
 */
std::string SinglyLinkedList::removeLastOccurence(std::string data)
{
    if (data.size() == 0)
        throw std::invalid_argument("The data arg passed in is null.");

    if (this->isEmpty())
        throw std::out_of_range("The list is empty, so we cannot find the data passed in.");

    SinglyLinkedListNode* current = head;
    SinglyLinkedListNode* toRemove = nullptr;

    while (current->next)
    {
        if (current->next->data == data) toRemove = current;

        current = current->next;
    }

    if (toRemove == nullptr)
    {
        if (this->head->data == data) return this->removeFromFront();
        else throw std::out_of_range("The data passed in was not found in the list.");
    }
    else
    {
        std::string removeData;
        if (size == 1) return this->removeFromBack();
        else
        {
            current = toRemove;
            toRemove = current->next;
            current->next = current->next->next;
            this->size--;
            removeData = toRemove->data;
            delete toRemove;
            
            return removeData;
        }
    }
}

/**
 * Returns an array representation of the linked list
 * 
 * Must be O(n) for all cases
 * 
 * @return the array of length size holding all the data in the list in the same order
 */
std::vector<std::string> SinglyLinkedList::toArray()
{
    std::vector<std::string> ret(this->size);
    SinglyLinkedList::SinglyLinkedListNode* current = this->head;

    for (int i = 0; i < ret.size(); i++)
    {
        ret[i] = current->data;
        current = current->next;
    }

    return ret;
}