#include <stdio.h>

int main() {
    int N;
    scanf("%d",&N);

    int j;
    long long int sum=0;
    for(int i=1;i<=N;i+=2){
        j = i;
        while(j <= N){
            sum += i;
            j *= 2;
        }
    }
    printf("%lld",sum);
    return 0;
}
