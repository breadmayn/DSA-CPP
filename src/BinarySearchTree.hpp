#pragma once

#include <vector>
#include <queue>

template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
class BinarySearchTree {
public:
    typedef struct BSTNode {
        T data;
        BSTNode* left;
        BSTNode* right;

        BSTNode():
            data(0), left(nullptr), right(nullptr) {}

        BSTNode(T newData):
            data(newData), left(nullptr), right(nullptr) {}
    } Node;

private:
    Node* root;
    int size;

    typedef enum TraversalEnum {
        PRE_ORDER,
        IN_ORDER,
        POST_ORDER
    } TraversalType;

#pragma mark - Private Recursive Helper Functions
    /**
     * This is a recursive helper method that calls itself in order to locate where we
     * want to add the current data.
     * 
     * @param current the current node that we are located in our traversal
     * @param data the data that we are trying to add to our BST
     * @return we are returning the node that we are currently on, this is solely for pointer
     * reinforcement
     */
    inline Node* addRecursiveHelper(Node* current, T data)
    {
        // if the current node is nullptr we are at a leaf
        if (!current)
        {
            // add the new node by returning the new node for pointer reinforcement
            size++;
            return new typename BinarySearchTree<T>::Node(data);
        }

        // going left or right
        if (data < current->data) current->left = this->addRecursiveHelper(current->left, data);
        else if (data > current->data) current->right = this->addRecursiveHelper(current->right, data);
        // else // do nothing because we cannot have duplicates so just return

        // return the current node after traversing for pointer reinforcement
        return current;
    }

    /**
     * This is another helper method that will find the successor in the case that the data we
     * want has 2 children.
     * 
     * @param current the current node that we are located at in our traversal
     * @param dummy a dummy node that will store the data of the successor
     * @return the node that we want to set for pointer reinforcement
     */
    inline Node* findSuccessor(Node* current, Node* dummy)
    {
        if (current->left) current->left = this->findSuccessor(current->left, dummy);
        else
        {
            dummy->data = current->data;

            return (current->right) ? current->right : nullptr;
        }

        return current;
    }

    /**
     * This is a recursive helper method that calls itself in order to locate the node
     * that we want to remove.
     * 
     * @param current the current node that we are located in our traversal
     * @param data the data that we are trying to find and remove from the BST
     * @param dummy this is a dummy node that we will use for storing a reference to the removed node
     * @throws std::out_of_range if the data cannot be found in the BST
     * @return we are returning the node that we are currently on, this is solely for pointer
     * reinforcement
     */
    inline Node* removeRecursiveHelper(Node* current, T data, Node* dummy)
    {
        if (!current)
            throw std::out_of_range("The data was not found in the tree.");

        // current is non-null
        if (data < current->data) current->left = this->removeRecursiveHelper(current->left, data, dummy);
        else if (data > current->data) current->right = this->removeRecursiveHelper(current->right, data, dummy);
        else 
        {
            dummy->data = current->data;

            if (current->left && current->right) // both children
            {
                Node dummy2;
                current->right = this->findSuccessor(current->right, &dummy2);
                current->data = dummy2.data;
                return current;
            }
            // only left child
            else if (current->left && !current->right) return current->left;
            // only right child
            else if (!current->left && current->right) return current->right;
            // no children
            else return nullptr;
        }

        return current;
    }

    /**
     * This is the recursive method that will find data if it is stored in the tree.
     * Note that because we are just trying to find something, we will not use pointer
     * reinforcement because we will never modify the tree.
     * 
     * @param current the current node that we are located at in our traversal
     * @param data the data that we are trying to find
     * @throws std::out_of_range if we cannot find data in the tree
     * @return the data that we found
     */
    inline T findRecursiveHelper(Node* current, T data)
    {
        if (!current)
            throw std::out_of_range("Could not find data in the tree.");

        if (data < current->data) return this->findRecursiveHelper(current->left, data);
        else if (data > current->data) return this->findRecursiveHelper(current->right, data);
        else return current->data;
    }

    /**
     * This is the recursive method that will traverse to the bottom of the BST and then
     * start calculating the height of the root.
     * 
     * @param current the current node that we are located during traversal
     * @return the height of the root
     */
    inline int heightRecursiveHelper(Node* current)
    {
        if (!current) return -1;

        int left = this->heightRecursiveHelper(current->left);
        int right = this->heightRecursiveHelper(current->right);

        if (right > left) return right + 1;
        else return left + 1;
    }

