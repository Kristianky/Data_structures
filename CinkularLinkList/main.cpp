#include "CinkList.h"
#include "iostream"
int main ()
{
    List list(5);
    list.Display();
    list.AddData(6);
    list.AddData(8);
    std::cout<<"______________________\n";
    list.Display();

    return 0;
    
}