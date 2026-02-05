#include "CinkList.h"
#include "iostream"
int main ()
{
    List list(5);
    list.Display();
    list.AddData(6);
    std::cout<<"______________________\n";
    list.Display();
    std::cout<<"=====================================\n";
    list.Insert(0,4);
    list.Delete(1);
    list.Insert(2,8);
    list.Display();
    std::cout<<list.Lenght()<<"\n==============================================\n";

    list.AddData(808);
    list.Display();
    return 0;
    
}