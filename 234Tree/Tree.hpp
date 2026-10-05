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
    bool IsDuplicate(T Data);
    bool Split(Node<T> *p);
    void Display();
};

template <typename T>
int Tree<T>::Insert(T Data)
{
    Node<T> *p = root;
    T MinValue = static_cast<T>(INT16_MIN);
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
    if (p == root)
    {
        if(p->A == MinValue)
        {
            p->A = Data;
        }
        else if (p->A != MinValue && p->B == MinValue)
        {
            if (p->A < Data)
                p->B = Data;
            else
            {
                p->B = p->A;
                p->A = Data;
            }
        }
        else if (p->A != MinValue && p->B != MinValue && p->C == MinValue)
        {
            if (p->B < Data)
                p->C = Data;
            else if (p->A > Data && p->B < Data)
            {
                p->C = p->B;
                p->B = Data;
            }
            else if(Data < p->A)
            {
                p->C = p->B;
                p->B = p->A;
                p->A = Data;
            }
        }
        else
        {
            Split(p);
        }

    }
    while (!p->IsLeaf())
    {
        Node<T> *OldParent = nullptr;
        Node<T> *Parent = nullptr;
        if (p->Parent)
            OldParent = p->Parent;
        if (IsDuplicate(Data))
            return -1; // We are returning -1 because of duplicate in list
        if (p->IsFull())
            Split(p);
        if (OldParent == nullptr)
            Parent = root;
        else
            Parent = OldParent;
        if (Data < Parent->A)
            p = p->Child1;
        else if (Parent->B != MinValue && Data < Parent->B)
            p = Parent->Child2;
        else if (Parent->C != MinValue && Data < Parent->C)
            p = Parent->Child3;
        else if (Parent->C != MinValue && Data > Parent->C)
            p = Parent->Child4;
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
    T MinValue = static_cast<T>(INT16_MIN);
    ST.Push(p);
    while (!ST.isEmpty())
    {
        p = ST.Pop();
        std::cout << "{";
        if (p->A != MinValue)
            std::cout <<"["<< p->A<<"]";
        if (p->B != MinValue)
            std::cout <<"[" <<p->B<<"]";
        if (p->C != MinValue)
            std::cout <<"[" << p->C<<"]";
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
    T MinValue = static_cast<T>(INT16_MIN);
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
bool Tree<T>::Split(Node<T> *p)
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
        root->Child1 = new Node<T>(p->A, p->Child1, p->Child2, nullptr);
        root->Child2 = new Node<T>(p->C, p->Child3, p->Child4, nullptr);
        delete p;
    }
    return true;
}