#include <stdio.h>
#include <stdlib.h>

int d(int i,int j,int k,int l){
    int d1,d2;
    d1 = abs(i-k);
    d2 = abs(j-l);
    if (d1>d2){
        return d1;
    }
    return d2;
}

int main() {
    int n,r;
    scanf("%d %d",&n,&r);
    int **F;
    F = (int **)calloc(n,sizeof(int*));
    for (int i=0;i<n;i++){
        F[i] = (int*)calloc(n,sizeof(int));
    }

    int **W;
    W = (int **)calloc(n,sizeof(int*));
    for (int i=0;i<n;i++){
        W[i] = (int*)calloc(n,sizeof(int));
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++) {
            scanf("%d", &F[i][j]);
            W[i][j] = 0;
        }
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            for (int k=0;k<n;k++){
                for (int l=0;l<n;l++){
                    if(d(i,j,k,l) <= r){
                        if (F[k][l] == 1){
                            W[i][j] += 1;
                        }
                    }
                }
            }
        }
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++) {
            printf("%d ",W[i][j]);
        }
        printf("\n");
    }
    free(F);
    free(W);
    return 0;
}
