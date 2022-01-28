#include <stdio.h>

int main(){
    int n, m;
    scanf("%d %d", &n,&m);
    if(m==1){
        printf("%d",0);
        return 0;
    }
    int i=0;
    int cnt = 0;
    int x = 1;
    int a;
    for (a=0; a < n; a++){
        if ((i+x) % m == 0){
            cnt += 1;
            break;
        }
        x *= 2;
    }

    int maxi = 1<<n;
    for (i=1; i<maxi; i++){
        int j;
        if (i % m != 0){
            x = 1;
            int temp = i;
            for (j=0; j < n; j++){
                if (temp % 2 == 0){
                    if ((i+x) % m == 0){
                        cnt += 1;
                        break;
                    }
                }
                else{
                    if ((i-x) % m == 0){
                        if (i-x > 0){
                            cnt += 1;
                            break;
                        }
                    }
                }
                temp /= 2;
                x *= 2;
            }
        }
    }
    printf("%d", cnt);
}