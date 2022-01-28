#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int n){
    if( n < 2 ) return false;
    if(n == 2 ) return true;
    if(n % 2 == 0)return false;
    for(int i=3;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}

int main() {
    char* s = malloc(sizeof(char)*50);
    scanf("%s",s);
    int n = strlen(s);
    int o;
    int p;
    char* mins = malloc(sizeof(char)*n);
    for(int i=0;i<n;i++){
        mins[i] = s[i];
    }

    char* t = malloc(sizeof(char)*n);
    int x;
    int idx;
    for(o=0;o<n;o++){
        for(p = 2;p < n;p++) {
            x = 0;
            idx = 0;
            if(isPrime(p)){
                while(x<n){
                    t[idx] = s[(o+x*p)%n];
                    x++;
                    idx++;
                }
                if(strcmp(t,mins)<0){
                    for(int i=0;i<n;i++){
                        mins[i] = t[i];
                    }
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        printf("%c",mins[i]);
    }
    free(s);
    free(mins);
    free(t);
    return 0;
}
