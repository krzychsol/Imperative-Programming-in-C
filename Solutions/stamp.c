#include <stdlib.h>
#include <stdio.h>

int countSum(int **T,int** P,int k,int l,int n,int i,int j,int maxsum){
    if (i+k > n || l+j > n){
        return maxsum;
    }

    int sum = 0;
    for(int x = 0;x<k;x++){
        for(int y = 0;y<l;y++){
            if(P[x][y] == 1){
                sum += T[x+i][y+j];
            }
        }
    }
    return sum;
}
int main(){
    int n,k,l;
    scanf("%d %d %d",&n,&k,&l);

    int **T = malloc(sizeof(int*)*n);
    for(int i = 0;i<n;i++){
        T[i] = malloc(sizeof(int)*n);
        for(int j = 0;j<n;j++)
            scanf("%d",&T[i][j]);
    }

    int **P = malloc(sizeof(int*)*k);
    for(int i = 0;i<k;i++){
        P[i] = malloc(sizeof(int)*l);
        for(int j = 0; j<l;j++){
            scanf("%d",&P[i][j]);
        }
    }

    int maxsum = countSum(T,P,k,l,n,0,0,0);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            int currsum = countSum(T,P,k,l,n,i,j,maxsum);
            if(currsum > maxsum){
                maxsum = currsum;
            }
        }
    }

    printf("%d",maxsum);

    free(P);
    free(T);
    return(0);
}