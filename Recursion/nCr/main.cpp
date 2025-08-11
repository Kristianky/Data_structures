#include <stdio.h>

int fact (int n){
     if (n > 0){
        return fact((n -1) * n);
     }
     return 0;

    }

int nCr (int n,int r){
    int t0,t1,t2;
    t0 = fact(n);
    t1 = fact(r);
    t2 = fact(n - r);
    return t0 / (t1 * t2); 
}

int nCr_R(int n,int r) {
    if (r == 0 || r == n) {
        return 1;
    }
    return nCr_R(n - 1,r - 1) + nCr_R (n-1,r);
}