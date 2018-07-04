#include "RedBlackTree.h"
namespace structure{
    explicit  RBnode::RBnode(T& key,
                             RBColor color,
                             RBnode* p,
                             RBnode* left = nullptr,
                             RBnode* right = nullptr):
                                     color(color),
                                     Node(key,p,left,right)
                                     {};
    explicit  RBnode::RBnode(T& key,
                             RBColor color):RBnode(key,color, nullptr){};
    RBColor RBnode::getColor() const { return color; };

    bool RBnode::rightRotate(){
        if(this->p == nullptr)
            return false;

        RBnode* other = dynamic_cast<RBnode*>(this->p);
        other->right = this->left;
        if(this->left != nullptr)
            this->left->p = other;


    }
    bool leftRotate();

}