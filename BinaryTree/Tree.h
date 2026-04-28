#ifndef _TREE_H_
#define _TREE_H_

#include "qeue.h"
#include <iostream>

template <typename T>
class Tree
{
public:
    Node<T> *root;
    Tree() {};
    ~Tree() { delete root; };
    void CreateTree();
    void InOrder(const Node<T> *p);
    void PostOrder(const Node<T> *p);
    void PreOrder(const Node<T> *p);
};

template <typename T>
void Tree<T>::CreateTree()
{
    Node<T> *p, *t;
    T x;
    queue<Node<T>*> Q(100);

    std::cout << "Enter root value: ";
    std::cin >> x;
    root = new Node<T>;
    root->Data = x;
    root->Left = root->Right = nullptr;
    Q.Enqueue(root);

    while (!Q.IsEmpty())
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

template <typename T>
void Tree<T>::InOrder(const Node<T> *p)
{
    while (p)
    {
        InOrder(p->Left);
        std::cout << p->Data << ", ";
        InOrder(p->Right);
    }
}

template <typename T>
void Tree<T>::PostOrder(const Node<T> *p)
{
    while (p)
    {
        InOrder(p->Left);
        InOrder(p->Right);
        std::cout << p->Data << ", ";
    }
}

template <typename T>
void Tree<T>::PreOrder(const Node<T> *p)
{
    while (p)
    {
        std::cout << p->Data << ", ";
        InOrder(p->Left);
        InOrder(p->Right);
    }
}
#endif