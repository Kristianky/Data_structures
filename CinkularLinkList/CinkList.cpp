#include "CinkList.h"

void List::Display()
{
    Node *p = First;
    do
    {
        std::cout<<p->data<<"\n";
        p = p->Next;
    }
    while(p != First);
}

void List::AddData(int Data)
{
    Node *p,*Last = First;
    p = new Node;
    p->data = Data;
    p->Next = Last->Next;
    Last->Next = p;
    Last = p;
    
    
}