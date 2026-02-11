#ifndef _STACK_H_
#define _STACK_H_

#include<iostream>

template <typename T>
class Node
{
public:
    Node *Next;
    T Data;
};

template<typename T>
class Stack;

template<typename T>
std::ostream &operator<<(std::ostream &Os,const Stack<T> &Rhs);


template <typename T>
class Stack
{
private:
    Node<T> *First;
    int Size;
    int Top;
    friend std::ostream &operator<< <>(std::ostream &os,const Stack<T> &Rhs);

public:
    Stack(T Data = 0, int Size = 1)
    {
        First = new Node<T>;
        First->Data = Data;
        Stack::Size = Size;
        Top = 0;
        First->Next = nullptr;
    }
    ~Stack() = default;
    bool isEmpty()
    {
        if (Top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        if(Top == Size - 1)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
    void Push(T Data);
    void Pop();
    void Peek(int Index);
};
template<typename T>
void Stack<T>::Push(T Data)
{
    if(isFull())
    {
        std::cout<<"Stack Owerflow";
    }
    else
    {
        Node<T> *p = new Node<T>;
        p->Data = Data;
        p->Next = First;
        First = p;
        Top++;
    }
}
template<typename T>
void Stack<T>::Pop()
{
    if(isEmpty())
    {
        std::cout<<"Stack Underflow";
    }
    else
    {
        Node<T> *p = First;
        First = First->Next;
        delete p;
        Top--;

    }
}
template<typename T>
std::ostream &operator<<(std::ostream &os,const Stack<T> &Rhs)
{
    Node<T> *p = Rhs.First;
    while(p != nullptr)
    {
        os<<p->Data<<", ";
        p = p->Next;
    }
    os<<"\n";
    return os;

}
#endif