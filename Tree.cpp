#include "Tree.h"


namespace structure{
    Node::Node(T& key,
               Node* p,
               Node* left,
               Node* right):key(key),
                                     p(p),
                                     left(left),
                                     right(right){};

    Node::Node(T& key):Node(key, nullptr){isRoot=true;};

    Node::~Node() {
        if(right != nullptr)
            right->~Node();
        if(left != nullptr)
            left->~Node();

        if(p != nullptr){
            if(p->left==this)
                p->left= nullptr;
            else
                p->right= nullptr;
        }
    }
    std::random_device Node::rd;
    std::default_random_engine Node::generator(Node::rd());
    std::uniform_int_distribution<int> Node::distribution(0,1);

    Node* Node::popNode() {
        Node* sibling;
        if(left == nullptr)
            sibling = right;
        else if(right == nullptr)
            sibling = left;
        else
            return nullptr;

        if(!isRoot) {
            if (p != nullptr) {
                if (p->left == this)
                    p->left = sibling;
                else
                    p->right = sibling;
            }

            if (sibling != nullptr)
                sibling->p = p;

            p = nullptr;
            left = nullptr;
            right = nullptr;
            return this;
        } else{
            if(sibling==right){
                T old_key(key);
                key = right->key;
                right->key = old_key;
                left = right->left;
                right->left = nullptr;
                return right->popNode();
            }else{
                T old_key(key);
                key = left->key;
                left->key = old_key;
                right = left->right;
                left->right = nullptr;
                return left->popNode();
            }
        }

    }

    Node * Node::overrideWith(Node *newNode){
        if(newNode == nullptr)
            return nullptr;
        if(isRoot){
            key=newNode->key;
            newNode->p= nullptr;
            newNode->left= nullptr;
            newNode->right= nullptr;
            return newNode;
        }
        newNode->left = left;
        newNode->right = right;
        newNode->p = p;
        if(p != nullptr) {
            if (p->left == this)
                p->left = newNode;
            else
                p->right = newNode;
        }
        if(right != nullptr)
            right->p = newNode;
        if(left != nullptr)
            left->p = newNode;

        p= nullptr;
        left= nullptr;
        right= nullptr;
        return this;
    }

    Node* Node::getRoot(){
        Node* node = this;
        while(node->p != nullptr)
            node = node->p;
        return node;
    }
    Node* Node::getParent() const{
        return this->p;
    }
    Node* Node::getLeft() const{
        return this->left;
    }
    Node* Node::getRight() const{
        return this->right;
    }
    const T& Node::getKey() const{
        return this->key;
    }
    Node* Node::insert(T& key){
        Node* current_node = this->getRoot();
        Node* previous_node = current_node;
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
            previous_node->right = new Node(key,previous_node);
            return previous_node->right;
        } else{
            previous_node->left = new Node(key,previous_node);
            return previous_node->left;
        }
    }
    bool Node::remove() {

        if(left== nullptr || right == nullptr){
            delete popNode();
            return true;
        }

        Node* newNode;

        if(distribution(generator)==0)
            newNode = left->maximum();
        else
            newNode = right->minimum();

        newNode = newNode->popNode();
        delete overrideWith(newNode);
        return true;

    }

    bool Node::remove(T& key){
        Node* node = find(key);
        return node->remove();
    }

    Node* Node::find(T& key){
        Node* current_node = this->getRoot();
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
    Node* Node::minimum(){
        Node* current_node = this;
        while(current_node->left != nullptr)
            current_node = current_node->left;
        return current_node;
    }
    Node* Node::maximum(){
        Node* current_node = this;
        while(current_node->right != nullptr)
            current_node = current_node->right;
        return current_node;
    }

    Node* Node::successor(){
        if(right != nullptr)
            return right->minimum();
        Node* current = this;
        Node* parent = this->p;
        while(parent != nullptr && current== parent->right){
            current = parent;
            parent = parent->p;
        }
        return parent;
    }
    Node* Node::predecessor(){
        if(left != nullptr)
            return left->maximum();
        Node* current = this;
        Node* parent = p;
        while(parent != nullptr && current== parent->left){
            current = parent;
            parent = parent->p;
        }
        return parent;
    }

    void printNode(Node* node, int depth){
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