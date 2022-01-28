#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int max(int a, int b){
    if (a>b) return a;
    return b;
}

int maxRectangle(int* T,int n,int i,int j,int k,int l,int maxarea,int* dp,int* dp2){
    if(l != n-1){
        short flag = 0;
        if(dp2[(l*n*n)+(i*n)+k] != -1){
            flag = dp2[(l*n*n)+(i*n)+k];
        }else
            for(int o = i;o<=k;o++){
                if (T[(o*n)+l+1] != 0){
                    flag = 1;
                    break;
                }
            }
        if(flag ==0){
            dp2[(l*n*n)+(i*n)+k] = flag;
            maxarea = max(maxRectangle(T,n,i,j,k,l+1,(k-i+1)*(l+1-j+1),dp,dp2),maxarea);
        }
    }
    if(k != n-1){
        short flag = 0;
        k+=1;
        if(dp[(k*n*n)+(j*n)+l] != -1){
            flag = dp[(k*n*n)+(j*n)+l];
        }else
            for(int o = j;o<=l;o++){
                if (T[(k*n)+o] != 0){
                    flag = 1;
                    break;
                }
            }
        if(flag == 0){
            maxarea = max(maxRectangle(T,n,i,j,k,l,(k-i+1)*(l+1-j),dp,dp2),maxarea);
            dp[(k*n*n)+(j*n)+l] = flag;
        }
    }
    return maxarea;
}

int main() {
    int n;
    scanf("%d",&n);

    int *T;
    T = malloc(sizeof(int)*n*n);

    bool zeros = 0;
    bool ones = 0;
    for (int i=0;i<n*n;i++){
        scanf("%d",&T[i]);
        if(T[i] == 1){
            zeros = 1;
        }
        else{
            ones = 1;
        }
    }

    if(zeros == 0){
        free(T);
        printf("%d",n*n);
        return 0;
    }

    if(ones == 0){
        free(T);
        printf("%d",0);
        return 0;
    }

    int maxarea = 0;

    int* dp = malloc(sizeof(int) *n*n*n);
    memset(dp,-1,sizeof(int)*n*n*n);

    int* dp2 = malloc(sizeof(int) *n*n*n);
    memset(dp2,-1,sizeof(int)*n*n*n);

    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(T[(i*n)+j] != 1){
                maxarea = max(maxRectangle(T,n,i,j,i,j,1,dp,dp2),maxarea);
            }
        }
    }
    printf("%d",maxarea);

    free(T);
    free(dp);
    free(dp2);

    return 0;
}
