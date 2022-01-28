#include <stdio.h>
#include <stdbool.h>

bool canweight(int *tab,int w,int p,int n){
    if (w==0){
        return true;
    }
    if (p == n){
        return false;
    }
    return canweight(tab,w-tab[p],p+1,n) || canweight(tab,w,p+1,n) || canweight(tab,w+tab[p],p+1,n);
}

int main() {
    int n,w;
    int sum = 0;
    scanf("%d %d",&n,&w);
    int tab[n];
    for(int i=0;i<n;i++){
        scanf("%d",&tab[i]);
        sum += tab[i];
    }
    if(sum < w){
        printf("NO");
    }
    else if(sum == w){
        printf("YES");
    }
    else if(canweight(tab,w,0,n)){
        printf("YES");
    }
    else printf("NO");

    return 0;
}
