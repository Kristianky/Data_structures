#ifndef _STACK_H_
#define _STACK_H_

#include<iostream>

template <typename T>
class node
{
public:
    node *Next;
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
    node<T> *First;
    int Size;
    int Top;
    friend std::ostream &operator<< <>(std::ostream &os,const Stack<T> &Rhs);

public:
    Stack( int Size) {Stack<T>::Size = Size;Top = -1;}
   
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
    T Pop();
    void Peek(int Index);
};
template<typename T>
void Stack<T>::Push(T Data)
{
    if(isFull())
    {
        std::cout<<"Stack Owerflow! ";
    }
    else
    {
        node<T> *p = new node<T>;
        p->Data = Data;
        p->Next = First;
        First = p;
        Top++;
    }
}
template<typename T>
T Stack<T>::Pop()
{
    T ReturnValue = nullptr;
    if(isEmpty())
    {
        std::cout<<"Stack Underflow";
        return ReturnValue;
    }
    else
    {
        node<T> *p = First;
        First = First->Next;
        ReturnValue = p->Data;
        delete p;
        Top--;
    }
    return ReturnValue;
}
template<typename T>
std::ostream &operator<<(std::ostream &os,const Stack<T> &Rhs)
{
    node<T> *p = Rhs.First;
    while(p != nullptr)
    {
        os<<p->Data<<", ";
        p = p->Next;
    }
    os<<"\n";
    return os;

}
#endif