#ifndef _LINKEDSPARSE_H_
#define _LINKEDSPARSE_H_

#include <iostream>

struct Node
{
    Node *Next;
    int Row;
    int Data;
};

class Link
{
private:
Node *Column[10];
int SizeColumn;
int SizeRov;
public:
void Display();
};

#endif