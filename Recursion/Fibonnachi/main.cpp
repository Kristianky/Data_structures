#include <stdio.h>

int F[10]; //for memorozition

int fib_forloop (int n){
    int t0{},t1{1},s{},i;
    if (n <= 1){
        return n;
    }
    for (i = 2;i <= n;i++){
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}
int fib_func (int n){
    if (n <= 1){
        return n;
    }

    return fib_func(n - 2) + fib_func (n - 1);
}

int fib_M(int n){
    if (n <= 1){
        F[n] = n;
        return n;
    }
  
    else {
        if (F[n - 2 == -1]){
            F[n-2]=fib_M(n - 2);
        }
        if (F[n-1]==-1){
            F[n-1] = fib_M(n-1);
        }
        return F[n-2] + F[n-1];

    }
}
int main () {
      for (auto &c:F){
        c = -1;
    }
    printf ("%d \n",fib_forloop(6));
    printf ("%d \n",fib_func(6));
    printf("%d ",fib_M(6));
    return 0;
}