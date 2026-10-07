#pragma once

#include "qeue.h"
#include "Stack.h"
#include <iostream>
template <typename T>
class Tree
{
public:
    Node<T> *root;
    Tree() { root = nullptr; }
    int Insert(T Data);
    T Delete(T Data);
    bool IsDuplicate(T Data);
    Node<T> *Split(Node<T> *p);
    void Display();
    Node<T> *Find(T Data);
    Node<T> *Successor(Node<T> *p, T Data);
    T LeafDelete(T Data);
};

template <typename T>
int Tree<T>::Insert(T Data)
{
    Node<T> *p = root;
    T MinValue = static_cast<T>(INT32_MIN);
    // Creating new tree
    if (p == nullptr)
    {
        p = new Node<T>;
        p->A = Data;
        p->Parent = nullptr;
        p->Child1 = p->Child2 = p->Child3 = p->Child4 = nullptr;
        p->B = p->C = MinValue;
        root = p;
        return 1;
    }
    while (!p->IsLeaf())
    {
        if (IsDuplicate(Data))
            return -1; // We are returning -1 because of duplicate in list
        if (p->IsFull())
            p = Split(p);
        if (p->ValueCount() == 1)
        {
            if (p->A > Data)
                p = p->Child1;
            else
                p = p->Child2;
        }
        else if (p->ValueCount() == 2)
        {
            if (p->A > Data)
            {
                p = p->Child1;
            }
            else if (p->A < Data && p->B > Data)
                p = p->Child2;
            else
                p = p->Child3;
        }
        else
        {
            if (p->A > Data)
            {
                p = p->Child1;
            }
            else if (p->A < Data && p->B > Data)
                p = p->Child2;
            else if (p->B < Data && p->C > Data)
                p = p->Child3;
            else
                p = p->Child4;
        }
    }
    if (p->ValueCount() == 1)
    {
        if (p->A < Data)
            p->B = Data;
        else
        {
            p->B = p->A;
            p->A = Data;
        }
    }
    else if (p->ValueCount() == 2)
    {
        if (p->A > Data)
        {
            p->C = p->B;
            p->B = p->A;
            p->A = Data;
        }
        else if (p->A < Data && p->B > Data)
        {
            p->C = p->B;
            p->B = Data;
        }
        else
            p->C = Data;
    }
    if (p->ValueCount() == 3)
    {
        Node<T> *parent = Split(p);

        if (Data < parent->A)
            p = parent->Child1;
        else if (parent->ValueCount() == 1 || Data < parent->B)
            p = parent->Child2;
        else if (parent->ValueCount() == 2 || Data < parent->C)
            p = parent->Child3;
        else
            p = parent->Child4;
    }
    return 1;
}

template <typename T>
void Tree<T>::Display()
{
    Node<T> *p = root;
    if (!p)
        return;
    Stack<Node<T> *> ST(20);
    T MinValue = static_cast<T>(INT32_MIN);
    ST.Push(p);
    while (!ST.isEmpty())
    {
        p = ST.Pop();
        std::cout << "{";
        if (p->A != MinValue)
            std::cout << "[" << p->A << "]";
        if (p->B != MinValue)
            std::cout << "[" << p->B << "]";
        if (p->C != MinValue)
            std::cout << "[" << p->C << "]";
        std::cout << "}";

        if (p->Child4)
            ST.Push(p->Child4);
        if (p->Child3)
            ST.Push(p->Child3);
        if (p->Child2)
            ST.Push(p->Child2);
        if (p->Child1)
            ST.Push(p->Child1);
    }
}

// This fucntion get data to find and if it is found it returns true
template <typename T>
bool Tree<T>::IsDuplicate(T Data)
{

    Node<T> *p = root;
    if (root == nullptr)
        return false;
    T MinValue = static_cast<T>(INT32_MIN);
    while (!p->IsLeaf())
    {
        if (Data == p->A)
            return true;

        if (Data == p->B && p->B != MinValue)
            return true;
        if (Data == p->C && p->C != MinValue)
            return true;

        if (Data < p->A)
            p = p->Child1;
        else if (p->B == MinValue || Data < p->B)
            p = p->Child2;
        else if (p->C == MinValue || Data < p->C)
            p = p->Child3;
        else
            p = p->Child4;
    }
    if (Data == p->A)
        return true;

    if (Data == p->B && p->B != MinValue)
        return true;
    if (Data == p->C && p->C != MinValue)
        return true;
    return false;
}

