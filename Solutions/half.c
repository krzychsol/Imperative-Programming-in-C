#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d",&n);
    int *tab = (int*)malloc(n*sizeof(int));
    int sum=0;
    for(int i=0;i<n;i++){
        scanf("%d",&tab[i]);
        sum += tab[i];
    }

    int lsum = 0;
    int rsum = sum-tab[0];
    for(int i=0;i<n;i++){
        if (lsum == rsum){
            printf("%d",i);
            break;
        }
        lsum+=tab[i];
        rsum-=tab[i+1];
    }
    free(tab);

    return 0;
}
