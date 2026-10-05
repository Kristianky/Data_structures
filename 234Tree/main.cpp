#include "Tree.hpp"

int main ()
{
    Tree<int> tree;
    tree.Insert(10);
    tree.Insert(20);
    tree.Display();
    std::cout<<"\nEnd";
    return 0;
}