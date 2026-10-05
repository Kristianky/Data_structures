#include "Tree.hpp"

int main()
{
    Tree<int> AVL;
    AVL.Insert(1,AVL.root);
    AVL.Insert(5,AVL.root);
    AVL.Insert(3,AVL.root);
    std::cout<<AVL.root->Data;
    std::cout<<AVL.root->Child4->Data;
    std::cout<<AVL.root->Child1->Data;
    return 0;
}