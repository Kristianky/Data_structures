#ifndef _TREE_H_
#define _TREE_H_

#include "qeue.h"
#include <iostream>
#include "Stack.h"

template <typename T>
class Tree
{
public:
   Node<T> *root;
   Tree() {root = nullptr;}
   ~Tree() {}
   Node<T>* Insert(T Data, Node<T> *t);
   int Height(Node<T> *p);
   int BalanceFacotr(Node<T> *p);
   Node<T>* LLRotation(Node<T> *p);
   Node<T>* LRRotation(Node<T> *p);
   Node<T>* RLRotation(Node<T> *p);
   Node<T>* RRRotation(Node<T> *p);
};
template <typename T>
Node<T> *Tree<T>::Insert(T Data, Node<T> *t)
{
    Node<T> *p = nullptr;
    if (t == nullptr)
    {
        p = new Node<T>;
        p->Data = Data;
        p->Left = p->Right = nullptr;
        p->Height = 1;
        if(root == nullptr)
        {
            root = p;
        }
        return p;
    }

    if (t->Data > Data)
        t->Left = Insert(Data, t->Left);
    else if(t->Data < Data)
        t->Right = Insert(Data, t->Right);

    t->Height = Height(t);

    if (BalanceFacotr(t) == 2 && BalanceFacotr(t->Left) == 1)
    {
        return LLRotation(t);
    }
    else if (BalanceFacotr(t) == 2 && BalanceFacotr(t->Left) == -1)
    {
        return LRRotation(t);
    }
    else if (BalanceFacotr(t) == -2 && BalanceFacotr(t->Left) == 1)
    {
        return RLRotation(t);
    }
    else if (BalanceFacotr(t) == -2 && BalanceFacotr(t->Left) == -1)
    {
        return RRRotation(t);
    }

    return t;

}

template <typename T>
int Tree<T>::Height(Node<T> *p)
{
    int HeightL, HeightR;
    HeightL = p && p->Left ? p->Left->Height : 0;
    HeightR = p && p->Right ? p->Right->Height : 0;
    return HeightL > HeightR ? HeightL + 1 : HeightR + 1;
}

template <typename T>
int Tree<T>::BalanceFacotr(Node<T> *p)
{
    int HeightL, HeightR;
    HeightL = p && p->Left ? p->Left->Height : 0;
    HeightR = p && p->Right ? p->Right->Height : 0;
    return HeightL - HeightR;
}

template<typename T>
Node<T>* Tree<T>::LLRotation(Node<T> *p)
{
    Node<T> *PL = p->Left;
    Node<T> *PLR = PL->Right;

    PL->Right = p;
    p->Left = PLR;
    
    p->Height = Height(p);
    PL->Height = Height(PL);

    if(p == root)
    {
        root = PL;
    }

    return PL;
}

template<typename T>
Node<T>* Tree<T>::LRRotation(Node<T> *p)
{
    return nullptr;
}

template<typename T>
Node<T>* Tree<T>::RLRotation(Node<T> *p)
{
    return nullptr;
}

template<typename T>
Node<T>* Tree<T>::RRRotation(Node<T> *p)
{
    return nullptr;
}
#endif