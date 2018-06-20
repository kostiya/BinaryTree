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
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution;
    public:
        enum Location{leftNode, rightNode};
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

    void printNode(Node node, int depth=0){
        if(node == nullptr)
            return;
        printNode(node->getLeft() , ++depth);
        for(int i = 0; i < depth*4;i++)
            cout << " ";
        cout << node->getKey() << endl;
        printNode(node->getRight(), ++depth);
    }
}

#endif //BINARYTREE_TREE_H
