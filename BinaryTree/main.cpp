#include "Tree.h"

int main()
{
    Tree<int> BinaryTree;
    BinaryTree.CreateTree();
    BinaryTree.InOrder(BinaryTree.root);
    return 0;
}