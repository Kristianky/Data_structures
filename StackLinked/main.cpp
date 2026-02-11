#include "Stack.h"

int main()
{
    Stack<int> S1(1,5);
    std::cout<<S1.isEmpty()<<"\n";
    std::cout<<S1.isFull()<<"\n";
    S1.Push(5);
    S1.Pop();
    std::cout<<S1;
    S1.Pop();
    std::cout<<S1.isEmpty();
    return 0;

}