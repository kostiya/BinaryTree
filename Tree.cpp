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

    void BinaryTree::popNode(Node node, Location side) {

        Node sibling;
        if(side == leftNode)
            sibling = node->left;
        else
            sibling = node->right;

        sibling->p = node->p;
        if(node->p->left == node)
            node->p->left = sibling;
        else
            node->p->right = sibling;

    }

    void BinaryTree::overideNode(Node oldNode, Node newNode){
        newNode->left = oldNode->left;
        newNode->right = oldNode->right;
        newNode->p = oldNode->p;
        if(oldNode->p->left == oldNode)
            oldNode->p->left = newNode;
        else
            oldNode->p->right = newNode;
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
        Node previous_node = current_node;
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

        if(node->left== nullptr){
            this->popNode(node,rightNode);
            delete node;
            return true;
        }
        if(node->right== nullptr){
            this->popNode(node,leftNode);
            delete node;
            return true;
        }

        Node newNode;
        Location side;

        if(distribution(generator)==0){
            newNode = node->left->maximum();
            side = leftNode;
        }
        else{
            newNode = node->right->minimum();
            side = rightNode;
        }

        if(newNode == node->left){
            this->popNode(node,leftNode);
            newNode->right = node->right;
            delete node;
            return true;
        }

        if(newNode == node->right){
            this->popNode(node,rightNode);
            newNode->left = node->left;
            delete node;
            return true;
        }

        if(side==rightNode)
            popNode(newNode,rightNode);
        else
            popNode(newNode,leftNode);

        overideNode(node,newNode);
        delete node;

        return true;

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
    bool node::rotateLeft(){

    }

    void printNode(Node node, int depth){
        if(node == nullptr)
            return;
        printNode(node->getLeft() , ++depth);
        for(int i = 0; i < depth*4;i++)
            cout << " ";
        cout << node->getKey() << endl;
        printNode(node->getRight(), ++depth);
    }
}