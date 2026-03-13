#ifndef _TREE_H_
#define _TREE_H_

#include "qeue.h"

template <typename T>
class Tree
{
    Node<T> *root;
    Tree();
    ~Tree();
    void CreateTree();
};

template <typename T>
void Tree<T>::CreateTree()
{
    Node<T> *p, *t;
    T x;
    queue<Node> Q(100);

    std::cout << "Enter root value: ";
    std::cin >> x;
    root = new Node<T>;
    root->Data = x;
    root->Left = root->Right = nullptr;
    Q.Enqueue(root);

    while (!Q.IsEmpty)
    {
        p = Q.Dequeue();
        std::cout << "Enter a value of left cild of " << p->Data << ": ";
        std::cin >> x;
        if (x != -1)
        {
            t = new Node<T>;
            t->Data = x;
            t->Left = t->Right = nullptr;
            p->Left = t;
            Q.Enqueue(t);
        }
        std::cout << "Enter a value of right cild of " << p->Data << ": ";
        std::cin >> x;
        if (x != -1)
        {
            t = new Node<T>;
            t->Data = x;
            t->Left = t->Right = nullptr;
            p->Right = t;
            Q.Enqueue(t);
        }

    }
}
#endif