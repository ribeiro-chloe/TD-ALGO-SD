#include fibo.h

//Fibonacci
//1
int fibonacci1(int n){
    if (n==0 || n==1){return n;}
    else{return fibonacci1(n-1)+ fibonacci1(n-2);}
}

//2
int fibonacci2(int n,int DPFib[n+1]){
    if(n<=1){return n;}
    if (DPFib[n]!=-1){return DPFib[n];}
    DPFib[n]=fibonacci2(n-1,DPFib)+fibonacci2(n-2,DPFib);
    return DPFib[n];
}

int a=10;
int DPFib[11];
