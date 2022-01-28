#include <stdio.h>
#include <stdbool.h>

unsigned int power(int n, int m){
    int w=1;
    for(int i=1;i<=m;i++){
        w *= n;
    }
    return w;
}

bool isNarcistic(int a,int b,int m){
    unsigned int s1=0,s2=0;
    int j = 0;

    while(a>0){
        s1 += (a%b)*(power(b,j));
        s2 += power(a%b,m);
        j += 1;
        a = a/b;
    }
    if(s1==s2){
        return true;
    }
    return false;
}

void print(int a,int b,int m){
    int t[m];
    if(a == 0){
        printf("%d",a);

    }
    for(int i=m-1;i>=0;i--){
        t[i] = a%b;
        a = a/b;
    }
    for(int i=0;i<m;i++){
        if(t[i]>9){
            printf("%c",t[i]-10+'A');
        }
        else{
            printf("%d",t[i]);
        }
    }
    printf(" ");
}

int main() {
    int m,b;
    int i;
    bool flag = false;
    scanf("%d %d",&m,&b);

    for(i = power(b,m-1);i<=power(b,m)-1;i++){
        if(isNarcistic(i,b,m)){
            print(i,b,m);
            flag = true;
        }
    }

    if(!flag){
        printf("NO");
    }

    return 0;
}
