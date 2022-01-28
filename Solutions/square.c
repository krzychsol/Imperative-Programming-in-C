#include <stdio.h>
#include <stdlib.h>

void print(int* cols,int* rows, int idx){
    printf("%d\n",idx);
    for (int i = 0; i < idx;i ++){
        printf("%d %d\n",cols[i],rows[i]);
    }

}

int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    int *T;
    T = malloc(sizeof(int)*n*n);
    for (int i=0;i<n*n;i++){
        scanf("%d",&T[i]);
    }

    int* rows = malloc(sizeof(int)*n*n);
    int* cols = malloc(sizeof(int)*n*n);
    int idx = 0;

    for(int i=1;i<n-1;i++) {
        for (int j = 1; j < n - 1; j++) {
            for (int l = 1;; l++) {
                if (i + l >= n || j + l >= n || i - l < 0 || j - l < 0)
                    break;
                int sum = 0;
                for (int p = i - l; p <= i + l; p++) {
                    sum += T[(p * n) + (j - l)];
                    sum += T[(p * n) + (j + l)];
                }
                for (int p = j - l + 1; p <= j + l - 1; p++) {
                    sum += T[((i - l) * n) + (p)];
                    sum += T[((i + l) * n) + (p)];
                }
                if (sum == k) {
                    cols[idx] = i;
                    rows[idx] = j;
                    idx++;
                }
            }
        }
    }
    print(cols,rows,idx);
    free(T);
    free(rows);
    free(cols);

    return 0;
}
