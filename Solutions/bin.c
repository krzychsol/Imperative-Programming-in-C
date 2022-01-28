#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int isCorrect(char* curr_cos,int curr_idx,int k, int *curr_k,int n,int last){
    if(curr_idx == n){
        (*curr_k)++;
        if (*curr_k == k){
            printf("%s",curr_cos);
            return true;
        }
        return false;
    }

    curr_cos[curr_idx] = '0';
    int a = isCorrect(curr_cos,curr_idx+1,k,curr_k,n,false);
    if(a){
        return true;
    }

    if (last == false){
        curr_cos[curr_idx] = '1';
        a = isCorrect(curr_cos,curr_idx+1,k,curr_k,n,true);
        if(a){
            return true;
        }

    }
    return false;
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);

    int cnt = 0;
    int* curr_idx = &cnt;
    char* bin = malloc(sizeof(char)*n);
    int res = isCorrect(bin,0,k,curr_idx,n,false);

    if (res == false){
        printf("-1");
    }

    free(bin);
    return(0);
}