#include "CinkList.h"

void List::Display()
{
    Node *p = Head;
    do
    {
        std::cout << p->data << "\n";
        p = p->Next;
    } while (p != Head);
}

void List::AddData(int Data)
{
    Node *p, *Last = Head;
    p = new Node;
    p->data = Data;
    p->Next = Last->Next;
    Last->Next = p;
    Last = p;
    Len++;
}

void List::Insert(int Position, int Data)
{
    Node *p = new Node;
    p->data = Data;
    if (Position < 0 || Position > Len)
        return;
    if (Position == 0)
    {
        Node *q = Head;
        if (Head == nullptr)
        {
            Head = q;
            Head->Next = Head;
        }
        else
        {
            do
            {
                q = q->Next;
            } while (q->Next != Head);
            q->Next = p;
            p->Next = Head;
            Head = p;
            Len++;
        }
    }
    else
    {
        Node *q = Head;
        int count{};
        for (count; count < Position - 1; count++)
        {
            q = q->Next;
        }
        p->Next = q->Next;
        q->Next = p;
        Len++;
    }
}

int List::Lenght()
{
    Len = 0;
    Node *p = Head;
    do
    {
        Len++;
        p = p->Next;
    } while (p != Head);
    return Len;
}

void List::Delete(int Index)
{
    if(Index < 0 || Index > Len)
    {
        return;
        std::cout<<"\nIndex je mimo rozmedzia";
    }
    if (Index == 0)
    {
        Node *p = Head;
        while (p->Next != Head)
        {
            p = p->Next;
        }
        if (p == Head)
        {
            delete Head;
            Head = nullptr;
        }
        else
        {
            p->Next = Head->Next;
            delete Head;
            Head = p->Next;
        }
    }
    else
    {
       Node *p = Head;
       Node *q = nullptr;
       int i{};
       for(i;i < Index - 1;i++)
       {
        p = p->Next;
       }
       q = p->Next;
       p->Next = q->Next;
       delete q;
       q = nullptr;
    }
}