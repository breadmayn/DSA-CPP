#pragma once

#include <string>
#include <vector>

class SinglyLinkedList {
public:
    typedef struct SinglyLinkedListNode {
        std::string data;
        SinglyLinkedListNode* next;

        // constructors
        SinglyLinkedListNode(std::string data, SinglyLinkedListNode* next): 
            data(data), next(next) {}

        SinglyLinkedListNode(std::string data):
            data(data), next(nullptr) {}

        SinglyLinkedListNode():
            data(""), next(nullptr) {}
    } Node;

private:
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;
    int size;

public:
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
    void addAtIndex(int index, std::string newData);

    /**
     * Adds the element to the front of the list.
     * 
     * Must be O(1)
     * 
     * @param newData the data to add at the front of the list
     * @throws std::invalid_arguement if the data is null
     */
    void addToFront(std::string newData);

    /**
     * Adds the element to the back of the list.
     * 
     * Must be O(1)
     * 
     * @param newData the data to add to the back of the list
     * @throws std::invalid_argument if the data is null
     */
    void addToBack(std::string newData);

    /**
     * Removes and returns the element at the specified index
     * 
     * Must be O(1) for index 0 and O(n) for all other cases
     * 
     * @param index the index of the element to remove
     * @return the data that was removed
     * @throws std::out_of_range if index < 0 or index >= size
     */
    std::string removeAtIndex(int index);

    /**
     * Removes and returns the first data element in the list
     * 
     * Must be O(1)
     * 
     * @return the data formerly located at the front of the list
     * @throws std::out_of_range if the list is empty
     */
    std::string removeFromFront();

    /**
     * Removes and returns the last data element in the list.
     * 
     * Must be O(n)
     * 
     * @return the data formerly located at the back of the list
     * @throws std::out_of_range if the list is empty
     */
    std::string removeFromBack();

    /**
     * Returns the element at the specified index.
     * 
     * Must be O(1) for indices 0 and <size - 1> and O(n) for all other cases
     * 
     * @param index the index of the element to get
     * @return the data stored at the index in the list
     * @throws std::out_of_range if index < 0 or index >= size
     */
    std::string get(int index);

    /**
     * Returns whether or not the list is empty.
     * 
     * Must be O(1)
     * 
     * @return true if empty, false otherwise
     */
    bool isEmpty();

    /**
     * Clears the list.
     * 
     * Clears all data and resets the size.
     * 
     * Must be O(1)
     */
    void clear();

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
    std::string removeLastOccurance(std::string data);

    /**
     * Returns an array representation of the linked list
     * 
     * Must be O(n) for all cases
     * 
     * @return the array of length size holding all the data in the list in the same order
     */
    std::vector<std::string> toArray();

    /**
     * Returns the head node of the list
     * 
     * @return the node at the head of the list
     */
    SinglyLinkedListNode* getHead() { return this->head; }

    /**
     * Returns the tail node of the list
     * 
     * @return the node at the tail of the list
     */
    SinglyLinkedListNode* getTail() { return this->tail; }

    /**
     * Returns the size of the list
     * 
     * @return the size of the list
     */
    int getSize() { return this->size; }
};