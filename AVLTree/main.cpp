#include "Tree.hpp"

int main()
{
    Tree<int> AVL;
    AVL.Insert(10,AVL.root);
    AVL.Insert(5,AVL.root);
    AVL.Insert(1,AVL.root);
    std::cout<<AVL.root->Data;
    return 0;
}