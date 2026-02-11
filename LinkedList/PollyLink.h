#ifndef _POLLYLINK_H_
#define _POLLYLINK_H_

struct Node
{
    Node *Next;
    int Expo;
    int Coef;
};

class Link
{
private:
    Node *First;

public:
void Polly(int X);
};

#endif