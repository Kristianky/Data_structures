#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>
#include <cstring>

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
    int PreOut(char c);
    int PreIn(char c);
    char *InfixToPostfix(const char *Test);
    bool ISOperand(char c);
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
    T Data = -1;
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
    if (Full())
    {
        std::cout << "Stack Owerflow";
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

template <typename T>
int Stack<T>::PreIn(char c)
{
    if (c == '+' || c == '-')
    {
        return 2;
    }
    if (c == '/' || c == '*')
    {
        return 4;
    }
    if (c == '^')
    {
        return 5;
    }
    if (c == '(' || c == '{')
    {
        return 0;
    }
    else
        return 0;
}

template <typename T>
int Stack<T>::PreOut(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    if (c == '/' || c == '*')
    {
        return 3;
    }
    if (c == '^')
    {
        return 6;
    }
    if (c == '(' || c == '{')
    {
        return 7;
        
    }
    if (c == ')' || '}')
        return 0;
    else
        return 0;
}

template <typename T>
bool Stack<T>::ISOperand(char c)
{
    if (c < 48 || c == 94)
    {
        return false;
    }
    else
        return true;
}
template <typename T>
char *Stack<T>::InfixToPostfix(const char *Test)
{
    while(Top != -1)
    {
        pop();
    }
    char *Result;
    int Size = strlen(Test) + 1;
    Result = new char[Size];
    int i{}, j{};
    while (Test[i] != '\0')
    {
        if (ISOperand(Test[i]))
        {
            Result[j] = Test[i];
            i++, j++;
        }
        else
        {
            if (PreOut(Test[i]) > PreIn(Arr[Top]))
            {
                Push(Test[i]);
                i++;
            }
            else if(PreOut(Test[i]) == PreIn(Arr[Top]))
            {
                pop();
                i++;
                
            }
            else
            {
                Result[j] = Arr[Top];
                j++;
                pop();
            }
        }
    }
    while (Top != -1)
    {
        Result[j] = Arr[Top];
        j++;
        pop();
    }
    Result[j] = '\0';
    return Result;
}
#endif