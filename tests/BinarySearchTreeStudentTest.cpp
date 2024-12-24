#include <gtest/gtest.h>
#include <chrono>
#include <future>

#include "../src/BinarySearchTree.hpp"

struct BinarySearchTreeStudentTest : public ::testing::Test {
    const int TIMEOUT = 200;
    BinarySearchTree<int>* tree;

    virtual void SetUp() override {
        tree = new BinarySearchTree<int>();
    }

    virtual void TearDown() override {
        tree->clear();
        delete tree;
    }
};

TEST_F(BinarySearchTreeStudentTest, TestInitialization) {
    ASSERT_EQ(0, tree->getSize());
    ASSERT_EQ(nullptr, tree->getRoot());
}

TEST_F(BinarySearchTreeStudentTest, TestConstructor) {
    /*
              2
             /
            0
             \
              1
    */

    std::vector<int> data;
    data.push_back(2);
    data.push_back(0);
    data.push_back(1);
    tree = new BinarySearchTree<int>(data);

    ASSERT_EQ(3, tree->getSize());
    ASSERT_EQ(2, tree->getRoot()->data);
    ASSERT_EQ(0, tree->getRoot()->left->data);
    ASSERT_EQ(1, tree->getRoot()->left->right->data);
}

TEST_F(BinarySearchTreeStudentTest, TestAdd) {
    /*
              1
             / \
            0   2
    */

    tree->add(1);
    tree->add(0);
    tree->add(2);

    ASSERT_EQ(3, tree->getSize());

    ASSERT_EQ(1, tree->getRoot()->data);
    ASSERT_EQ(0, tree->getRoot()->left->data);
    ASSERT_EQ(2, tree->getRoot()->right->data);
}

TEST_F(BinarySearchTreeStudentTest, TestRemove) {
    int temp = 2;

    /*
              1
             / \
            0   2
                 \
                  3
                   \
                    4

            ->

              1
             / \
            0   3
                 \
                  4
    */

    tree->add(1);
    tree->add(0);
    tree->add(temp);
    tree->add(3);
    tree->add(4);
    ASSERT_EQ(5, tree->getSize());

    ASSERT_EQ(temp, tree->remove(2));

    ASSERT_EQ(4, tree->getSize());

    ASSERT_EQ(1, tree->getRoot()->data);
    ASSERT_EQ(0, tree->getRoot()->left->data);
    ASSERT_EQ(3, tree->getRoot()->right->data);
    ASSERT_EQ(4, tree->getRoot()->right->right->data);

    temp = 1;
    tree = new BinarySearchTree<int>();

    /*
              1
             / \
            0   2
                 \
                  3
                   \
                    4

            ->

              2
             / \
            0   3
                 \
                  4
    */

    tree->add(temp);
    tree->add(0);
    tree->add(2);
    tree->add(3);
    tree->add(4);
    ASSERT_EQ(5, tree->getSize());

    ASSERT_EQ(temp, tree->remove(1));

    ASSERT_EQ(4, tree->getSize());

    ASSERT_EQ(2, tree->getRoot()->data);
    ASSERT_EQ(0, tree->getRoot()->left->data);
    ASSERT_EQ(3, tree->getRoot()->right->data);
    ASSERT_EQ(4, tree->getRoot()->right->right->data);
}

TEST_F(BinarySearchTreeStudentTest, TestGet) {
    int temp200 = 200;
    int temp185 = 185;
    int temp190 = 190;
    int temp195 = 195;
    int temp215 = 215;
    int temp205 = 205;
    int temp210 = 210;

    /*
                200
            /        \
        185         215
            \         /
            190     205
            \       \
            195     210
    */

    tree->add(temp200);
    tree->add(temp185);
    tree->add(temp190);
    tree->add(temp195);
    tree->add(temp215);
    tree->add(temp205);
    tree->add(temp210);
    ASSERT_EQ(7, tree->getSize());

    // We want to make sure the data we retrieve is the one from the tree,
    // not the data that was passed in. The Integers need to be outside of
    // the range [-128, 127] so that they are not cached.
    ASSERT_EQ(temp185, tree->get(185));
    ASSERT_EQ(temp190, tree->get(190));
    ASSERT_EQ(temp195, tree->get(195));
    ASSERT_EQ(temp200, tree->get(200));
    ASSERT_EQ(temp205, tree->get(205));
    ASSERT_EQ(temp210, tree->get(210));
    ASSERT_EQ(temp215, tree->get(215));
}

TEST_F(BinarySearchTreeStudentTest, TestContains) {
    /*
                3
             /     \
            0       6
             \     /
              1   4
               \   \
                2   5
    */

    tree->add(3);
    tree->add(0);
    tree->add(1);
    tree->add(2);
    tree->add(6);
    tree->add(4);
    tree->add(5);
    ASSERT_EQ(7, tree->getSize());

    ASSERT_TRUE(tree->contains(0));
    ASSERT_TRUE(tree->contains(1));
    ASSERT_TRUE(tree->contains(2));
    ASSERT_TRUE(tree->contains(3));
    ASSERT_TRUE(tree->contains(4));
    ASSERT_TRUE(tree->contains(5));
    ASSERT_TRUE(tree->contains(6));
}

