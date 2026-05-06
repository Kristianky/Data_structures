#include "Tree.h"

int main()
{
    Tree<int> BinaryTree;
    BinaryTree.CreateTree();
    BinaryTree.InOrder(BinaryTree.root);
    std::cout<<std::endl;
    BinaryTree.LevelOrder(BinaryTree.root);
    std::cout<<std::endl;
    std::cout<<BinaryTree.Height(BinaryTree.root);
    std::cout<<std::endl;
    BinaryTree.PreOrderItterative();
    std::cout<<std::endl;
    BinaryTree.InOrderItterative();
    return 0;
}