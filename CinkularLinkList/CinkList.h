#ifndef _CINKLIST_H_
#define _CINKLIST_H_

#include <iostream>

struct Node
{
    int data;
    Node *Next;
};

class List
{
    private:
       Node *Head;
       int Len;
    public:
       List(int data){Head = new Node;Head->data = data;Head->Next = Head;Len = 1;};
       ~List() = default;
       void Display();
       void AddData(int Data);
       void Insert(int Position,int Data);
       int Lenght();
       void Delete(int Index);
};

#endif