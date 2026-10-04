#include "RedBlack.hpp"

int main()
{
    Tree<int> tree;
    tree.Insert(5,tree.root);
    tree.Insert(4,tree.root);
    tree.Insert(6,tree.root);
    tree.Insert(7,tree.root);
    tree.Insert(2,tree.root);
    tree.Insert(3,tree.root);
    tree.PrintPreOrder();
    std::cout<<std::endl;
    std::cout<<tree.Delete(3,tree.root)<<"\n";
    tree.PrintPreOrder();
    tree.Delete(8,tree.root);
    return 1;
}