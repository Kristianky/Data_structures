#include <stdio.h>

void func_Tail(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        func1(n - 1);
    }
}
void func_Head(int n)
{
    if (n > 0)
    {
        func1(n - 1);
        printf("%d ", n);
        }
}

int main()
{
    int x = 3;
    // func_Tail(x);
    func_Head(x);
    return 0;
}