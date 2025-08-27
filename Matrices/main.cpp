#include "Matrices.h"

int main () {
    Matrices<int> One{5};
    One.set_diagonal();
    One.Display_Diagonal();
    std::cout<<One.get_single_diagonal(4,4);

}