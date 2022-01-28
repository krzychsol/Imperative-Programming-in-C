#include <stdio.h>
#include "stdbool.h"
#include "math.h"

bool isprime(unsigned int n){
    if (n<=1){
        return false;
    }
    if (n==2){
        return true;
    }
    int sq = (int)((double)sqrt(n)+1);
    for(int i=2;i<=sq;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

bool isincrease(unsigned int n){
    int dig = n%10;
    int tmp;
    n = n/10;
    while (n>0){
        tmp = n%10;
        if (tmp>dig){
            return false;
        }
        dig = tmp;
        n = n/10;
    }
    return true;
}

int main() {
    unsigned int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        if(isincrease(i) && isprime(i)){
            printf("%d\n",i);
        }
    }

    return 0;
}
