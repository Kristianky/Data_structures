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
        Arr = new T[Size];
    }
    bool Empty();
    bool Full();
    T GetTop();
    T pop();
    void Push(T data);
    bool ParenthisisMatch(const char *String);
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
template <typename T>
T Stack<T>::pop()
{
    T Data = 0;
    if (Empty())
    {
        std::cout << "Stack unedrflow!!\n";
        return Data;
    }
    else
    {
        Data = Arr[Top];
        Top--;
        return Data;
    }
}
template <typename T>
void Stack<T>::Push(T Data)
{
    if(Full())
    {
        std::cout<<"Stack Owerflow";
    }
    else
    {
        Top++;
        Arr[Top] = Data;
    }
}
template <typename T>
bool Stack<T>::ParenthisisMatch(const char *String)
{
    for (int i{}; String[i] != '\0'; i++)
    {
        if (String[i] == '(' || String[i] == '[' || String[i] == '{')
        {
            Push(String[i]);
        }
        else if (!Empty() && (Arr[Top] == String[i] - 1 || Arr[Top] == String[i] - 2))
        {
            pop();
        }
    }
    return Empty();
}
#endif