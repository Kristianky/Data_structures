#ifndef _MATRICES_H_
#define _MATRICES_H_

/*                             x
Diagonal Tabulka vzyera nejak takto:    1.   1 0 0 0
                                        2.   0 2 0 0
                                        3.   0 0 3 0
                                        4.   0 0 0 4
                                           y 1.2.3.4.
Potom mame TriangelLower: x 
                          1.  x  0  0  0
                          2.  x  x  0  0
                          3.  x  x  x  0
                          4.  x  x  x  x
                            y 1. 2. 3. 4.*/

#include <iostream>
template <class T>
class Matrices
{
private:
    T *Diagonal_Matrix; // Je to dvojrozmerna matrica ktora ma data len v suradniciach i==j v ostatnzch ma 0
    int Size_Diagonal;  // Ale vieme urobit syntax aby sme usetrili pamat tak aby pouzila len klasicku array
    T *Lower_Triangel_Matrix;
    int Lower_Triangel_Size;
public:
    Matrices(int n);
    ~Matrices() {delete[] Diagonal_Matrix;delete[] Lower_Triangel_Matrix;}
    void set_diagonal();
    int get_single_diagonal(int x, int y);
    void Display_Diagonal();
    void Triangel_Set();
    int Triangel_Get(int x,int y);
    void Triangel_Display();
};
template<class T>
Matrices<T>::Matrices(int n){
        Diagonal_Matrix = new T[n];
        Size_Diagonal = n;
        Lower_Triangel_Size = 0;
        for (int i{};i < n + 1;i++){
            Lower_Triangel_Size = Lower_Triangel_Size + i;
        }
        Lower_Triangel_Matrix = new T[Lower_Triangel_Size];
    }
template <class T>
void Matrices<T>::set_diagonal()
{
    T x;
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
        return Diagonal_Matrix[x - 1];
    }
    return 0;
}
template <class T>
void Matrices<T>::Display_Diagonal()
{
    for (int x{1}; x < Size_Diagonal + 1; x++)
    {
        for (int y{1}; y < Size_Diagonal + 1; y++)
        {
            if (x == y)
            {
                std::cout << Diagonal_Matrix[y-1];
            }
            else
                std::cout << "0";
        }
        std::cout<<std::endl;
    }
}
template<class T>
void Matrices<T>::Triangel_Set(){
    int n = 0;
    for (int i{};i < Lower_Triangel_Size;i++){
        std::cin>>n;
        Lower_Triangel_Matrix[i] = n;
    }
}
template<class T>
void Matrices<T>::Triangel_Display(){
    for(int i{};i < Lower_Triangel_Size;i++){
        for(int j{};j<Lower_Triangel_Size;j++){
            if (i >= j){
                std::cout<< Lower_Triangel_Matrix[j];
            }
            else
                std::cout<<0;
        }
        std::cout<<std::endl;
    }
}
template<class T>
int Matrices<T>::Triangel_Get(int x,int y){
    if (x >= y){
        return Lower_Triangel_Matrix[((x*(x - 1))/2) + y -1];
    }
    else 
    return 0;
}
#endif