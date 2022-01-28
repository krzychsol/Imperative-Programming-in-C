#include <malloc.h>
#include <stdio.h>
int main()
{
    int n, m, a, b, i;
    scanf("%d %d",&n,&m);
    int* red = malloc(sizeof(int)*(n+1));

    for(i=0;i<=n;i++){
        red[i]=0;
    }

    while(m--){
        scanf("%d %d",&a,&b);
        ++red[a];
        ++red[b];
    }

    for(m = 0, i = 1; i <= n; ++i) {
        m += red[i] * (n - 1 - red[i]);
    }

    int res = n*(n-1)*(n-2)/6-m/2;
    printf("%d",res);
    free(red);
}