#include prime_num.h

int prime_num(int n){
    int c=0;
    for (int i=2;i<n;i++){
        for (int j=2;j*j<=i;j++){
            if(i%j!=0){c=c+1;}
        }
    }
    return c;
}

int eff_prime_num(int n){
    int *not_prime=malloc(n*4);
    int k=0;
    for(int i=2;i<n;i++){
        if(search(not_prime,k,i))=false{
            for(int j=2;j*j<=i;j++){
                if(i%j!=0){c=c+1;}
            }
            for(int a=2;i*a<=n;a++){
                *(not_prime+k)=i*a;
                k=k+1;
            }
        }
    }
    return c;
}

bool search(int *ptr,int height,int value){
    for(int x=0;x<height;x++){
        if(*(ptr+x)==value){return true;}
    }
}