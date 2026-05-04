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
    void LevelOrder(Node<T> *p);
    int Height(Node<T> *p);
};

template <typename T>
void Tree<T>::CreateTree()
{
    Node<T> *p, *t;
    T x;
    queue<Node<T> *> Q(100);

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
    if (p)
    {
        InOrder(p->Left);
        std::cout << p->Data << ", ";
        InOrder(p->Right);
    }
}

template <typename T>
void Tree<T>::PostOrder(const Node<T> *p)
{
    if (p)
    {
        InOrder(p->Left);
        InOrder(p->Right);
        std::cout << p->Data << ", ";
    }
}

template <typename T>
void Tree<T>::PreOrder(const Node<T> *p)
{
    if (p)
    {
        std::cout << p->Data << ", ";
        InOrder(p->Left);
        InOrder(p->Right);
    }
}

template <typename T>
void Tree<T>::LevelOrder(Node<T> *p)
{
    queue<Node<T> *> Q(100);
    std::cout<<p->Data<<" , ";
    Q.Enqueue(p); 

    while (!Q.IsEmpty())
    {
        p = Q.Dequeue();
        if (p->Left)
        {
            std::cout << p->Left->Data<<" , ";
            Q.Enqueue(p->Left);
        }
        if (p->Right)
        {
            std::cout << p->Right->Data<<" , ";
            Q.Enqueue(p->Right);
        }
    }
}

template <typename T>
int Tree<T>::Height(Node<T> *p)
{
    int x{}, y{};
    if (p == 0)
    {
        return 0;
    }
    x = Height(p->Left);
    y = Height(p->Right);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}
#endif