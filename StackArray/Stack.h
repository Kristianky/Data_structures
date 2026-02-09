#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>
template <typename T>
class Stack
{
private:
    int Size;
    int Top;
    T *Arr;

public:
    Stack(int size = 0, int top = -1, T *arr = nullptr) : Size{size}, Top{top}, Arr{arr}
    {
        Arr = new Arr[Size];
    }
    bool Empty();
    bool Full();
    T Top();
    T pop();
    void Push(T data);
};
template <typename T>
bool Stack<T>::Empty()
{
    if (Top == -1)
    {
        return true;
    }
    else
        return false;
}

template <typename T>
bool Stack<T>::Full()
{
    if (Top > Size - 1)
    {
        return true;
    }
    else 
    {
        return false;
    }
}
template<typename T>
T Stack<T>::pop()
{
    T Data = 0;
    if(Empty)
    {
        std::cout<<"Stack unedrflow!!\n";
        return T;
    }
    else 
    {
        Data = Arr[Top];
        Top--;
        return Data;
    }
}
#endif