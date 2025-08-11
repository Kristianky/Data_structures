#include <stdio.h>

int pow(int n, int x)
{
    if (x == 0)
    {
        return 1;
    }
    else
    {
        return pow(n, x - 1) * n;
    }
}

int pow1(int n, int x)
{
    if (x == 0)
    {
        return 1;
    }
    if (x%2==0){
        return pow1(n*n,x/2);
    }
    return n* pow1(n*n,(x-1)*2);
}

int main()
{
    int result = pow(2, 4);
    printf("%d ", result);
    result = pow1(2,8);
    printf("\n");
    printf("%d ",result);
    return 0;
}