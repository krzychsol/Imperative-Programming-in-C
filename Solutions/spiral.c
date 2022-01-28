#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d",&n);
    int **T;
    T = (int **)calloc(n,sizeof(int*));
    for (int i=0;i<n;i++){
        T[i] = (int*)calloc(n,sizeof(int));
    }

    int left = 0;
    int right = n-1;
    int cnt = 1;
    while (left < right){
        for(int i = left;i < right;i++){
            T[left][i] = cnt;
            cnt++;
        }
        for(int i = left;i < right;i++){
            T[i][right] = cnt;
            cnt++;
        }
        for(int i = right;i > left;i--){
            T[right][i] = cnt;
            cnt++;
        }
        for(int i = right;i > left;i--){
            T[i][left] = cnt;
            cnt++;
        }
        left++;
        right--;
    }

    if(n%2 == 1){
        T[n/2][n/2] = cnt;
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++) {
            printf("%d ", T[i][j]);
        }
        printf("\n");
    }

    free(T);

    return 0;
}
