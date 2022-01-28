#include <stdio.h>

int main() {
    unsigned int n;
    unsigned int a=0;
    unsigned int b=1;
    scanf("%d",&n);

    unsigned int c=0;
    while (a*b <= n){
        if (a*b == n){
            printf("YES");
            break;
        }
        c = a+b;
        a = b;
        b = c;
    }
    if (a*b > n){
        printf("NO");
    }
    return 0;
}
