#include <stdio.h>
#include <stdlib.h>

int main() {
    int N,K;
    scanf("%d %d",&N,&K);
    int* tab = (int*)calloc(N,sizeof(int));
    int sum = 0;
    for(int i=0;i<N;i++){
        scanf("%d",&tab[i]);
        sum += tab[i];
    }
    while(K>0){
        int maxidx=0;
        for(int i=0;i<N;i++){
            if(tab[i]>tab[maxidx]){
                maxidx = i;
            }
        }
        sum -= tab[maxidx]-(tab[maxidx]/2);
        tab[maxidx] = tab[maxidx]/2;
        K--;
    }
    free(tab);
    printf("%d",sum);
    return 0;
}