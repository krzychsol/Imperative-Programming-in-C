#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isSingleton(int t2[],int size,int x){
    for (int i=0;i<size;i++){
        if (t2[i] == x){
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    scanf("%d",&N);
    int **t1;
    t1 = (int **)calloc(N,sizeof(int*));
    for (int i=0;i<N;i++){
        t1[i] = (int*)calloc(N,sizeof(int));
    }

    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++) {
            scanf("%d", &t1[i][j]);
        }
    }

    int* t2=(int*)calloc(N*N,sizeof(int));
    int M=0;
    for (int i=0;i<N*N;i++){
        if (isSingleton(t2,M,t1[i / N][i % N])){
            t2[M] = t1[i / N][i % N];
            M += 1;
        }
    }
    for (int i=0;i<M;i++){
        for (int j=i+1;j<M;j++){
            if (t2[j]<t2[i]){
                int tmp = t2[j];
                t2[j] = t2[i];
                t2[i] = tmp;
            }
        }
    }

    for (int i=0;i<M;i++){
        printf("%d ",t2[i]);
    }

    free(t1);
    free(t2);
    return 0;
}
