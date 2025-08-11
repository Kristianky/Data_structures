#include <iostream>

int func_For(int x, int n)
{
    int s{1};
    for (n; n > 0; n--)
    {
        s = 1 + x / n * s;
    }
    return s;
}

int func_recursion(int x, int n)
{
    static int s{1};
    if (n == 0)
    {
        return s;
    }
    s = 1 + x / n * s;
    return func_recursion(x, n - 1);
}

int main()
{
    std::cout << func_For(4, 3) << "\n";
    std::cout << func_recursion(4, 3) << "\n";
    return 0;
}