#pragma once

#include <vector>

template <typename T>
class BinarySearchTree {
public:
    typedef struct BSTNode {
        T data;
        BSTNode* left;
        BSTNode* right;

        BSTNode():
            data(NULL), left(nullptr), right(nullptr) {}

        BSTNode(T newData):
            data(newData), left(nullptr), right(nullptr) {}
    } Node;

private:
    Node* root;
    int size;

public:
#pragma mark - Constructors
    BinarySearchTree():
        root(nullptr), size(0) {}

    /**
     * Constructs a new BST.
     * 
     * This constructor should initialize the BST with the data in the
     * collection. The data should be added in the same order it is in the
     * collection.
     * 
     * Hint: Not all collections are indexable like Lists, so a regular for loop
     * will not work here. However, all collections are iterable, so what type of loop
     * would work?
     * 
     * @param data the data to add
     * @throws std::invalid_argument if data or any elemenet in data is null
     */
    template <typename C>
    BinarySearchTree(C collection);

#pragma mark - Generic Functions
    /**
     * Adds the data to the tree.
     * 
     * This must be done recursively.
     * 
     * The data becomes a leaf in the tree.
     * 
     * Traverse the tree to find the appropriate location. If the data is
     * already in the tree, then nothing should be done (the duplicate
     * shouldn't get added, and the size should not be incremented).
     * 
     * Must be O(log n) for best and average cases and O(n) for worst case.
     * 
     * @param data the data to add
     * @throws std::invalid_argument if data or any elemenet in data is null
     */
    void add(T data);

    /**
     * Removes and returns the data from the tree matching the given parameter.
     * 
     * This must be done recursively.
     * 
     * There are 3 cases to consider:
     * 1: The node containing the data is a leaf (no children). In this case, 
     * simply remove it.
     * 2: The node containing the data has one child. In this case, simply
     * replace it with its child.
     * 3: The node containing the ata has 2 children. Use the successor to
     * replace the data. You MUST use recursion to find and remove the
     * successor ()
     */
    T remove(T data);

    /**
     * Returns the data from the tree matching the given parameter.
     * 
     * This must be done recursively.
     * 
     * Do not return the same data that was passed in. Return the data that
     * was stored in the tree.
     * 
     * Hint: Should you use value equality or reference equality?
     * 
     * Must be O(log n) for the best and average cases and O(n) for worst case.
     * 
     * @param data the data to search for
     * @return the data in the tree equal to the parameter
     * @throws std::invalid_arugment if the data is null
     * @throws std::out_of_range if the data is not in the tree
     */
    T get(T data);

    /**
     * Returns whether or not data matching the given parameter is contained
     * within the tree.
     * 
     * This must be done recursively.
     * 
     * Hint: Should you use value equality or reference equality?
     * 
     * Must be O(log n) for best and average cases and O(n) for worst case.
     * 
     * @param data the data to search for
     * @return true if the parameter is contained within the tree, false otherwise
     * @throws std::invalid_arugment if data is null
     */
    bool contains(T data);

    /**
     * Returns the height of the root of the tree.
     * 
     * This must be done recursively.
     * 
     * A node's height is defined as max(left.height, right.height) + 1. A
     * leaf node has a height of 0 and a null child has a height or -1.
     * 
     * Must be O(n).
     * 
     * @return the height of the root of the tree, -1 if the tree is empty
     */
    int height();

    /**
     * Clears the tree.
     * 
     * Clears all data and resets the size.
     * 
     * Must be O(1).
     */
    void clear();

#pragma mark - Traversal Functions
    /**
     * Generate a pre-order traversal of the tree.
     * 
     * This must be done recursively.
     * 
     * Must be O(n).
     * 
     * @return the preorder traversal of the tree
     */
    std::vector<T> preOrder();

    /**
     * Generate a in-order traversal of the tree.
     * 
     * This must be done recursively.
     * 
     * Must be O(n).
     * 
     * @return the inorder traversal of the tree
     */
    std::vector<T> inOrder();

    /**
     * Generate a post-order traversal of the tree.
     * 
     * This must be done recursively.
     * 
     * Must be O(n).
     * 
     * @return the postorder traversal of the tree
     */
    std::vector<T> postOrder();

    /**
     * Generate a level-order traversal of the tree.
     * 
     * This does not need to be done recursively.
     * 
     * Hint: You will need to use a queue of nodes. Think about what initial
     * node you should add to the queue and what loop / loop conditions you
     * should use.
     * 
     * Must be O(n).
     * 
     * @return the level order traversal of the tree
     */
    std::vector<T> levelOrder();

#pragma mark - Getter Methods
    /**
     * Returns the root of the tree.
     * 
     * @return the root of the tree
     */
    Node* getRoot() { return this->root; }

    /**
     * Returns the size of the tree.
     * 
     * @return the size of the tree
     */
    int getSize() { return this->size; }

#pragma mark - LeetCode Questions

};