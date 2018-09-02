#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <random>
#include <functional>

using std::cout;
using std::endl;
namespace structure{
    enum Location{leftNode, rightNode};

    template <class T>
    class Node{
        friend class BinaryTree;
    protected:
        Node<T>* p;
        Node<T>* left;
        Node<T>* right;
        T key;
        bool isRoot=false;

        Node<T>* popNode();
        Node<T>* overrideWith(Node *newNode);
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
        Node<T>* getParent() const;
        Node<T>* getLeft() const;
        Node<T>* getRight() const;
        const T& getKey() const;
        Node<T>* minimum();
        Node<T>* maximum();
        Node<T>* successor();
        Node<T>* predecessor();
        Node<T>* getRoot();
        Node<T>* insert(T& key);
        bool remove(T& key);
        bool remove();
        Node<T>* find(T& key);
    };

    void printNode(Node<int>* node, int depth=0);
}

#endif //BINARYTREE_TREE_H
