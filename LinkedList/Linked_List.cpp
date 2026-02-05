#include "Linked_List.h"

LinkedList::LinkedList()
{
    First = new Node;
    First->data = 0;
    First->Next = nullptr;
    Last = First;
    count = 1;
}

// Copy constructor
LinkedList::LinkedList(const LinkedList &rhs) : First(nullptr)
{
    if (rhs.First == nullptr)
        return;

    First = new Node;
    First->data = rhs.First->data;
    First->Next = nullptr;

    Node *Temp = First;
    Node *TempRhs = rhs.First->Next;

    while (TempRhs != nullptr)
    {
        Temp->Next = new Node;
        Temp = Temp->Next;

        Temp->data = TempRhs->data;
        Temp->Next = nullptr;

        TempRhs = TempRhs->Next;
    }
}
// Operator =
LinkedList LinkedList::operator=(const LinkedList &rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    First = nullptr;
    First = new Node;
    First->data = rhs.First->data;
    First->Next = nullptr;

    Node *Temp = First;
    Node *TempRhs = rhs.First->Next;

    while (TempRhs != nullptr)
    {
        Temp->Next = new Node;
        Temp = Temp->Next;

        Temp->data = TempRhs->data;
        Temp->Next = nullptr;

        TempRhs = TempRhs->Next;
    }
}
LinkedList LinkedList::operator+(const LinkedList &rhs) const
{
    LinkedList result;

    Node dummy;               // pomocný uzol
    Node *tail = &dummy;      // ukazuje na koniec výsledku
    dummy.Next = nullptr;

    Node *a = First;
    Node *b = rhs.First;

    while (a && b)
    {
        if (a->data < b->data)
        {
            tail->Next = new Node{a->data, nullptr};
            a = a->Next;
        }
        else
        {
            tail->Next = new Node{b->data, nullptr};
            b = b->Next;
        }
        tail = tail->Next;
    }

    // pridaj zvyšok
    Node *rest = (a ? a : b);
    while (rest)
    {
        tail->Next = new Node{rest->data, nullptr};
        tail = tail->Next;
        rest = rest->Next;
    }

    result.First = dummy.Next;
    return result;
}

void LinkedList::Add(const wchar_t *data)
{
    Node *Temp;
    std::wstring Change = data;
    Temp = new Node;
    Temp->Next = nullptr;
    Temp->data = std::stoi(Change);
    Last->Next = Temp;
    Last = Temp;
    count++;
}

const wchar_t *LinkedList::Print()
{
    Node *Temp = First;
    Return_Value = L"";
    int i = 1;
    while (Temp->Next)
    {
        Return_Value += std::to_wstring(Temp->data);
        Return_Value += ',';
        Temp = Temp->Next;
    }
    Return_Value += std::to_wstring(Temp->data);
    return Return_Value.c_str();
}
void LinkedList::SetData(const wchar_t *data)
{
    std::wstring Change = data;
    Last->data = std::stoi(Change);
}

int LinkedList::sum()
{
    Node *Temp = First;
    int sum{};
    while (Temp != nullptr)
    {
        sum += Temp->data;
        Temp = Temp->Next;
    }
    return sum;
}

const wchar_t *LinkedList::Max()
{
    Node *Temp = First;
    int Max = 0;
    Return_Value = L"";
    while (Temp)
    {
        if (Max < Temp->data)
        {
            Max = Temp->data;
        }
        Temp = Temp->Next;
    }
    Return_Value = std::to_wstring(Max);
    return Return_Value.c_str();
}

const wchar_t *LinkedList::Min()
{
    Node *Temp = First;
    int Min = INT_MAX;
    Return_Value = L"";
    while (Temp)
    {
        if (Min > Temp->data)
        {
            Min = Temp->data;
        }
        Temp = Temp->Next;
    }
    Return_Value = std::to_wstring(Min);
    return Return_Value.c_str();
}

Node *LinkedList::Search(wchar_t *key)
{
    Node *Temp = First;
    Return_Value = key;
    while (Temp)
    {
        if (std::stoi(Return_Value) == Temp->data)
        {
            return Temp;
        }
        Temp = Temp->Next;
    }
    return NULL;
}

/*Move to head traspostion - Prehadzuje najdeny element na prvu poziciu
Node* LinkedList::Search(wchar_t *key)
{
   Node *temp = first;
   Node *temp_2 = NULL;
   while (Temp)
   {
      if (std::stoi(Return_Value)==Temp->data)
      {
         temp_2->Next = temp->Next;
         temp_Next = First;
         first = temp;
         return temp;
      }
      else
      {
         temp_2 = temp;
         temp = temp->Next;
    }
   }
    return NULL;
}*/

