#ifndef _DOUBLE_H_
#define _DOUBLE_H_

#include <iostream>

template <typename T>
struct Node
{
    Node<T> *Prev;
    T Data;
    Node<T> *Next;
};

template <typename T>
class Double;

template <typename T>
Double<T> &operator<<(Double<T> &Lhs, const T &rhs);

template <typename T>
std::ostream &operator<<(std::ostream &Os, const Double<T> &Rhs);

template <typename T>
class Double
{
private:
    Node<T> *First;
    int Len;
    //=====================
    // Pomocny Objekt na to aby vedel operator[] a operator= spolupracovat
    class IndexInserter
    {
    private:
        Double<T> &List;
        int Index;

    public:
        IndexInserter(Double<T> &list, int index) : List{list}, Index{index} {}
        IndexInserter &operator=(const T &value)
        {
            List.Insert(Index, value); // Index nam precita operator[] a value operator=
            return *this;              // vracia sa len kvoli funkcii podstatna funckia insert
        }
        IndexInserter operator--()
        {
            List.Delete(Index);
            return *this;
        }
        IndexInserter operator--(int)
        {
            List.Delete(Index);
            return *this;
        }
    };

public:
    Double(int Data = 0)
    {
        First = new Node<T>;
        First->Data = Data;
        First->Next = nullptr;
        First->Prev = nullptr;
        Len = 1;
    }

    friend Double<T> &operator<< <>(Double<T> &Lhs, const T &rhs);
    friend std::ostream &operator<< <>(std::ostream &Os, const Double<T> &Rhs);
    IndexInserter operator[](int Index) { return IndexInserter(*this, Index); }
    void Insert(int Index, const T &value);
    void Delete(int Index);
};

template <typename T>
Double<T> &operator<<(Double<T> &rhs, const T &value)
{
    Node<T> *q = new Node<T>;
    q->Data = value;
    q->Next = nullptr;

    if (rhs.First == nullptr)
    {
        q->Prev = nullptr;
        rhs.First = q;
        rhs.Len++;
        return rhs;
    }

    Node<T> *p = rhs.First;
    while (p->Next != nullptr)
        p = p->Next;

    p->Next = q;
    q->Prev = p;
    rhs.Len++;

    return rhs;
}

template <typename T>
std::ostream &operator<<(std::ostream &Os, const Double<T> &Rhs)
{
    Node<T> *p = Rhs.First;
    while (p)
    {
        Os << p->Data << " ";
        p = p->Next;
    }
    return Os;
}

template <typename T>
void Double<T>::Insert(int Index, const T &value)
{
    if (Index < 0 || Index > Len)
        return;

    Node<T> *p = new Node<T>;
    p->Data = value;
    p->Next = nullptr;
    p->Prev = nullptr;

    // 1) prázdny zoznam
    if (First == nullptr)
    {
        First = p;
        Len++;
        return;
    }

    // 2) vloženie na začiatok
    if (Index == 0)
    {
        p->Prev = nullptr;
        p->Next = First;
        First->Prev = p;
        First = p;
        Len++;
        return;
    }

    // 3) vloženie niekde v strede / na koniec
    Node<T> *q = First;
    for (int i = 0; i < Index - 1; i++)
    {
        q = q->Next;
    }

    p->Next = q->Next;
    p->Prev = q;

    if (q->Next)
    {
        q->Next->Prev = p;
    }

    q->Next = p;

    Len++;
}
template <typename T>
void Double<T>::Delete(int Index)
{
    if (Index < 0 || Index > Len)
    {
        return;
    }
    if (Index == 0)
    {
        Node<T> *p = First;
        First = First->Next;
        First->Prev = nullptr;
        delete p;
        Len--;
    }
    else
    {
        Node<T> *p = First;
        for (int i{}; i < Index - 1; i++)
        {
            p = p->Next;
        }
        p->Prev->Next = p->Next;
        if (p->Next)
        {
            p->Next->Prev = p->Prev;
        }
        delete p;
        Len--;
    }
}
#endif
