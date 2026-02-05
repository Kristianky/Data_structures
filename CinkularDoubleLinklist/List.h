#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
#include <stack>

template <typename T>
struct Node
{
    Node<T> *Next;
    T Data;
    Node<T> *Prev;
};

template <typename T>
class List;

template <typename T>
List<T> &operator<<(List<T> &Lhs, const T &value);

template <typename T>
std::ostream &operator<<(std::ostream &os, const List<T> &Rhs);

template <typename T>
class List
{
private:
    Node<T> *Head;
    int Len;
    class IndexInserter
    {
    private:
        int Index;
        List &list;

    public:
        IndexInserter(List<T> &lst, int index) : list{lst}, Index{index} {}
        IndexInserter operator=(const T &Value)
        {
            list.Insert(Index, Value);
            return *this;
        }
        IndexInserter operator--()
        {
            list.Delete(Index);
            return *this;
        }
        IndexInserter operator--(int)
        {
            list.Delete(Index);
            return *this;
        }
    };

public:
    List(T Data = 0)
    {
        Head = new Node<T>;
        Head->Data = Data;
        Head->Prev = Head;
        Head->Next = Head;
        Len = 1;
    }
    void Insert(int Index, T Value);
    void Delete(int Index);
    friend List<T> &operator<< <>(List<T> &Lhs, const T &value);
    friend std::ostream &operator<< <>(std::ostream &os, const List<T> &Rhs);
    IndexInserter operator[](int Index) { return IndexInserter(*this, Index); }
};
template <typename T>
List<T> &operator<<(List<T> &Lhs, const T &value)
{
    Node<T> *p = new Node<T>;
    p->Data = value;

    if (Lhs.Head == nullptr)
    {
        Lhs.Head = p;
        p->Next = p;
        p->Prev = p;
        Lhs.Len++;
        return Lhs;
    }

    Node<T> *last = Lhs.Head->Prev;

    p->Next = Lhs.Head;
    p->Prev = last;

    last->Next = p;
    Lhs.Head->Prev = p;

    Lhs.Len++;
    return Lhs;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const List<T> &Rhs)
{
    Node<T> *p = Rhs.Head;
    do
    {
        os << p->Data << "\n";
        p = p->Next;
    } while (p != Rhs.Head);
    os << "====================\n";
    return os;
}

template <typename T>
void List<T>::Insert(int Index, T Value)
{
    if (Head == nullptr)
    {
        return;
    }
    Node<T> *p = Head;
    for (int i{}; i < Index - 1; i++)
    {
        p = p->Next;
    }
    Node<T> *t = new Node<T>;
    t->Data = Value;
    t->Next = p->Next;
    t->Prev = p;
    p->Next->Prev = t;
    p->Next = t;
    Len++;
}
template <typename T>
void List<T>::Delete(int Index)
{
    if (Index < 0 || Index > Len)
    {
        return;
    }
    Node<T> *p = Head;
    for (int i{}; i < Index; i++)
    {
        p = p->Next;
    }
    p->Prev->Next = p->Next;
    p->Next->Prev = p->Prev;
    if (p == Head)
    {
        Head = p->Next;;
    }
    delete p;
    Len--;
}

#endif