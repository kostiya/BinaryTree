#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <random>
#include <functional>

using std::cout;
using std::endl;
namespace structure{
    //template <class T>
    enum Location{leftNode, rightNode};

    typedef int T;
    typedef class node *Node;
    class node{
        friend class BinaryTree;
    protected:
        Node p;
        Node left;
        Node right;
        T key;
    public:
        explicit  node(T& key,
                         Node p= nullptr,
                         Node left = nullptr,
                         Node right = nullptr);
        Node getParent() const;
        Node getLeft() const;
        Node getRight() const;
        const T& getKey() const;
        Node minimum();
        Node maximum();
        Node succsessor();
        Node predecessor();
        bool rotateRight();
        bool rotateLeft();
    };

    class BinaryTree{
    protected:
        Node root;
        void destroyTree(Node node);
        void popNode(Node node);
        void overrideNode(Node oldNode, Node newNode);
        std::random_device rd;
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution;
    public:
        explicit BinaryTree();
        explicit BinaryTree(T& key);
        ~BinaryTree();
        Node getRoot() const;
        Node insert(T& key);
        bool remove(T& key);
        Node find(T& key);
        Node minimum();
        Node maximum();
    };

    void printNode(Node node, int depth=0);
}

#endif //BINARYTREE_TREE_H
