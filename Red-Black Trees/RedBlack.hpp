#pragma once

#include "qeue.h"
#include "Stack.h"
#include <cstdint>
enum
{
    Red,
    Black
};

template <typename T>
class Tree
{
public:
    Node<T> *root;

    Tree() : root(nullptr) {}

    // Returns 1 when inserted and -1 when Data is already present.
    int Insert(T Data, Node<T> *t);
    T Delete(T Data, Node<T> *t);

    Node<T> *LLRotation(Node<T> *p);
    Node<T> *LRRotation(Node<T> *p);
    Node<T> *RLRotation(Node<T> *p);
    Node<T> *RRRotation(Node<T> *p);
    Node<T> *InSuccessor(Node<T> *p);
    Node<T> *InPedeccessor(Node<T> *p);

    void FixUp(Node<T> *p);
    void ReColor(Node<T> *GrandParent, Node<T> *Parent, Node<T> *Uncle);
    void PrintPreOrder();

private:
    void RotateLeft(Node<T> *p);
    void RotateRight(Node<T> *p);
};

template <typename T>
void Tree<T>::FixUp(Node<T> *p)
{
    while (p != root && p->Parent->RedBlack == Red)
    {
        Node<T> *parentNode = p->Parent;
        Node<T> *grandParent = parentNode->Parent;

        // Defensive guard
        if (grandParent == nullptr)
        {
            parentNode->RedBlack = Black;
            break;
        }

        if (parentNode == grandParent->Child1)
        {
            Node<T> *uncle = grandParent->Child4;

            if (uncle != nullptr && uncle->RedBlack == Red)
            {
                ReColor(grandParent, parentNode, uncle);
                p = grandParent;
            }
            else
            {
                if (p == parentNode->Child4)
                {
                    p = parentNode;
                    RotateLeft(p);
                    parentNode = p->Parent;
                    grandParent = parentNode->Parent;
                }

                parentNode->RedBlack = Black;
                grandParent->RedBlack = Red;
                RotateRight(grandParent);
            }
        }
        else
        {
            Node<T> *uncle = grandParent->Child1;

            if (uncle != nullptr && uncle->RedBlack == Red)
            {
                ReColor(grandParent, parentNode, uncle);
                p = grandParent;
            }
            else
            {
                if (p == parentNode->Child1)
                {
                    p = parentNode;
                    RotateRight(p);
                    parentNode = p->Parent;
                    grandParent = parentNode->Parent;
                }

                parentNode->RedBlack = Black;
                grandParent->RedBlack = Red;
                RotateLeft(grandParent);
            }
        }
    }
}

template <typename T>
int Tree<T>::Insert(T Data, Node<T> * /*t*/)
{
    Node<T> *parent = nullptr;
    Node<T> *current = root;

    // Find the insertion point.
    while (current != nullptr)
    {
        parent = current;
        if (Data < current->Data)
            current = current->Child1;
        else if (Data > current->Data)
            current = current->Child4;
        else
            return -1; // duplicate
    }

    Node<T> *inserted = new Node<T>;
    inserted->Data = Data;
    inserted->Child1 = nullptr;
    inserted->Child4 = nullptr;
    inserted->Parent = parent;
    inserted->RedBlack = Red;
    inserted->Height = 1;

    if (parent == nullptr)
    {
        root = inserted;
        root->RedBlack = Black;
        return 1;
    }

    if (Data < parent->Data)
        parent->Child1 = inserted;
    else
        parent->Child4 = inserted;
    FixUp(inserted);
    root->RedBlack = Black;
    root->Parent = nullptr;
    return 1;
}

template <typename T>
void Tree<T>::RotateLeft(Node<T> *p)
{
    Node<T> *right = p->Child4;
    Node<T> *middle = right->Child1;
    Node<T> *oldParent = p->Parent;

    right->Parent = oldParent;
    if (oldParent == nullptr)
        root = right;
    else if (oldParent->Child1 == p)
        oldParent->Child1 = right;
    else
        oldParent->Child4 = right;

    right->Child1 = p;
    p->Parent = right;
    p->Child4 = middle;
    if (middle != nullptr)
        middle->Parent = p;
}

