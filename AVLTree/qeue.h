#ifndef _QEUE_H_
#define _QEUE_H_

#include<iostream>
//Implementovane je cilkular qeue ulozenu ako array pretoze bez cilkular by sme vzdy museli vyprazdnit 
//array a az potom by sme mohli znova pridavat data takto pojdu rear a front index vzdy v kruhu

template<typename T>
struct Node
{
    Node<T> *Left;
    T Data;
    int Height;
    Node<T> *Right;

};

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
        if((Rear + 1)%Size == Front)
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

template<typename T>
void queue<T>::Enqueue(T data)
{
    if(IsFull())
    {
        std::cout<<"Queue is full";
    }
    else
    {
        Data[Rear] = data;
        Rear = (Rear + 1)%Size;
    }
}

template<typename T>
T queue<T>::Dequeue()
{
    T Temp{};
    if(IsEmpty())
    {
        std::cout<<"Queue is empty";
        return T{};
    }
    else
    {
        Temp = Data[Front];
        Front = (Front + 1)%Size;
        
    }
    return Temp;
}

template<typename T>
void queue<T>::Display()
{
    int i = Front + 1;
    do
    {
        std::cout<<Data<<",";
        i = (i + 1) % Size;
    }
    while(i != (Rear + 1) % Size);
    std::cout<<"\n";
}
#endif