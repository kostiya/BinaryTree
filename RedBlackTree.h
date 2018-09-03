#ifndef RBTREE_H
#define RBTREE_H

#include <iostream>
#include <random>
#include <functional>

using std::cout;
using std::endl;
namespace structure{
    enum Location{leftNode, rightNode};

    template <class T>
    class RBNode{
        friend class BinaryTree;
    protected:
        RBNode<T>* p;
        RBNode<T>* left;
        RBNode<T>* right;
        T key;
        bool isRoot=false;

        RBNode<T>* popNode();
        RBNode<T>* overrideWith(RBNode *newNode);
        static std::random_device rd;
        static std::default_random_engine generator;
        static std::uniform_int_distribution<int> distribution;
        explicit  RBNode(T& key,
                       RBNode* p,
                       RBNode* left = nullptr,
                       RBNode* right = nullptr);
    public:
        explicit  RBNode(T& key);
        ~RBNode();
        RBNode<T>* getParent() const;
        RBNode<T>* getLeft() const;
        RBNode<T>* getRight() const;
        const T& getKey() const;
        RBNode<T>* minimum();
        RBNode<T>* maximum();
        RBNode<T>* successor();
        RBNode<T>* predecessor();
        RBNode<T>* getRoot();
        RBNode<T>* insert(T& key);
        bool remove(T& key);
        bool remove();
        RBNode<T>* find(T& key);
    };

    void printNode(RBNode<int>* node, int depth=0);
}

#endif //RBTREE_TREE_H
