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
       Node *First;
    public:
       List(int data){First = new Node;First->data = data;First->Next = First;};
       ~List() = default;
       void Display();
       void AddData(int Data);
      
};

#endif