#ifndef _MATRICES_H_
#define _MATRICES_H_

/*                             x
Tabulka vzyera nejak takto:    1.   1 0 0 0
                               2.   0 2 0 0
                               3.   0 0 3 0
                               4.   0 0 0 4
                                  y 1.2.3.4.*/

#include <iostream>
template <class T>
class Matrices
{
private:
    T *Diagonal_Matrix; // Je to dvojrozmerna matrica ktora ma data len v suradniciach i==j v ostatnzch ma 0
    int Size_Diagonal;  // Ale vieme urobit syntax aby sme usetrili pamat tak aby pouzila len klasicku array
public:
    Matrices(int n)
    {
        Diagonal_Matrix = new T[n];
        Size_Diagonal = n;
    }
    ~Matrices();
    void set_diagonal(T x);
    int get_single_diagonal(int x, int y);
    void Display_Diagonal();
};

template <class T>
void Matrices<T>::set_diagonal(T x)
{
    for (int i{}; i < Size_Diagonal; i++)
    {
        std::cin >> x;
        Diagonal_Matrix[i] = x;
    }
}
template <class T>
int Matrices<T>::get_single_diagonal(int x, int y)
{
    if (x == y)
    {
        return Diagonal_Matrix[x];
    }
    return 0;
}
template <class T>
void Matrices<T>::Display_Diagonal()
{
    for (int x{}; x < Size_Diagonal; x++)
    {
        for (int y{}; y < Size_Diagonal; y++)
        {
            if (x == y)
            {
                std::cout << Diagonal_Matrix[y];
            }
            else
                std::cout << "0";
        }
    }
}
#endif