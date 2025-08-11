
#include <iostream>
#include <iomanip>

double exponetial_num(double x, double n)
{
    static double pow{1};
    static double fact{1};
    double result{};
    if (n == 0)
    {
        return 1;
    }
    else
    result = exponetial_num(x, n - 1);
    pow = pow * x;
    fact = fact * n;
    return result + pow / fact;
}

int main()
{
    double result = exponetial_num(3, 10);
    std::cout<<std::setprecision(4);
    std::cout<<result;
    return 0;
}