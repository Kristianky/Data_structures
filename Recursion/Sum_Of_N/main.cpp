#include <stdio.h>

int sum (int n) {
    if (n == 0){
        return 0;
    }
    int result;
    return result =  sum (n-1) + n;
}

int Isum (int n){           //Iterative function
    int result {};
    for (int i{1};i <= n;i++){
        result = result + i;
    }
    return result;
}
int main () {
    int r;
    int a = Isum(5);
    r = sum (5);
    printf ("%d ",r);
    printf ("\n");
    printf ("%d ",a);
    return 0;
}