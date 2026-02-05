#include "Double.h"

int main() 
{
    Double<int> One;
    One << 5;
    std::cout<<One<<"\n";
    One[0] = 4;
    std::cout<<One<<"\n";
    One[2]--;
    std::cout<<One;
    return 0;
}
