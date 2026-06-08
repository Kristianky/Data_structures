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
    std::cout<<std::endl;
    BinaryTree.LevelOrderIterative();
    std::cout<<std::endl;
    Tree<int> BTS;
    BTS.AddBTS(10);
    BTS.AddBTS(20);
    BTS.AddBTS(30);
    BTS.InOrder(BTS.root);
    return 0;
}