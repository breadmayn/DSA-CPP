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
template <typename T>
void SinglyLinkedList<T>::addAtIndex(int index, T newData)
{
    if (index < 0 || index > this->size)
        throw std::out_of_range("The value of the index parameter is out of bounds.");

    if (index == 0) this->addToFront(newData);
    else if (index == this->size) this->addToBack(newData);
    else
    {
        if (newData == NULL)
            throw std::invalid_argument("The data arg passed in is null.");

        SinglyLinkedListNode* newNode = new SinglyLinkedListNode(newData);
        SinglyLinkedListNode* current = this->head;

        for (int i = 0; i < (index - 1); i++)
        {
            current = current->getNext();
        }

        newNode->setNext(current->getNext());
        current->setNext(newNode);

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
template <typename T>
void SinglyLinkedList<T>::addToFront(T newData)
{
    if (newData == NULL)
        throw std::invalid_argument("The data arg passed in is null.");

    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(newData);

    if (this->isEmpty()) this->tail = newNode;
    else newNode->setNext(this->head);

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
template <typename T>
void SinglyLinkedList<T>::addToBack(T newData)
{
    if (newData == NULL)
        throw std::invalid_argument("The data arg passed in is null.");

    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(newData);

    if (this->isEmpty()) this->head = newNode;
    else this->tail->setNext(newNode);

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
template <typename T>
T SinglyLinkedList<T>::removeAtIndex(int index)
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
            current = current->getNext();
        }

        T toRemove = current->getData();
        SinglyLinkedListNode removedNode = current->getNext();
        current->setNext(current->getNext()->getNext());
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
template <typename T>
T SinglyLinkedList<T>::removeFromFront()
{
    if (this->isEmpty())
        throw std::out_of_range("The list is empty so we cannot remove anything.");

    T toRemove = this->head->getData();

    if (this->size == 1) this->tail = nullptr;

    SinglyLinkedListNode* next = this->head->getNext();
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
template <typename T> 
T SinglyLinkedList<T>::removeFromBack()
{
    if (this->isEmpty())
        throw std::out_of_range("The list is empty so we cannot remove anything.");

    T toRemove = this->tail.getData();

    if (this->size == 1)
    {
        delete this->tail;

        head = nullptr;
        tail = nullptr;
    }
    else
    {
        SinglyLinkedListNode* current = head;

        while (current->getNext()->getNext())
        {
            current = current->getNext();
        }

        delete this->tail;

        this->tail = current;
        this->tail->setNext(nullptr);
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
template <typename T>
T SinglyLinkedList<T>::get(int index)
{
    if (index < 0 || index >= this->size)
        throw std::out_of_range("The index arg passed in is out of bounds.");
    
    SinglyLinkedListNode* current = this->head;

    for (int i = 0; i <= index; i++)
    {
        current = current->getNext();
    }

    return current->getData();
}

/**
 * Returns whether or not the list is empty.
 * 
 * Must be O(1)
 * 
 * @return true if empty, false otherwise
 */
template <typename T>
bool SinglyLinkedList<T>::isEmpty()
{
    return this->size == 0;
}

/**
 * Clears the list.
 * 
 * Clears all data and resets the size.
 * 
 * Must be O(1)
 */
template <typename T>
void SinglyLinkedList<T>::clear()
{
    SinglyLinkedListNode* current = this->head;
    SinglyLinkedListNode* next = nullptr;

    while (current)
    {
        next = current->getNext();

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
template <typename T>
T SinglyLinkedList<T>::removeLastOccurence(T data)
{
    if (data == NULL)
        throw std::invalid_argument("The data arg passed in is null.");

    if (this->isEmpty())
        throw std::out_of_range("The list is empty, so we cannot find the data passed in.");

    SinglyLinkedListNode* current = head;
    SinglyLinkedListNode* toRemove = nullptr;

    while (current->getNext())
    {
        if (current->getNext()->getData() == data) toRemove = current;

        current = current->getNext();
    }

    if (toRemove == nullptr)
    {
        if (this->head->getData() == data) return this->removeFromFront();
        else throw std::out_of_range("The data passed in was not found in the list.");
    }
    else
    {
        T removeData;
        if (size == 1) return this->removeFromBack();
        else
        {
            current = toRemove;
            toRemove = current->getNext();
            current->setNext(current->getNext().getNext());
            this->size--;
            removeData = toRemove->getData();
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
// template <typename T>
// T* SinglyLinkedList<T>::toArray()
// {
//     if (this->isEmpty()) return nullptr;

//     T[this->size] arr;
//     SinglyLinkedListNode* current = this->head;

//     for (int i = 0; i < size; i++)
//     {
//         arr[i] = current->getData();
//         current = current->getNext();
//     }

//     return &arr;
// }

/**
 * Returns the head node of the list
 * 
 * @return the node at the head of the list
 */
template <typename T>
typename SinglyLinkedList<T>::SinglyLinkedListNode* SinglyLinkedList<T>::getHead()
{
    return this->head;
}

/**
 * Returns the tail node of the list
 * 
 * @return the node at the tail of the list
 */
template <typename T>
typename SinglyLinkedList<T>::SinglyLinkedListNode* SinglyLinkedList<T>::getTail()
{
    return this->tail;
}

/**
 * Returns the size of the list
 * 
 * @return the size of the list
 */
template <typename T>
uint64_t SinglyLinkedList<T>::getSize()
{
    return this->size;
}

template struct SinglyLinkedList<std::string>;