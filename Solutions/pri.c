#include <stdio.h>
#include <stdbool.h>
#include <math.h>

long sumofsquares(long n){
    long sum = 0;
    while(n>0){
        sum += (n%10)*(n%10);
        n = n/10;
    }
    return sum;
}

bool isonesqure(long n){
    if(sumofsquares(n) == 1){
        return true;
    }
    if(sumofsquares(n) == 4){
        return false;
    }
    long sum = sumofsquares(n);
    return isonesqure(sum);
}

bool isprime(long n){
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

int main() {
    long L,U,K;
    long cnt = 0;
    scanf("%d %d %d",&L,&U,&K);
    if(U-L+1<K){
        printf("%d",-1);
    }
    else{
        for(int i=L;i<=U;i++){
            if(isprime(i) && isonesqure(i)){
                cnt += 1;
                if(cnt == K){
                    printf("%d",i);
                    break;
                }
            }
        }
    }
    if(cnt < K){
        printf("%d",-1);
    }
    return 0;
}
