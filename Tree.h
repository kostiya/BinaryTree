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
    class Node{
        friend class BinaryTree;
    protected:
        Node* p;
        Node* left;
        Node* right;
        T key;
        bool isRoot=false;

        Node* popNode();
        Node * overrideWith(Node *newNode);
        static std::random_device rd;
        static std::default_random_engine generator;
        static std::uniform_int_distribution<int> distribution;
        explicit  Node(T& key,
                       Node* p,
                       Node* left = nullptr,
                       Node* right = nullptr);
    public:
        explicit  Node(T& key);
        ~Node();
        Node* getParent() const;
        Node* getLeft() const;
        Node* getRight() const;
        const T& getKey() const;
        Node* minimum();
        Node* maximum();
        Node* successor();
        Node* predecessor();
        Node* getRoot();
        Node* insert(T& key);
        bool remove(T& key);
        bool remove();
        Node* find(T& key);
    };

    void printNode(Node* node, int depth=0);
}

#endif //BINARYTREE_TREE_H
