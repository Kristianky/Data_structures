#include "Stack.h"

int main()
{
    Stack<char> S1(10);
    std::cout<<S1.ParenthisisMatch("{[1+2]-(2+1)");
    return 0;


}