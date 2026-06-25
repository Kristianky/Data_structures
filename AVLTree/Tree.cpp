#include "Tree.hpp"

template <typename T>
Node<T> *Tree<T>::Insert(T Data, Node<T> *t)
{
    if (root == nullptr)
    {
        root = new Node<T>;
        root->Data = Data;
        root->Left = root->Right = nullptr;
        root->Height = 1;
        return;
    }
    Node<T> *p = nullptr;
    t = root;

    if (t->Data < Data)
        t->Left = Insert(Data, t->Left);
    else
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

    if(PL == root)
    {
        root = PL;
    }

    return PL;
}

template<typename T>
Node<T>* Tree<T>::LRRotation(Node<T> *p)
{
}

template<typename T>
Node<T>* Tree<T>::RLRotation(Node<T> *p)
{
}

template<typename T>
Node<T>* Tree<T>::RRRotation(Node<T> *p)
{
}