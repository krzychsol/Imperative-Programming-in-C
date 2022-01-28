#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int partition(int tab[],int n,int p,int r){
    int i = p-1;
    int pivot = tab[r];
    int tmp;
    for(int j=p;j<r;j++){
        if(tab[j]<=pivot){
            i++;
            tmp = tab[i];
            tab[i] = tab[j];
            tab[j] = tmp;
        }
    }
    tmp = tab[i+1];
    tab[i+1] = tab[r];
    tab[r] = tmp;
    return i+1;
}

void quicksort(int tab[],int n,int p,int r){
    while(p<r){
        int q = partition(tab,n,p,r);
        if(q-p<r-q){
            quicksort(tab,n,p,q-1);
            p = q+1;
        }
        else{
            quicksort(tab,n,q+1,r);
            r = q-1;
        }
    }
}

bool havepair(int tab[],int N,int K,int x){
    int j;
    for(j=0;j<N;j++){
        if(tab[j] != x && abs(tab[j]-x)<=K){
            return true;
        }
    }
    return false;
}

int counter(int tab[],int N,int i){
    int cnt = 1;
    while(i<N-1 && tab[i+1]==tab[i]){
        cnt++;
        i++;
    }
    return cnt;
}

int main() {
    int N,K;
    scanf("%d %d",&N,&K);
    int* tab=(int*)calloc(N,sizeof(int));

    for(int i=0;i<N;i++){
        scanf("%d",&tab[i]);
    }

    quicksort(tab,N,0,N-1);
    int cnt = 0;
    int i=0;
    while(i<N){
        if(havepair(tab,N,K,tab[i])){
            cnt += counter(tab,N,i);
            i += counter(tab,N,i);
        }
        else{
            i++;
        }
    }
    free(tab);
    printf("%d",cnt);
    return 0;
}