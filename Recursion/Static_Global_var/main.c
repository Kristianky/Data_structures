#include <stdio.h>

int Copies(int n)
{
    if (n > 0)
    {
        return Copies(n - 1) + n;
    }
    return 0;
}

int Static(int n)
{
    static int y = 0;
    if (n > 0)
    {
        y++;
        return Static(n - 1) + y;
    }
    return 0;
}
int main()
{
    int x = 5;
    printf("Funcition with copied variable: ");
    printf("%d ", Copies(x));
    printf("\nFuncition with static variable: ");
    printf("%d ", Static(x));
    printf("\nFuncition with static variable: ");
    printf("%d ", Static(x));
    return 0;
}