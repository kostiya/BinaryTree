#include "RedBlackTree.h"


namespace structure{
    template <class T>
    RBNode<T>::RBNode(T& key,
                  RBNode* p,
                  RBNode* left,
                  RBNode* right):key(key),
                               p(p),
                               left(left),
                               right(right){};

    template <class T>
    RBNode<T>::RBNode(T& key):RBNode(key, nullptr){isRoot=true;};

    template <class T>
    RBNode<T>::~RBNode() {
        delete right;
        delete left;

        if(p != nullptr){
            if(p->left==this)
                p->left= nullptr;
            else
                p->right= nullptr;
        }
    }
    template <class T>
    std::random_device RBNode<T>::rd;

    template <class T>
    std::default_random_engine RBNode<T>::generator(Node<T>::rd());

    template <class T>
    std::uniform_int_distribution<int> RBNode<T>::distribution(0,1);

    template <class T>
    RBNode<T>* RBNode<T>::popNode() {
        RBNode* sibling;
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

    template <class T>
    RBNode<T> * RBNode<T>::overrideWith(RBNode *newNode){
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

    template <class T>
    RBNode<T>* RBNode<T>::getRoot(){
        RBNode* node = this;
        while(node->p != nullptr)
            node = node->p;
        return node;
    }
    template <class T>
    RBNode<T>* RBNode<T>::getParent() const{
        return this->p;
    }
    template <class T>
    RBNode<T>* RBNode<T>::getLeft() const{
        return this->left;
    }
    template <class T>
    RBNode<T>* RBNode<T>::getRight() const{
        return this->right;
    }
    template <class T>
    const T& RBNode<T>::getKey() const{
        return this->key;
    }
    template <class T>
    RBNode<T>* RBNode<T>::insert(T& key){
        RBNode* current_node = this->getRoot();
        RBNode* previous_node = current_node;
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
            previous_node->right = new RBNode(key,previous_node);
            return previous_node->right;
        } else{
            previous_node->left = new RBNode(key,previous_node);
            return previous_node->left;
        }
    }
    template <class T>
    bool RBNode<T>::remove() {

        if(left== nullptr || right == nullptr){
            delete popNode();
            return true;
        }

        RBNode* newNode;

        if(distribution(generator)==0)
            newNode = left->maximum();
        else
            newNode = right->minimum();

        newNode = newNode->popNode();
        delete overrideWith(newNode);
        return true;

    }

    template <class T>
    bool RBNode<T>::remove(T& key){
        RBNode* node = find(key);
        return node->remove();
    }

    template <class T>
    RBNode<T>* RBNode<T>::find(T& key){
        RBNode* current_node = this->getRoot();
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
    template <class T>
    RBNode<T>* RBNode<T>::minimum(){
        RBNode* current_node = this;
        while(current_node->left != nullptr)
            current_node = current_node->left;
        return current_node;
    }
    template <class T>
    RBNode<T>* RBNode<T>::maximum(){
        RBNode* current_node = this;
        while(current_node->right != nullptr)
            current_node = current_node->right;
        return current_node;
    }

    template <class T>
    RBNode<T>* RBNode<T>::successor(){
        if(right != nullptr)
            return right->minimum();
        RBNode* current = this;
        RBNode* parent = this->p;
        while(parent != nullptr && current== parent->right){
            current = parent;
            parent = parent->p;
        }
        return parent;
    }
    template <class T>
    RBNode<T>* RBNode<T>::predecessor(){
        if(left != nullptr)
            return left->maximum();
        RBNode* current = this;
        RBNode* parent = p;
        while(parent != nullptr && current== parent->left){
            current = parent;
            parent = parent->p;
        }
        return parent;
    }


    void printNode(RBNode<int>* node, int depth){
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

    template class RBNode<int>;
}