template <typename T>
void Tree<T>::RotateRight(Node<T> *p)
{
    Node<T> *left = p->Child1;
    Node<T> *middle = left->Child4;
    Node<T> *oldParent = p->Parent;

    left->Parent = oldParent;
    if (oldParent == nullptr)
        root = left;
    else if (oldParent->Child1 == p)
        oldParent->Child1 = left;
    else
        oldParent->Child4 = left;

    left->Child4 = p;
    p->Parent = left;
    p->Child1 = middle;
    if (middle != nullptr)
        middle->Parent = p;
}

// The four familiar cases are wrappers around the two primitive rotations.
template <typename T>
Node<T> *Tree<T>::LLRotation(Node<T> *p)
{
    RotateRight(p);
    return p->Parent;
}

template <typename T>
Node<T> *Tree<T>::RRRotation(Node<T> *p)
{
    RotateLeft(p);
    return p->Parent;
}

template <typename T>
Node<T> *Tree<T>::LRRotation(Node<T> *p)
{
    RotateLeft(p->Child1);
    RotateRight(p);
    return p->Parent;
}

template <typename T>
Node<T> *Tree<T>::RLRotation(Node<T> *p)
{
    RotateRight(p->Child4);
    RotateLeft(p);
    return p->Parent;
}

template <typename T>
void Tree<T>::ReColor(Node<T> *GrandParent, Node<T> *Parent, Node<T> *Uncle)
{
    Parent->RedBlack = Black;
    if (Uncle != nullptr)
        Uncle->RedBlack = Black;
    GrandParent->RedBlack = Red;
}

template <typename T>
Node<T> *Tree<T>::InSuccessor(Node<T> *p)
{
    if (p == nullptr)
    {
        return nullptr;
    }
    Node<T> *ReturnValue = nullptr;
    p = p->Child4;
    while (p != nullptr)
    {
        ReturnValue = p;
        p = p->Child1;
    }
    return ReturnValue;
}

template <typename T>
Node<T> *Tree<T>::InPedeccessor(Node<T> *p)
{
    if (p == nullptr)
    {
        return nullptr;
    }
    Node<T> *ReturnValue = nullptr;
    p = p->Child1;
    while (p != nullptr)
    {
        ReturnValue = p;
        p = p->Child4;
    }
    return ReturnValue;
}

template <typename T>
T Tree<T>::Delete(T Data, Node<T> *p)
{
    if (p == nullptr)
    {
        return 0;
    }
    T ReturnValue;
    uint16_t LastColor;
    while (p != nullptr && p->Data != Data)
    {
        if (p->Data > Data)
        {
            p = p->Child1;
        }
        else
        {
            p = p->Child4;
        }
    }
    if (p == nullptr)
    {
        return 0;
    }
    Node<T> *ToDelete = p, *ToDeleteParent = nullptr, *ToDeleteChild = nullptr;
    ReturnValue = p->Data;
    if (ToDelete->Child1 && ToDelete->Child4)
    {
        ToDelete = InSuccessor(ToDelete);
        p->Data = ToDelete->Data;
    }
    if (ToDelete->Child1)
        ToDeleteChild = ToDelete->Child1;
    else if (ToDelete->Child4)
        ToDeleteChild = ToDelete->Child4;
    LastColor = ToDelete->RedBlack;
    ToDeleteParent = ToDelete->Parent;
    if (ToDelete->RedBlack == Red)
    {
        if (ToDeleteParent->Child1 == ToDelete)
        {
            ToDeleteParent->Child1 = ToDeleteChild;
        }
        else
        {
            ToDeleteParent->Child4 = ToDeleteChild;
        }
    }
    else
    {
        if (ToDelete->Data < ToDeleteParent->Data)
            ToDeleteParent->Child1 = ToDeleteChild;
        else
            ToDeleteParent->Child4 = ToDeleteChild;
        FixUp(ToDeleteChild);
    }

    delete ToDelete;
    return ReturnValue;
}

template <typename T>
void Tree<T>::PrintPreOrder()
{
    Stack<Node<T> *> ST(20);
    Node<T> *p = root;
    while (p != nullptr || !ST.isEmpty())
    {
        if (p != nullptr)
        {
            std::cout << p->Data << ", ";
            ST.Push(p);
            p = p->Child1;
        }
        else
        {
            p = ST.Pop();
            p = p->Child4;
        }
    }
}