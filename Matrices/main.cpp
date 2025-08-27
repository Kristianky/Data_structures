#include "Matrices.h"

int main () {
    Matrices<int> One{5};
    One.Triangel_Set();
    One.Triangel_Display();
    std::cout<<One.Triangel_Get (5,1);
    return 0;
}