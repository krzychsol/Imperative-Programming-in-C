#include <stdlib.h>
#include <stdio.h>

int numofdigits(long long int i){
    int len = 0;
    while(i != 0){
        i/=10;
        len+=1;
    }
    return len;
}

int main(){
    long long int S = 0;
    scanf("%lld",&S);
    int len = numofdigits(S);

    int i = 1;
    long long int pom= 1;
    while (i < len){
        pom *= 10;
        pom ++;
        i++;
    }

    int* N = malloc(sizeof(int)*len);
    for(i=0;i<len;i++){
        N[i]=0;
    }

    int flag = 0;
    for (i = 0; i< len; i++){
        while (S-pom >= 0){
            S -= pom;
            N[i]++;
            if(N[i] > 9){
                printf("-1");
                flag = 1;
                break;
            }
        }
        pom/=10;
    }

    if(!flag){
        int isFirst=0;
        while(N[isFirst] == 0){
            isFirst++;
        }
        for(i=isFirst;i<len;i++){
            printf("%d",N[i]);
        }
    }

    free(N);
}