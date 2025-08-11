#include <iostream>
#include "Array.h"

int main()
{
    Array<int> arr1(8,0);
    std::cout<<arr1.Get_Size()<<std::endl;
    arr1.Fill_Data(5);
    arr1.delete_element(4);
    std::cout<<arr1.Finding_Missing_Element();
    return 0;
}

