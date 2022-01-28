#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int main(){
    int N, G;
    scanf("%d%d", &N, &G);
    int i;
    int* T;
    T = malloc(sizeof(int)*N);
    for (i=0; i<N; i++){
        scanf("%d", &T[i]);
    }

    int x = G, y=0;
    while (x!=0){
        x = x/2;
        y += 1;
    }
    int* A;
    int* B;
    A = malloc(sizeof(int)*y);
    B = malloc(sizeof(int)*y);
    for (i=0;i<y;i++){
        A[y-1-i] = G % 2;
        G /= 2;
    }
    for (i=0;i<y;i++){
        B[y-1-i] = 0;
    }
    int j, pause;
    for (i=0;i<N;i++){
        if (T[i]/pow(2,y) > 1){
            continue;
        }
        pause=0;
        x = T[i];
        for (j = 0; j<y; j++){
            if (A[y-1-j] == 0 && x % 2 == 1){
                pause = 1;
                break;
            }
            x /= 2;
        }
        if (pause) continue;
        for(j=0; j<y;j++){
            B[y-1-j] += T[i] % 2;
            T[i] /= 2;
        }
    }
    int min = INT_MAX;
    for (i=0; i<y; i++){
        if (A[i] == 0){
            if (min>(N - B[i])){
                min = N - B[i];
            }
        }
        else{
            if (min>B[i]){
                min = B[i];
            }
        }
    }
    printf("%d", min);
    free(T);
    free(A);
    free(B);
}

