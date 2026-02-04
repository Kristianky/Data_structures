#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include <string>
struct Node
{
    int data;
    Node *Next;
};



class LinkedList
{
   private:
       Node *First;
       Node *Last;
       int count;
       std::wstring Return_Value;
   public:
       LinkedList ();
       ~LinkedList() = default;
       LinkedList(const LinkedList &Source);
       LinkedList operator+(const LinkedList &rhs) const;
       LinkedList operator=(const LinkedList &rhs);
       void SetData(const wchar_t *Data);
       void Add(const wchar_t *data);
       const wchar_t* Print();
       int sum();
       const wchar_t* Max();
       const wchar_t* Min();
       Node* Search(wchar_t *Key);
       int Count() {return count;}
       void Insert(wchar_t *Place,wchar_t *data);
       void InsertInSorted(wchar_t *data);
       void Delete(int Position);
       bool Issorted();
       void RemoveDuplicates();
       void ReverseData();
       void ReverseLinks();
      
};

#endif