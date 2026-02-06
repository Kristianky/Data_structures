#include "PollyLink.h"

void Link::Polly(int X)
{
    Node *p = First;
    int result{};
    while(p)
    {
        int pow{1};
        for(int i{};i < p->Expo;i++)
        {
            pow *= X;
        }
        result += p->Coef * pow;
        p = p->Next;
    }
}