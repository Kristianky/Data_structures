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

        if (parentNode == grandParent->Left)
        {
            Node<T> *uncle = grandParent->Right;

            if (uncle != nullptr && uncle->RedBlack == Red)
            {
                ReColor(grandParent, parentNode, uncle);
                p = grandParent;
            }
            else
            {
                if (p == parentNode->Right)
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
            Node<T> *uncle = grandParent->Left;

            if (uncle != nullptr && uncle->RedBlack == Red)
            {
                ReColor(grandParent, parentNode, uncle);
                p = grandParent;
            }
            else
            {
                if (p == parentNode->Left)
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
            current = current->Left;
        else if (Data > current->Data)
            current = current->Right;
        else
            return -1; // duplicate
    }

    Node<T> *inserted = new Node<T>;
    inserted->Data = Data;
    inserted->Left = nullptr;
    inserted->Right = nullptr;
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
        parent->Left = inserted;
    else
        parent->Right = inserted;
    FixUp(inserted);
    root->RedBlack = Black;
    root->Parent = nullptr;
    return 1;
}

template <typename T>
void Tree<T>::RotateLeft(Node<T> *p)
{
    Node<T> *right = p->Right;
    Node<T> *middle = right->Left;
    Node<T> *oldParent = p->Parent;

    right->Parent = oldParent;
    if (oldParent == nullptr)
        root = right;
    else if (oldParent->Left == p)
        oldParent->Left = right;
    else
        oldParent->Right = right;

    right->Left = p;
    p->Parent = right;
    p->Right = middle;
    if (middle != nullptr)
        middle->Parent = p;
}

template <typename T>
void Tree<T>::RotateRight(Node<T> *p)
{
    Node<T> *left = p->Left;
    Node<T> *middle = left->Right;
    Node<T> *oldParent = p->Parent;

    left->Parent = oldParent;
    if (oldParent == nullptr)
        root = left;
    else if (oldParent->Left == p)
        oldParent->Left = left;
    else
        oldParent->Right = left;

    left->Right = p;
    p->Parent = left;
    p->Left = middle;
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
    RotateLeft(p->Left);
    RotateRight(p);
    return p->Parent;
}

template <typename T>
Node<T> *Tree<T>::RLRotation(Node<T> *p)
{
    RotateRight(p->Right);
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
    p = p->Right;
    while (p != nullptr)
    {
        ReturnValue = p;
        p = p->Left;
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
    p = p->Left;
    while (p != nullptr)
    {
        ReturnValue = p;
        p = p->Right;
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
            p = p->Left;
        }
        else
        {
            p = p->Right;
        }
    }
    if (p == nullptr)
    {
        return 0;
    }
    Node<T> *ToDelete = p, *ToDeleteParent = nullptr, *ToDeleteChild = nullptr;
    ReturnValue = p->Data;
    if (ToDelete->Left && ToDelete->Right)
    {
        ToDelete = InSuccessor(ToDelete);
        p->Data = ToDelete->Data;
    }
    if (ToDelete->Left)
        ToDeleteChild = ToDelete->Left;
    else if (ToDelete->Right)
        ToDeleteChild = ToDelete->Right;
    LastColor = ToDelete->RedBlack;
    ToDeleteParent = ToDelete->Parent;
    if (ToDelete->RedBlack == Red)
    {
        if (ToDeleteParent->Left == ToDelete)
        {
            ToDeleteParent->Left = ToDeleteChild;
        }
        else
        {
            ToDeleteParent->Right = ToDeleteChild;
        }
    }
    else
    {
        if (ToDelete->Data < ToDeleteParent->Data)
            ToDeleteParent->Left = ToDeleteChild;
        else
            ToDeleteParent->Right = ToDeleteChild;
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
            p = p->Left;
        }
        else
        {
            p = ST.Pop();
            p = p->Right;
        }
    }
}