    /**
     * This is the recursive method that will traverse to the bottom of the BST and start deleting
     * the nodes allocated on the heap.
     * 
     * @param current the current node that we are located during traversal
     */
    inline void clearRecursiveHelper(Node* current)
    {
        if (!current) return;

        this->clearRecursiveHelper(current->left);
        this->clearRecursiveHelper(current->right);

        delete current;

        current = nullptr;
    }

    /**
     * This is the recursive method that will be used to return a vector of the recursive traversals
     * of BST (pre, post, in).
     * 
     * @param current the current node that we are located during traversal
     */
    inline void traversal(Node* current, std::vector<T>* list, TraversalType type)
    {
        if (!current) return;

        if (type == PRE_ORDER) list->push_back(current->data);
        this->traversal(current->left, list, type);
        if (type == IN_ORDER) list->push_back(current->data);
        this->traversal(current->right, list, type);
        if (type == POST_ORDER) list->push_back(current->data);
    }

public:
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
    inline void add(T data)
    {
        // if (data == NULL)
            // throw std::invalid_argument("The data argument passed in is null.");

        this->root = this->addRecursiveHelper(this->root, data);
    }

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
    inline T remove(T data)
    {
        // if (data == NULL)
            // throw std::invalid_argument("The data argument passed in is null.");

        Node dummy;

        this->root = this->removeRecursiveHelper(this->root, data, &dummy);
        this->size--;
        return dummy.data;
    }

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
    inline T get(T data)
    {
        // if (data == NULL)
            // throw std::invalid_argument("The data argument passed in is null.");

        return this->findRecursiveHelper(this->root, data);
    }

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
    inline bool contains(T data)
    {
        // if (data == NULL)
        //     throw std::invalid_argument("The data argument passed in is null.");

        return this->findRecursiveHelper(this->root, data) == data;
    }

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
    inline int height() { return this->heightRecursiveHelper(this->root); }

    /**
     * Clears the tree.
     * 
     * Clears all data and resets the size.
     * 
     * Must be O(1).
     */
    inline void clear()
    {
        this->clearRecursiveHelper(this->root);

        this->root = nullptr;
        this->size = 0;
    }

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
    inline std::vector<T> preOrder()
    {
        std::vector<T> ret;

        this->traversal(this->root, &ret, PRE_ORDER);
        return ret;
    }

    /**
     * Generate a in-order traversal of the tree.
     * 
     * This must be done recursively.
     * 
     * Must be O(n).
     * 
     * @return the inorder traversal of the tree
     */
    inline std::vector<T> inOrder()
    {
        std::vector<T> ret;

        this->traversal(this->root, &ret, IN_ORDER);
        return ret;
    }

    /**
     * Generate a post-order traversal of the tree.
     * 
     * This must be done recursively.
     * 
     * Must be O(n).
     * 
     * @return the postorder traversal of the tree
     */
    inline std::vector<T> postOrder()
    {
        std::vector<T> ret;

        this->traversal(this->root, &ret, POST_ORDER);
        return ret;
    }

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
    inline std::vector<T> levelOrder()
    {
        std::vector<T> ret;
        if (!this->root) return ret;

        std::queue<Node*> queue;
        queue.push(this->root);

        int levelCount;
        Node* current;
        while (!queue.empty())
        {
            levelCount = queue.size();

            for (int i = 0; i < levelCount; i++)
            {
                current = queue.front();
                queue.pop();

                ret.push_back(current->data);

                if (current->left) queue.push(current->left);
                if (current->right) queue.push(current->right);
            }
        }

        return ret;
    }

#pragma mark - Getter Methods
    /**
     * Returns the root of the tree.
     * 
     * @return the root of the tree
     */
    inline Node* getRoot() { return this->root; }

    /**
     * Returns the size of the tree.
     * 
     * @return the size of the tree
     */
    inline int getSize() { return this->size; }

#pragma mark - Constructors
    /**
     * Default constructor for the BST.
     */
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
     * @param collection the data to add
     * @throws std::invalid_argument if data or any elemenet in data is null
     */
    template <typename C>
    BinarySearchTree(C collection) {
        for (auto const& element : collection) this->add(element);
    }

#pragma mark - LeetCode Questions

};