#include <stdio.h>
#include "math.h"
#include "stdbool.h"

#define N 10 //wielkosc statycznej tablicy

/*
 Algorytm wykorzystuje własność wynikającą z Teorii Leonharda Eulera
 */

bool isprime(unsigned int n){
    if (n==1){
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

void main(){
    unsigned int n;
    unsigned int mn, mx;
    scanf("%d %d",&mn,&mx);
    unsigned int tab[N]={0};
    int j = 0;
    int cnt=0;
    unsigned int i=1;

    while(1){
        n = (unsigned int)(pow(2,i)-1);
        if(isprime(n)){
            n *= (unsigned int)(pow(2,i-1));
            if(n>=mn && n<=mx){
                tab[j] = n;
                cnt+=1;
                j+=1;
                tab[j]=0;
            }
            else if(n>mx){
                printf("%d\n",cnt);
                for(int k=0;k<N;k++) {
                    if (tab[k] != 0) {
                        printf("%d ", tab[k]);
                    }
                }
                break;
            }
        }
        i++;
    }
}