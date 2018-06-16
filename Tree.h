#ifndef TREE_H
#define TREE_H

#include <iostream>

using std::cout;
using std::endl;
namespace structure{
    //template <class T>
    typedef int T;
    class Tree{
    public:
        enum Location{right, left};
        typedef class node{
            friend class Tree;
        protected:
            node* p;
            node* left;
            node* right;
            T key;
        public:
            node(T key,node* p= nullptr,node* left= nullptr,
                    node* right= nullptr):key(key){};
        } *Node;
        const Node& insert(T key);
        bool  remove(T key);
        const Node& find(T key) const;
        const Node& minimum(T key) const;
        const Node& maximum(T key) const;
        const Node& succsessor(T key) const;
        const Node& predecessor(T key) const;
        void printTree() const;

    protected:
        Node root;
    private:
        void printNode(Tree::Node node, int depth=0){
            if(node == nullptr)
                return;
            for(int i = 0; i < depth*4;i++)
                cout << " ";
            cout << node->key << endl;
            printNode(node->left , ++depth);
            printNode(node->right, ++depth);
        }
    };
}

#endif //BINARYTREE_TREE_H