// vkladanie
void LinkedList::Insert(wchar_t *Place, wchar_t *data)
{
    std::wstring Place_Temp = Place, Data_Tamp = data;
    int temp_Place_int = std::stoi(Place_Temp), tamp_Data_int = std::stoi(Data_Tamp);
    // Ak je to na zaciatku musi byt logika takato pretoze presuvame first node
    if (temp_Place_int == 0)
    {
        Node *Temp = new Node;
        Temp->data = tamp_Data_int;
        Temp->Next = First;
        First = Temp;
    }
    else
    {
        Node *Temp = First;
        Node *NewNode = new Node;
        NewNode->data = tamp_Data_int;
        for (int i{}; i < temp_Place_int - 1; i++)
        {
            if (!Temp->Next)
            {
                break;
            }
            Temp = Temp->Next;
        }
        NewNode->Next = Temp->Next;
        Temp->Next = NewNode;
    }
}
//=================================================
void LinkedList::InsertInSorted(wchar_t *data)
{
    std::wstring Data_temp = data;
    int Data_Int = std::stoi(Data_temp);
    Node *Temp = First;
    Node *Second = nullptr;
    while (Temp)
    {
        if (Data_Int < Temp->data)
        {
            Second = Temp;
            Temp = Second->Next;
        }
        else
        {
            Node *Result = new Node;
            Result->data = Data_Int;
            Result->Next = Second->Next;
            Second->Next = Result;
            break;
        }
    }
}
//===========================================================
void LinkedList::Delete(int Position)
{
    Node *temp = nullptr;
    Node *Temp2 = nullptr;
    int Count = 0;
    if (Position == 0)
    {
        temp = First;
        First = First->Next;
        delete temp;
    }
    else
    {
        temp = First;
        for (Count; Count < Position - 1; Count++)
        {
            Temp2 = temp;
            temp = temp->Next;
        }
        Temp2->Next = temp->Next;
        delete temp;
    }
}
//===================================================================
bool LinkedList::Issorted()
{
    Node *Temp1 = First;
    int x = INT_MIN;
    while (Temp1 != nullptr)
    {
        if (Temp1->data < x)
        {
            return false;
        }
        else
        {
            x = Temp1->data;
            Temp1 = Temp1->Next;
        }
    }
    return true;
}
//================================================================
void LinkedList::RemoveDuplicates()
{
    Node *Temp = First;
    Node *Temp2 = Temp->Next;
    while (Temp2 != NULL)
    {
        if (Temp->data != Temp2->data)
        {
            Temp = Temp2;
            Temp2 = Temp2->Next;
        }
        else
        {
            Temp->Next = Temp2->Next;
            delete Temp2;
            Temp2 = Temp->Next;
        }
    }
}
//=============================================
void LinkedList::ReverseData()
{
    Node *Temp = First;
    int *Data;
    // Zistenie velkosti array
    int i = 1;
    while (Temp != nullptr)
    {
        i++;
        Temp = Temp->Next;
    }
    Temp = First;
    Data = new int[i];
    int j{};
    while (Temp != nullptr)
    {
        Data[j] = Temp->data;
        Temp = Temp->Next;
        j++;
    }
    j--;
    Temp = First;
    while (Temp != nullptr)
    {
        Temp->data = Data[j];
        Temp = Temp->Next;
        j--;
    }
}
//=====================================================
void LinkedList::ReverseLinks()
{
    Node *Temp1 = First;
    Node *Temp2 = nullptr;
    Node *Temp3 = nullptr;
    while (Temp1 != nullptr)
    {
        Temp3 = Temp2;
        Temp2 = Temp1;
        Temp1 = Temp1->Next;
        Temp2->Next = Temp3;
    }
}
//==========================================
// Reversing with recursion
/*
void ReverseRecurs(Node *Temp1,Node *Temp2)
{
  if(Temp2)
  {
  ReverseRcurs(Temp2,Temp2->Next);
  Temp1->Next = Temp2;
  }
  else
  {
  First = Temp1;
  }
}*/

//bool LinkedList::IsLopp() -------Pozera ci je linked list loop to znamena ze posledny pointer nie je null ale ukazuje na 
//nejaky Node hocikde v linkliste
/*
{
   Node *p = First,*q = First;
   do
   {
      p = p->next;
      q = q->next;
         if(q != nullptr)
         {
            q = q->next;
         }
   }
   while(p && q && p!=q)
   if (p == q)
      return true;
    else 
       return false;

}*/

std::stack<Node*> LinkedList::Midlle()
{
    std::stack<Node*> Stack;
    Node *p = First;
    while(p)
    {
        Stack.push(p);
        p = p->Next;
    }
    int result = Stack.size() - 1 / 2;
    for(int i{};i < result;i++)
    {
        Stack.pop();
    }
    return Stack;
}