#include "Tree.hpp"

int main ()
{
    Tree<int> tree;
    tree.Insert(10);
    tree.Insert(20);
    tree.Insert(40);
    tree.Insert(30);
    tree.Insert(50);
    tree.Insert(70);
    tree.Insert(100);
    tree.Insert(55);
    tree.Insert(45);
    tree.Insert(75);
    tree.Insert(32);
    tree.Display();
    std::cout<<"\n";
    tree.Delete(55);
    tree.Delete(40);
    tree.Display();
    std::cout<<"\nEnd";
    return 0;
}