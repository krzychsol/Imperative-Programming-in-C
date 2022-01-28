#include <stdio.h>
#include <stdlib.h>

#define max(A,B) ((A) > (B) ? (A) : (B))

int count(int **T,int n,int k,int i,int j){
    int res = 0;
    int tmp_res = 0;

    //right
    for(int l=0;l<k;l++){
        res += T[i][(j+l+n)%n];
    }

    //down
    for(int l=0;l<k;l++){
        tmp_res += T[(i+l+n)%n][j];
    }
    res = max(res,tmp_res);

    //right-down
    tmp_res = 0;
    for(int l=0;l<k;l++){
        tmp_res += T[(i+l+n)%n][(j+l+n)%n];
    }
    res = max(res,tmp_res);

    //left-down
    tmp_res = 0;
    for(int l=0;l<k;l++){
        tmp_res += T[(i+l+n)%n][(j-l+n)%n];
    }
    res = max(res,tmp_res);

    //right-up
    tmp_res = 0;
    for(int l=0;l<k;l++){
        tmp_res += T[(i-l+n)%n][(j+l+n)%n];
    }
    res = max(res,tmp_res);

    //up
    tmp_res = 0;
    for(int l=0;l<k;l++){
        tmp_res += T[(i-l+n)%n][j];
    }
    res = max(res,tmp_res);

    //left-up
    tmp_res = 0;
    for(int l=0;l<k;l++){
        tmp_res += T[(i-l+n)%n][(j-l+n)%n];
    }
    res = max(res,tmp_res);

    //left
    tmp_res = 0;
    for(int l=0;l<k;l++){
        tmp_res += T[i][(j-l+n)%n];
    }
    res = max(res,tmp_res);

    return res;
}

int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    int **T = malloc(sizeof(int*) * n);
    for(int i=0;i<n;i++){
        T[i] = malloc(sizeof(int)*n);
        for(int j=0;j<n;j++){
            scanf("%d",&T[i][j]);
        }
    }

    int maxcnt = count(T,n,k,0,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            maxcnt = max(maxcnt,count(T,n,k,i,j));
        }
    }

    printf("%d",maxcnt);
    for(int i = 0;i<n;i++)
        free(T[i]);
    free(T);

    return 0;
}
