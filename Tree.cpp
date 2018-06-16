#include "Tree.h"

namespace structure{
    class_node::class_node(T key,Node p= nullptr,Node left= nullptr,
            Node right= nullptr):key(key),p(p),left(left),right(right){}
    class_node::~class_node() {

    }
    Node class_node::getParent() const{
        return this->p;
    }
    Node class_node::getLeft() const{
        return this->left;
    }
    Node class_node::getRight() const{
        return this->right;
    }
    T class_node::getKey() const{
        return this->key;
    }
    Node class_node::insert(T key){
        Node current_node = this;
        Node previous_node = nullptr;
        Location side;
        while (current_node != nullptr){
            if(key < this->key){
                previous_node = current_node;
                current_node = current_node->left;
                side = leftNode;
            } else{
                previous_node = current_node;
                current_node = current_node->right;
                side = rightNode;
            }
        }
        if(side == rightNode){
            previous_node->right = new class_node(key,previous_node);
        } else{
            previous_node->left = new class_node(key,previous_node);
        }
    }
    bool class_node::remove(T key){

    }
    Node class_node::find(T key) const{

    }
    Node class_node::minimum(T key) const{

    }
    Node class_node::maximum(T key) const{

    }
    Node class_node::succsessor(T key) const{

    }
    Node class_node::predecessor(T key) const{

    }
}