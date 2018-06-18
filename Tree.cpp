#include "Tree.h"
#include <random>
#include <iostream>
#include <functional>

namespace structure{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0,1);
    auto sideGenerator = std::bind(distribution,generator);
    class_node::class_node(T key,Node p= nullptr,Node left= nullptr,
            Node right= nullptr):key(key),
                                  p(p),
                                  left(left),
                                  right(right){}
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
    T& class_node::getKey() const{
        return this->key;
    }
    Node class_node::insert(T& key){
        Node current_node = this;
        Node previous_node = nullptr;
        Location side;
        while (current_node != nullptr){
            if(key==this->key)
                return nullptr;
            else if(key < this->key){
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
            return previous_node->right;
        } else{
            previous_node->left = new class_node(key,previous_node);
            return previous_node->left;
        }
    }
    bool class_node::remove(T& key){
        
    }
    Node class_node::find(T& key){
        Node current_node = this;
        while (current_node != nullptr){
            if(key==this->key)
                return current_node;
            else if(key < this->key){
                current_node = current_node->left;
            } else{
                current_node = current_node->right;
            }
        }
        return nullptr;
    }
    Node class_node::minimum(){
        Node current_node = this;
        while(current_node->left != nullptr)
            current_node = current_node->left;
        return current_node;
    }
    Node class_node::maximum(){
        Node current_node = this;
        while(current_node->right != nullptr)
            current_node = current_node->right;
        return current_node;
    }
    Node class_node::succsessor(){
        if(right != nullptr)
            return right->minimum();
        Node current = this;
        Node parent = this->p;
        while(parent != nullptr && current== parent->right){
            current = parent;
            parent = parent->p;
        }
        return parent;
    }
    Node class_node::predecessor(){
        if(left != nullptr)
            return left->maximum();
        Node current = this;
        Node parent = this->p;
        while(parent != nullptr && current== parent->left){
            current = parent;
            parent = parent->p;
        }
        return parent;
    }

    bool class_node::rotateRight(){

    }
    bool class_node::rotateLeft(){

    }
}