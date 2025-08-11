#include <stdio.h>

int factiorial(int n)
{
    if (n > 0)
    {
        return factiorial(n - 1) * n;
    }
    return 1;
}

int main () {
    int a{0};
    a = factiorial(10);
    printf ("%d ",a);
    return 0;
}