// This function splits the nodes when adding. When split fails it return false
template <typename T>
Node<T> *Tree<T>::Split(Node<T> *p)
{
    Node<T> *Parent = nullptr;
    if (p->Parent != nullptr)
        Parent = p->Parent;

    if (Parent && Parent->ValueCount() == 1)
    {
        if (Parent->A < p->B)
        {
            Parent->B = p->B;
            Parent->Child2 = new Node<T>(p->A, p->Child1, p->Child2, Parent);
            Parent->Child3 = new Node<T>(p->C, p->Child3, p->Child4, Parent);
        }
        else
        {
            Parent->B = Parent->A;
            Parent->Child3 = Parent->Child2;
            Parent->A = p->B;
            Parent->Child1 = new Node<T>(p->A, p->Child1, p->Child2, Parent);
            Parent->Child2 = new Node<T>(p->C, p->Child3, p->Child4, Parent);
        }
        delete p;
    }
    else if (Parent && Parent->ValueCount() == 2)
    {
        if (Parent->B < p->B)
        {
            Parent->C = p->B;
            Parent->Child3 = new Node<T>(p->A, p->Child1, p->Child2, Parent);
            Parent->Child4 = new Node<T>(p->C, p->Child3, p->Child4, Parent);
        }
        else if (Parent->A > p->B && Parent->B > p->B)
        {
            Parent->C = Parent->B;
            Parent->Child4 = Parent->Child3;
            Parent->B = p->B;
            Parent->Child1 = new Node<T>(p->A, p->Child1, p->Child2, Parent);
            Parent->Child2 = new Node<T>(p->C, p->Child3, p->Child4, Parent);
        }
        else
        {
            Parent->C = Parent->B;
            Parent->Child4 = Parent->Child3;
            Parent->B = Parent->A;
            Parent->Child3 = Parent->Child2;
            Parent->Child1 = new Node<T>(p->A, p->Child1, p->Child2, Parent);
            Parent->Child2 = new Node<T>(p->C, p->Child3, p->Child4, Parent);
        }
        delete p;
    }
    else
    {
        root = new Node<T>(p->B);
        root->Child1 = new Node<T>(p->A, p->Child1, p->Child2, root);
        root->Child2 = new Node<T>(p->C, p->Child3, p->Child4, root);
        Parent = root;
        delete p;
    }
    return Parent;
}

template <typename T>
T Tree<T>::Delete(T Data)
{
    T MinValue = static_cast<T>(INT32_MIN);
    Node<T> *p = root;
    p = Find(Data);
    if (p == nullptr)
        return MinValue;
    else
    {
        if (p->ValueCount() == 1)
        {
            Node<T> *Parent = p->Parent;
            if (Parent == nullptr)
            {
            }
            Node<T> *NextChild = nullptr;
            if (Parent->Child1 == p)
                NextChild = Parent->Child2;
            else if (Parent->Child2 == p)
                NextChild = Parent->Child1;
            if (Parent->ValueCount() == 1)
            {
                if (NextChild->ValueCount() == 1)
                {
                    if (NextChild == Parent->Child1)

                    {
                        NextChild->B = Parent->A;
                        NextChild->C = p->A;
                    }
                    else if (NextChild == Parent->Child2)
                    {
                        NextChild->C = NextChild->A;
                        NextChild->B = Parent->A;
                        NextChild->A = p->A;
                    }
                    if (p->IsLeaf() && NextChild->IsLeaf())
                    {
                        delete p;
                        Parent->Parent = NextChild;
                        if (NextChild == Parent->Child1)
                            NextChild->C = MinValue;
                        else
                        {
                            NextChild->A = NextChild->B;
                            NextChild->B = NextChild->C;
                            NextChild->C = MinValue;
                        }
                        return Data;
                    }
                    else if (p->IsLeaf() && NextChild->IsLeaf())
                    {
                        Node<T> *Successor = Successor(p, Data);
                        p->A = Successor->A;
                        Parent = Successor->Parent;
                    }

                    else if (Parent == root)
                    {
                        root = Parent;
                    }
                }
            }
        }
        else if (p->ValueCount() == 2)
        {
            if (p->A == Data)
            {
                p->A = p->B;
                p->B = MinValue;
            }
            if (p->B == Data)
                p->B = MinValue;
        }
    }
    return Data;
}

