#include "List.h"

int main()
{
    List<int> One;
    One<<5;
    One<<8;
    std::cout<<One;
    One[1] = 2;
    std::cout<<One;
    One[1]--;
    std::cout<<One;
    return 0;

}