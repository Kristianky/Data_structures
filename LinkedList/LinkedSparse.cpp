#include "LinkedSparse.h"

void Link::Display()
{
    for(int i{};i < SizeColumn;i++)
    {
        Node *p = Column[i];
        for(int j{};j < SizeRov;j++)
        {
            if(j == p->Row)
            {
                std::cout<<p->Data;
                p->Next;
            }
            else 
            {
                std::cout<<0;
            }
        }
        std::cout<<"\n";
    }
}