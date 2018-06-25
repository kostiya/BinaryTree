#include <iostream>
#include <random>
#include <functional>
#include "Tree.h"
using std::cout;
using std::endl;
using structure::node;
using structure::BinaryTree;
using structure::printNode;

int main() {
    int num;
    BinaryTree tree1;
    num = 4;
    tree1.insert(num);
    num = 6;
    tree1.insert(num);
    num = 2;
    tree1.insert(num);
    num = 1;
    tree1.insert(num);
    num = 7;
    tree1.insert(num);
    num = 3;
    tree1.insert(num);
    num = 5;
    tree1.insert(num);
    printNode(tree1.getRoot());
    num = 4;
    tree1.remove(num);
    printNode(tree1.getRoot());
    node * node = tree1.minimum();
    while(node != nullptr){
        cout << node->getKey() << " ";
        node = node->succsessor();
    }
    cout << endl;
    return 0;
}
