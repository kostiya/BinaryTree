#include "Tree.h"


namespace structure{
    node::node(T& key,
               Node p,
               Node left,
               Node right):key(key),
                                     p(p),
                                     left(left),
                                     right(right){}

    BinaryTree::BinaryTree():generator(),
                                      distribution(0,1){
        root = nullptr;
    }
    BinaryTree::BinaryTree(T& key){
        root = nullptr;
        this->insert(key);
    }

    void BinaryTree::destroyTree(Node node){
        if(node == nullptr)
            return;
        this->destroyTree(node->left);
        this->destroyTree(node->right);
        delete node;
    }
    BinaryTree::~BinaryTree() {
        destroyTree(this->getRoot());
    }

    Node BinaryTree::getRoot() const {
        return this->root;
    }
    Node node::getParent() const{
        return this->p;
    }
    Node node::getLeft() const{
        return this->left;
    }
    Node node::getRight() const{
        return this->right;
    }
    const T& node::getKey() const{
        return this->key;
    }
    Node BinaryTree::insert(T& key){
        if(this->getRoot()== nullptr){
            this->root = new node(key);
            return this->getRoot();
        }
        Node current_node = this->getRoot();
        Node previous_node = nullptr;
        Location side = rightNode;
        while (current_node != nullptr){
            if(key==current_node->key)
                return nullptr;
            else if(key < current_node->key){
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
            previous_node->right = new node(key,previous_node);
            return previous_node->right;
        } else{
            previous_node->left = new node(key,previous_node);
            return previous_node->left;
        }
    }
    bool BinaryTree::remove(T& key){
        Node node = this->find(key);
        if(node == nullptr)
            return false;


    }
    Node BinaryTree::find(T& key){
        Node current_node = this->getRoot();
        while (current_node != nullptr){
            if(key==current_node->key)
                return current_node;
            else if(key < current_node->key){
                current_node = current_node->left;
            } else{
                current_node = current_node->right;
            }
        }
        return nullptr;
    }
    Node node::minimum(){
        Node current_node = this;
        while(current_node->left != nullptr)
            current_node = current_node->left;
        return current_node;
    }
    Node node::maximum(){
        Node current_node = this;
        while(current_node->right != nullptr)
            current_node = current_node->right;
        return current_node;
    }
    Node BinaryTree::minimum(){
        this->getRoot()->minimum();
    }
    Node BinaryTree::maximum(){
        this->getRoot()->maximum();
    }
    Node node::succsessor(){
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
    Node node::predecessor(){
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

    bool node::rotateRight(){

    }
    bool node::rotateKLeft(){

    }
}