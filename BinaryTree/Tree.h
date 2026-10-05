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
    Node<T>* DeleteBTS(T Data, Node<T> *p = nullptr);
    Node<T>* InSucc(Node<T> *p);
    Node<T>* InPre(Node<T> *p);
    
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
    root->Child1 = root->Child4 = nullptr;
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
            t->Child1 = t->Child4 = nullptr;
            p->Child1 = t;
            Q.Enqueue(t);
        }
        std::cout << "Enter a value of right cild of " << p->Data << ": ";
        std::cin >> x;
        if (x != -1)
        {
            t = new Node<T>;
            t->Data = x;
            t->Child1 = t->Child4 = nullptr;
            p->Child4 = t;
            Q.Enqueue(t);
        }
    }
}

template <typename T>
void Tree<T>::InOrder(const Node<T> *p)
{
    if (p)
    {
        InOrder(p->Child1);
        std::cout << p->Data << ", ";
        InOrder(p->Child4);
    }
}

template <typename T>
void Tree<T>::PostOrder(const Node<T> *p)
{
    if (p)
    {
        InOrder(p->Child1);
        InOrder(p->Child4);
        std::cout << p->Data << ", ";
    }
}

template <typename T>
void Tree<T>::PreOrder(const Node<T> *p)
{
    if (p)
    {
        std::cout << p->Data << ", ";
        InOrder(p->Child1);
        InOrder(p->Child4);
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
        if (p->Child1)
        {
            std::cout << p->Child1->Data << " , ";
            Q.Enqueue(p->Child1);
        }
        if (p->Child4)
        {
            std::cout << p->Child4->Data << " , ";
            Q.Enqueue(p->Child4);
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
    x = Height(p->Child1);
    y = Height(p->Child4);
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
            t = t->Child1;
        }
        else
        {
            t = st.Pop();
            t = t->Child4;
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
            t = t->Child1;
        }
        else
        {
            t = st.Pop();
            std::cout << t->Data << ", ";
            t = t->Child4;
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
        if(t->Child1)
        {
            std::cout<<t->Child1->Data<<" , ";
            Q.Enqueue(t->Child1);
        }
         if(t->Child4)
        {
            std::cout<<t->Child4->Data<<" , ";
            Q.Enqueue(t->Child4);
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
            t = t->Child1;
        }
        else if(t->Data < Key)
        {
            t = t->Child4;
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
        root->Child1=root->Child4 = nullptr;
        return;
    }
    Node<T> *t = root,*p = nullptr;

    while(t != nullptr)
    {
         p = t;
        if(t->Data > Data)
        {
            t = t->Child1;
        }
        else if(t->Data < Data)
        {
            t = t->Child4;
        }
        else 
        {
            return;
        }
    }
    Node<T> *r = new Node<T>;
    r->Child1 = r->Child4 = nullptr;
    r->Data = Data;
    if(p->Data > Data)
    {
        p->Child1 = r;
    }
    else
    {
        p->Child4 = r;
    }
}

template<typename T>
void Tree<T>::CreatePreOrd(T *Data, int Size)
{
    int i = 0;
    root = new Node<T>;
    root->Data = Data[i];
    i++;
    root->Child1 = root->Child4 = nullptr;
    Node<T> *p = root,*t = nullptr;
    while(i < Size)
    {
        if(Data[i] < p->Data)
        {
            t = new Node<T>;
            t->Data = Data[i];
            t->Child1 = t->Child4 = nullptr;
            p->Child1 = t;
            p = t;
            i++;
        }
        else
        {
            if(Data[i] > p->Data && Data[i] < root->Data)
            {
                t = new Node<T>;
                t->Data = Data[i];
                t->Child1 = t->Child4 = nullptr;
                p->Child4 = t;
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

template<typename T>
Node<T>* Tree<T>::InSucc(Node<T> *p)
{
    while(p && p->Child1 != nullptr)
    {
        p = p->Child1;
    }
    return p;
}

template<typename T>
Node<T>* Tree<T>::InPre(Node<T> *p)
{
    while(p && p->Child4 != nullptr)
    {
        p = p->Child4;
    }
    return p;
}

template<typename T>
Node<T>* Tree<T>::DeleteBTS(T Data, Node<T> *p = nullptr)
{
    if(p == nullptr)
    {
        p = root;
    }
    else if(p == nullptr)
    {
        return nullptr;
    }
    if(p->Child1 == nullptr && p->Child4 == nullptr)
    {
        if(p == root)
        {
            delete root;
            root = nullptr;
            return nullptr;
        }
        delete p;
        return nullptr;
    }
    if (p->Data > Data)
    {
        p->Child1 = DeleteBTS(Data, p->Child1);
    }
    else if(p->Data < Data)
    {
        p->Child4 = DeleteBTS(Data, p->Child4);
    }
    else
    {
        Node<T> *q;
        if(Height(p->Child1) > Height(p->Child4))
        {
            q = InPre(p->Child1);
            p->Data = q->Data;
            p->Child1 = DeleteBTS(q->Data, p->Child1);
        }
        else
        {
            q = InSucc(p->Child4);
            p->Data = q->Data;
            p->Child4 = DeleteBTS(q->Data, p->Child4);
        }
    }
    
}

#endif