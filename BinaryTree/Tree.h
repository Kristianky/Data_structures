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
    Tree() {root = nullptr;};
    ~Tree() { delete root; };
    void CreateTree();
    void InOrder(const Node<T> *p);
    void PostOrder(const Node<T> *p);
    void PreOrder(const Node<T> *p);
    void LevelOrder(Node<T> *p);
    int Height(Node<T> *p);
    void PostOrderItterative();
    void PreOrderItterative();
    void InOrderItterative();
    void LevelOrderIterative();
    Node<T>* BinarySearch(T Key); //Must be ordered
    void AddBTS(T Data);
    void CreatePreOrd(T *Data, int Size);
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
    std::cout << p->Data << " , ";
    Q.Enqueue(p);

    while (!Q.IsEmpty())
    {
        p = Q.Dequeue();
        if (p->Left)
        {
            std::cout << p->Left->Data << " , ";
            Q.Enqueue(p->Left);
        }
        if (p->Right)
        {
            std::cout << p->Right->Data << " , ";
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

template <typename T>
void Tree<T>::PreOrderItterative()
{
    Node<T> *t = root;
    Stack<Node<T> *> st(20);
    while (t != nullptr || !st.isEmpty())
    {
        if (t != nullptr)
        {
            std::cout << t->Data << " ,";
            st.Push(t);
            t = t->Left;
        }
        else
        {
            t = st.Pop();
            t = t->Right;
        }
    }
}
template <typename T>
void Tree<T>::InOrderItterative()
{
    Node<T> *t = root;
    Stack<Node<T> *> st(20);
    while (t != nullptr || !st.isEmpty())
    {
        if (t != nullptr)
        {
            st.Push(t);
            t = t->Left;
        }
        else
        {
            t = st.Pop();
            std::cout << t->Data << ", ";
            t = t->Right;
        }
    }
}

template <typename T>
void Tree<T>::LevelOrderIterative()
{
    Node<T> *t = root;
    queue<Node<T> *> Q(100);
    Q.Enqueue(root);
    std::cout<<t->Data<<" , ";
    while (!Q.IsEmpty())
    {
        t = Q.Dequeue();
        if(t->Left)
        {
            std::cout<<t->Left->Data<<" , ";
            Q.Enqueue(t->Left);
        }
         if(t->Right)
        {
            std::cout<<t->Right->Data<<" , ";
            Q.Enqueue(t->Right);
        }
    }
}

template <typename T>
Node<T>* Tree<T>::BinarySearch(T Key)
{
    Node<T> *t = root;
    while(t != nullptr)
    {
        if(t->Data > Key)
        {
            t = t->Left;
        }
        else if(t->Data < Key)
        {
            t = t->Right;
        }
        else
        {
            return t;
        }
        return nullptr;
    }

}

template<typename T>
void Tree<T>::AddBTS(T Data)
{
    if(root == nullptr)
    {
        root = new Node<T>;
        root->Data = Data;
        root->Left=root->Right = nullptr;
        return;
    }
    Node<T> *t = root,*p = nullptr;

    while(t != nullptr)
    {
         p = t;
        if(t->Data > Data)
        {
            t = t->Left;
        }
        else if(t->Data < Data)
        {
            t = t->Right;
        }
        else 
        {
            return;
        }
    }
    Node<T> *r = new Node<T>;
    r->Left = r->Right = nullptr;
    r->Data = Data;
    if(p->Data > Data)
    {
        p->Left = r;
    }
    else
    {
        p->Right = r;
    }
}

template<typename T>
void Tree<T>::CreatePreOrd(T *Data, int Size)
{
    int i = 0;
    root = new Node<T>;
    root->Data = Data[i];
    i++;
    root->Left = root->Right = nullptr;
    Node<T> *p = root,*t = nullptr;
    while(i < Size)
    {
        if(Data[i] < p->Data)
        {
            t = new Node<T>;
            t->Data = Data[i];
            t->Left = t->Right = nullptr;
            p->Left = t;
            p = t;
            i++;
        }
        else
        {
            if(Data[i] > p->Data && Data[i] < root->Data)
            {
                t = new Node<T>;
                t->Data = Data[i];
                t->Left = t->Right = nullptr;
                p->Right = t;
                p = t;
                i++;
            }
            else
            {
                p = root;
            }
        }
    }

}
#endif