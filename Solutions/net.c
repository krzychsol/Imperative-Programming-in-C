#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int diff(char *s1,char *s2,int n){
    int res1 = 0;
    int res2 = 0;
    int p = 0;
    for(int i = n-1;i>=0;i--){
        if(s1[i] == '1'){
            res1 += (int)pow(2,p);
        }
        if(s2[i] == '1'){
            res2 += (int)pow(2,p);
        }
        p++;
    }
    return res2-res1+1;
}

void increment(int **We,int n){
    We[n-1][0] +=1 ;
    int carry = We[n-1][0]/2;
    We[n-1][0] = We[n-1][0]%2;

    for(int i=n-2;i>=0;i--){
        if(carry == 1){
            We[i][0] +=1;
            carry = We[i][0]/2;
            We[i][0] = We[i][0] % 2;
        }
    }
}

int obliczBramke(int **Br,int **We,int nr){
    int left,right;
    if(Br[nr][0] < 0){
        if(We[abs(Br[nr][0])][0] == 1){
            left = 1;
        } else left = 0;
    }
    else{
        left = obliczBramke(Br,We,Br[nr][0]);
    }
    if(Br[nr][1] < 0){
        if(We[abs(Br[nr][1])][0] == 1){
            right = 1;
        } else right = 0;
    }
    else{
        right = obliczBramke(Br,We,Br[nr][1]);
    }
    return (left+right)%2;
}

int main() {
    int n,m,last;
    scanf("%d %d %d",&n,&m,&last);

    int **Bramki = malloc(sizeof(int*)*(m+1));
    int **Wejscia = malloc((sizeof(int*))*(n+1));

    for(int i=0;i<(m+1);i++){
        Bramki[i] =  malloc(sizeof(int)*4);
        Bramki[i][3] = 0;
        Bramki[i][2] = 0;
    }
    Bramki[0][0] = 0;

    for(int i=0;i<(n+1);i++){
        Wejscia[i] =  malloc(sizeof(int)*2);
        Wejscia[i][1] = 1;
    }
    Wejscia[0][0]=0;
    for(int i=1;i<m+1;i++){
        scanf("%d %d",&Bramki[i][0],&Bramki[i][1]);
    }

    char *s1 = malloc(sizeof(char)*n+1); //low
    char *s2 = malloc(sizeof(char)*n+1); //high
    scanf("%s",s1);
    scanf("%s",s2);

    for(int i=1;i<n+1;i++){
        Wejscia[i][0] = s1[i-1]-'0';
    }

    int range = diff(s1,s2,n);
    int cnt = 0;
    for(int i=0;i<range;i++){
        cnt += obliczBramke(Bramki,Wejscia,last);
        increment(Wejscia,n+1);
    }
    printf("%d",cnt);
    for(int i=0;i<m+1;i++){
        free(Bramki[i]);
    }
    for(int i=0;i<n+1;i++){
        free(Wejscia[i]);
    }
    free(s1);
    free(s2);
    return 0;
}
