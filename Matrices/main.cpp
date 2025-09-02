#include "Matrices.h"

int main () {
    Matrices<int> One{4};
    One.Toeplitz_Set();
    One.Toeplitz_Display();
    std::cout<<One.Triangel_Upper_Get (1,3);
    return 0;
}