#include "Tree.h"


namespace structure{
    node::node(T& key,
               Node p,
               Node left,
               Node right):key(key),
                                     p(p),
                                     left(left),
                                     right(right){}

    BinaryTree::BinaryTree():rd(),
                             generator(rd()),
                             distribution(0,1){
        root = nullptr;
    }
    BinaryTree::BinaryTree(T& key):BinaryTree(){
        this->insert(key);
    }

    void BinaryTree::destroyTree(Node node){
        if(node == nullptr)
            return;
        this->destroyTree(node->left);
        this->destroyTree(node->right);
        delete node;
    }

    void BinaryTree::popNode(Node node) {
        Node sibling;
        if(node->left == nullptr)
            sibling = node->right;
        else if(node->right == nullptr)
            sibling = node->left;
        else
            return;

        if(node->p != nullptr) {
            if (node->p->left == node)
                node->p->left = sibling;
            else
                node->p->right = sibling;
        }

        if(sibling != nullptr)
            sibling->p = node->p;

    }

    void BinaryTree::overrideNode(Node oldNode, Node newNode){
        if(newNode == nullptr || oldNode == nullptr)
            return;
        newNode->left = oldNode->left;
        newNode->right = oldNode->right;
        newNode->p = oldNode->p;
        if(oldNode->p != nullptr) {
            if (oldNode->p->left == oldNode)
                oldNode->p->left = newNode;
            else
                oldNode->p->right = newNode;
        }
        if(oldNode->right != nullptr)
            oldNode->right->p = newNode;
        if(oldNode->left != nullptr)
            oldNode->left->p = newNode;
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
    bool BinaryTree::remove(Node node){
        if(node == nullptr)
            return false;

        if(node->left== nullptr){
            if(node==root)
                root = node->right;
            this->popNode(node);
            delete node;
            return true;
        }

        if(node->right == nullptr){
            if(node==root)
                root = node->left;
            this->popNode(node);
            delete node;
            return true;
        }

        Node newNode;

        if(distribution(generator)==0)
            newNode = node->left->maximum();
        else
            newNode = node->right->minimum();

        popNode(newNode);
        overrideNode(node,newNode);
        if(root==node)
            root = newNode;
        delete node;
        return true;

    }

    bool BinaryTree::remove(T& key){
        Node node = find(key);
        return remove(node);
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
    Node node::successor(){
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

    void printNode(Node node, int depth){
        if(node == nullptr)
            return;
        printNode(node->getLeft() ,depth+1);
        for(int i = 0; i < depth*4;i++)
            cout << " ";
        cout << node->getKey() << endl;
        printNode(node->getRight(),depth+1);
        if(depth==0)
            cout << "--------------------" << endl;
    }
}