#ifndef _QEUE_H_
#define _QEUE_H_

#include <iostream>
#include <cstdint>
// Implementovane je cilkular qeue ulozenu ako array pretoze bez cilkular by sme vzdy museli vyprazdnit
// array a az potom by sme mohli znova pridavat data takto pojdu rear a front index vzdy v kruhu

template <typename T>
class Node
{
public:
    Node<T> *Parent;
    Node<T> *Child1;
    Node<T> *Child2;
    T A;
    T B;
    T C;
    Node<T> *Child3;
    Node<T> *Child4;
    int Height;
    // Fuctions
    bool IsEmpty();
    bool IsFull();
    bool IsLeaf();
    uint16_t ValueCount();
    // Cosntructor
    Node(Node<T> *ParentInit = nullptr, Node<T> *LeftInit = nullptr, Node<T> *MidleLeft = nullptr, Node<T> *MidleRight = nullptr, Node<T> *Right = nullptr);
    Node(T Data,Node<T>* Left,Node<T>* Right,Node<T>* Parent);
    Node(T Data)
    {A = Data;Child1 = Child2 = Child3 = Child4 = Parent = nullptr;B = C = static_cast<T>(INT16_MIN);}
};

template <typename T>
Node<T>::Node(Node<T> *ParentInit, Node<T> *LeftInit, Node<T> *MidleLeftInit,
              Node<T> *MidleRightInit, Node<T> *RightInit)
    : Parent{ParentInit}, Child1{LeftInit}, Child2{MidleLeftInit}, Child3{MidleRightInit}, Child4{RightInit}
{
}

template<typename T>
Node<T>::Node(T DataInit,Node<T>* LeftInit,Node<T>* RightInit,Node<T>* ParentInit)
{
    A = DataInit;
    B = static_cast<T>(INT16_MIN);
    C = static_cast<T>(INT16_MIN);
    Child1 = LeftInit;
    Child2 = RightInit;
    Parent = ParentInit;
    Child3 = nullptr;
    Child4 = nullptr;

}
template <typename T>
uint16_t Node<T>::ValueCount()
{
    uint16_t ReturnValue = 0;
    T MinValue = static_cast<T>(INT_MIN);
    if (MinValue != A)
        ReturnValue = 1;
    if (MinValue != B)
        ReturnValue = 2;
    if (MinValue != C)
        ReturnValue = 3;
    return ReturnValue;
}

template <typename T>
bool Node<T>::IsEmpty()
{
    T EmptyValue = static_cast<T>(INT16_MIN);
    if (A == EmptyValue && B == EmptyValue && C == EmptyValue)
        return true;
    return false;
}

template <typename T>
bool Node<T>::IsFull()
{
    T EmptyValue = static_cast<T>(INT16_MIN);
    if (A != EmptyValue && B != EmptyValue && C != EmptyValue)
        return true;
    return false;
}

template <typename T>
bool Node<T>::IsLeaf()
{
    if (!Child1 && !Child2 && !Child3 && !Child4)
        return true;
    return false;
}

template <typename T>
class queue
{
private:
    int Size, Rear, Front;
    T *Data;

public:
    queue(int size = 1) : Size{size}
    {
        Data = new T[Size];
        Front = 0;
        Rear = 0;
    }
    ~queue() = default;
    bool IsEmpty()
    {
        if (Rear == Front)
            return true;
        else
            return false;
    };
    bool IsFull()
    {
        if ((Rear + 1) % Size == Front)
            return true;
        else
            return false;
    };
    T First() { return Data[Front]; }
    T Lasts() { return Data[Rear]; }
    void Enqueue(T data);
    T Dequeue();
    void Display();
};

template <typename T>
void queue<T>::Enqueue(T data)
{
    if (IsFull())
    {
        std::cout << "Queue is full";
    }
    else
    {
        Data[Rear] = data;
        Rear = (Rear + 1) % Size;
    }
}

template <typename T>
T queue<T>::Dequeue()
{
    T Temp{};
    if (IsEmpty())
    {
        std::cout << "Queue is empty";
        return T{};
    }
    else
    {
        Temp = Data[Front];
        Front = (Front + 1) % Size;
    }
    return Temp;
}

template <typename T>
void queue<T>::Display()
{
    int i = Front + 1;
    do
    {
        std::cout << Data << ",";
        i = (i + 1) % Size;
    } while (i != (Rear + 1) % Size);
    std::cout << "\n";
}
#endif