#include "Tree.h"

namespace structure{
    void Tree::printTree() const{

    }
    const Tree::Node& Tree::insert(T key){
        Node y = nullptr;
        Node x = this->root;
        while(x != nullptr){
            y = x;
            Location loc;
            if (key < x->key){
                loc = left;
                x = x->left;
            } else{
                loc = right;
                x->right;
            }
        }
        if(y == nullptr){
            this->root=Node(key);
        }
        return nullptr;
    }

    bool  Tree::remove(T key){
        return true;
    }
    const Tree::Node& Tree::find(T key) const{
        return nullptr;
    }
    const Tree::Node& Tree::minimum(T key) const{
        return nullptr;
    }
    const Tree::Node& Tree::maximum(T key) const{
        return nullptr;
    }
    const Tree::Node& Tree::succsessor(T key) const{
        return nullptr;
    }
    const Tree::Node& Tree::predecessor(T key) const{
        return nullptr;
    }
}