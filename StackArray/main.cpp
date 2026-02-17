#include "Stack.h"

int main()
{
    Stack<char> S1(10);
    std::cout<<S1.ParenthisisMatch("{[1 + 2]-(2 + 1)")<<"\n";
    std::cout<<S1.InfixToPostfix("1*(2+8-7)+1^6^5")<<"\n";
    std::cout<<S1.PostfixToResult("59-");
    return 0;

}