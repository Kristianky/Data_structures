#include <stdio.h>

void funcB(int n);
void funcA(int n)
{
    printf("%d ", n);
    if (n > 0)
    {
        funcB(n - 1);
    }
}

void funcB(int n)
{
    printf("%d ", n);
    funcA(n / 2);
}

int main()
{
    funcA(20);
    return 0;
}