template <typename T>
Node<T> *Tree<T>::Find(T Data)
{
    T MinValue = static_cast<T>(INT32_MIN);
    Node<T> *p = root;
    while (!p->IsLeaf())
    {
        if (p->A == Data || p->B == Data || p->C == Data)
            return p;
        else
        {
            if (p->A > Data)
                p = p->Child1;
            else if (p->B == MinValue || p->B > Data)
                p = p->Child2;
            else if (p->C == MinValue || p->C > Data)
                p = p->Child3;
            else
                p = p->Child4;
        }
    }
    if (p->A == Data || p->B == Data || p->C == Data)
        return p;
    return nullptr;
}

template <typename T>
Node<T> *Tree<T>::Successor(Node<T> *p, T Data)
{
    if (Data == p->A)
        p = p->Child2;
    else if (Data == p->B)
        p = p->Child3;
    else if (Data == p->C)
        p = p->Child4;
    else
        p = nullptr;
    while (!p->IsLeaf())
    {
        p = p->Child1;
    }
    return p;
}

template <typename T>
T Tree<T>::LeafDelete(T Data)
{
    T MinValue = static_cast<T>(INT32_MIN);
    Node<T> *p, *Parent, *NextChild;

    p = Find(Data);
    Parent = p->Parent;
    if (Parent == nullptr)
    {
    }
    else
    {
        if (p == Parent->Child1)
            NextChild = Parent->Child2;
        else if (p == Parent->Child4)
            NextChild = Parent->Child3;
        else if (p == Parent->Child2)
        {
            if (Parent->ValueCount() = 2)
            {
                if (Parent->Child3->ValueCount() > 1)
                    NextChild = Parent->Child3;
                else
                    NextChild = Parent->Child1;
            }
            else
                NextChild = Parent->Child1;
        }
        else if (p == Parent->Child3)
        {
            if (Parent->ValueCount() == 3)
            {
                if (Parent->Child4->ValueCount() > 1)
                    NextChild = Parent->Child4;
                else
                    NextChild = Parent->Child2;
            }
            else
                NextChild = Parent->Child2;
        }
    }
    if (p->ValueCount() > 1)
    {
        if (Data == p->A)
        {
            p->A = p->B;
            p->B = p->C;
            p->C = MinValue;
        }
        else if (Data == p->B)
        {
            p->B = p->C;
            p->C = MinValue;
        }
        else
        {
            p->C = MinValue;
        }
    }
    else if (p->ValueCount() == 1)
    {
        if (Parent->ValueCount() == 1)
        {
            if (NextChild->ValueCount() == 1)
            {
                if (NextChild == Parent->Child1)
                {
                    NextChild->B = Parent->A;
                    NextChild->C = p->A;
                }
                else if (NextChild == Parent->Child2)
                {
                    NextChild->C = NextChild->A;
                    NextChild->B = Parent->A;
                    NextChild->A = p->A;
                }
                if (p->IsLeaf() && NextChild->IsLeaf())
                {
                    delete p;
                    Parent->Parent = NextChild;
                    if (NextChild == Parent->Child1)
                        NextChild->C = MinValue;
                    else
                    {
                        NextChild->A = NextChild->B;
                        NextChild->B = NextChild->C;
                        NextChild->C = MinValue;
                    }
                    return Data;
                }
            }
            else
            {
                if (NextChild == Parent->Child1)
                {
                    if (NextChild->ValueCount() == 2)
                    {
                        p->A = Parent->A;
                        Parent->A = NextChild->B;
                        NextChild->B = MinValue;
                    }
                    else if (NextChild->ValueCount() == 3)
                    {
                        p->A = Parent->A;
                        Parent->A = NextChild->C;
                        NextChild->C = MinValue;
                    }
                }
                else if (NextChild == Parent->Child2)
                {
                    if (NextChild->ValueCount() == 2)
                    {
                        p->A = Parent->A;
                        Parent->A = NextChild->A;
                        NextChild->A = NextChild->B;
                        NextChild->B = MinValue;
                    }
                    else if (NextChild->ValueCount() == 3)
                    {
                        p->A = Parent->A;
                        Parent->A = NextChild->A;
                        NextChild->A = NextChild->B;
                        NextChild->B = NextChild->C;
                        NextChild->C = MinValue;
                    }
                }
            }
        }
        else if (Parent->ValueCount() == 2)
        {
        }
    }
}