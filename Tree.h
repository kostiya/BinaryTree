#ifndef TREE_H
#define TREE_H

#include <iostream>

using std::cout;
using std::endl;
namespace structure{
    //template <class T>
    class class_node;
    typedef class_node *Node;


    typedef int T;
    class class_node{
    protected:
        Node p;
        Node left;
        Node right;
        T key;
    public:
        enum Location{left, right};
        explicit class_node(T key,Node p= nullptr,Node left= nullptr,
                Node right= nullptr);
        class_node()=delete;
        class_node(class_node node) = default;
        Node getParent() const;
        Node getLeft() const;
        Node getRight() const;
        T getKey() const;
        Node insert(T key);
        bool remove(T key);
        Node find(T key) const;
        Node minimum(T key) const;
        Node maximum(T key) const;
        Node succsessor(T key) const;
        Node predecessor(T key) const;
    };

    void printNode(Node node, int depth=0){
        if(node == nullptr)
            return;
        for(int i = 0; i < depth*4;i++)
            cout << " ";
        cout << node->getKey() << endl;
        printNode(node->getLeft() , ++depth);
        for(int i = 0; i < depth*4+10;i++)
            cout << "-";
        printNode(node->getRight(), ++depth);
    }
}

#endif //BINARYTREE_TREE_H
