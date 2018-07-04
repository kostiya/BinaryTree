#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H
#include "Tree.h"
#include <iostream>
#include <random>
#include <functional>

using std::cout;
using std::endl;
namespace structure{
    enum RBColor {Black, Red};

    class RBnode : public Node{
    protected:
        RBColor color;
        explicit  RBnode(T& key,
                         RBColor color,
                         RBnode* p,
                         RBnode* left = nullptr,
                         RBnode* right = nullptr);
        bool rightRotate();
        bool leftRotate();
    public:
        explicit  RBnode(T& key,
                         RBColor color);
        RBColor getColor() const;

    };

}

#endif //REDBLACKTREE_H
