#include "Matrices.h"

int main () {
    Matrices<int> One{4};
    One.Diagonal_Triple_Set();
    One.Diagonal_Triple_Display();
    std::cout<<One.Triangel_Upper_Get (1,3);
    return 0;
}