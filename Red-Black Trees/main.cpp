#include "RedBlack.hpp"

int main()
{
    Tree<int> tree;
    tree.Insert(1,tree.root);
    tree.Insert(2,tree.root);
    tree.Insert(4,tree.root);
    tree.Insert(5,tree.root);
    tree.Insert(6,tree.root);
    tree.Insert(7,tree.root);
    std::cout<<tree.Delete(7,tree.root);
    tree.Delete(8,tree.root);
    std::cout<<tree.root->Right->Data;
    return 1;
}