TEST_F(BinarySearchTreeStudentTest, TestPreorder) {
    tree->add(3);
    tree->add(0);
    tree->add(1);
    tree->add(2);
    tree->add(8);
    tree->add(4);
    tree->add(6);
    tree->add(5);
    tree->add(7);
    ASSERT_EQ(9, tree->getSize());

    std::vector<int> preorder;
    preorder.push_back(3);
    preorder.push_back(0);
    preorder.push_back(1);
    preorder.push_back(2);
    preorder.push_back(8);
    preorder.push_back(4);
    preorder.push_back(6);
    preorder.push_back(5);
    preorder.push_back(7);


    // Should be [3, 0, 1, 2, 8, 4, 6, 5, 7]
    std::vector<int> studentResult = tree->preOrder();
    for (int i = 0; i < preorder.size(); i++) EXPECT_EQ(preorder[i], studentResult[i]);
}

TEST_F(BinarySearchTreeStudentTest, TestInorder) {
    tree->add(3);
    tree->add(0);
    tree->add(1);
    tree->add(2);
    tree->add(8);
    tree->add(4);
    tree->add(6);
    tree->add(5);
    tree->add(7);
    ASSERT_EQ(9, tree->getSize());

    std::vector<int> inorder;
    inorder.push_back(0);
    inorder.push_back(1);
    inorder.push_back(2);
    inorder.push_back(3);
    inorder.push_back(4);
    inorder.push_back(5);
    inorder.push_back(6);
    inorder.push_back(7);
    inorder.push_back(8);

    // Should be [0, 1, 2, 3, 4, 5, 6, 7, 8]
    std::vector<int> studentResult = tree->inOrder();
    for (int i = 0; i < inorder.size(); i++) EXPECT_EQ(inorder[i], studentResult[i]);
}

TEST_F(BinarySearchTreeStudentTest, TestPostorder) {
    /*
                3
             /     \
            0       8
             \     /
              1   4
               \   \
                2   6
                   / \
                  5   7
    */

    tree->add(3);
    tree->add(0);
    tree->add(1);
    tree->add(2);
    tree->add(8);
    tree->add(4);
    tree->add(6);
    tree->add(5);
    tree->add(7);
    ASSERT_EQ(9, tree->getSize());

    std::vector<int> postorder;
    postorder.push_back(2);
    postorder.push_back(1);
    postorder.push_back(0);
    postorder.push_back(5);
    postorder.push_back(7);
    postorder.push_back(6);
    postorder.push_back(4);
    postorder.push_back(8);
    postorder.push_back(3);

    // Should be [2, 1, 0, 5, 7, 6, 4, 8, 3]
    std::vector<int> studentResult = tree->postOrder();
    for (int i = 0; i < postorder.size(); i++) EXPECT_EQ(postorder[i], studentResult[i]);
}

TEST_F(BinarySearchTreeStudentTest, TestLevelOrder) {
    /*
                3
             /     \
            0       8
             \     /
              1   4
               \   \
                2   6
                   / \
                  5   7
    */

    tree->add(3);
    tree->add(0);
    tree->add(1);
    tree->add(2);
    tree->add(8);
    tree->add(4);
    tree->add(6);
    tree->add(5);
    tree->add(7);
    ASSERT_EQ(9, tree->getSize());

    std::vector<int> levelorder;
    levelorder.push_back(3);
    levelorder.push_back(0);
    levelorder.push_back(8);
    levelorder.push_back(1);
    levelorder.push_back(4);
    levelorder.push_back(2);
    levelorder.push_back(6);
    levelorder.push_back(5);
    levelorder.push_back(7);

    // Should be [3, 0, 8, 1, 4, 2, 6, 5, 7]
    std::vector<int> studentResult = tree->levelOrder();
    for (int i = 0; i < levelorder.size(); i++) EXPECT_EQ(levelorder[i], studentResult[i]);
}

TEST_F(BinarySearchTreeStudentTest, TestHeight) {
    /*
              2
             /
            0
             \
              1
    */

    tree->add(2);
    tree->add(0);
    tree->add(1);
    ASSERT_EQ(3, tree->getSize());

    ASSERT_EQ(2, tree->height());
}

TEST_F(BinarySearchTreeStudentTest, TestClear) {
    /*
              2
             /
            0
             \
              1
    */

    tree->add(2);
    tree->add(0);
    tree->add(1);
    ASSERT_EQ(3, tree->getSize());

    tree->clear();
    ASSERT_EQ(0, tree->getSize());
    ASSERT_EQ(nullptr, tree->getRoot());
}
