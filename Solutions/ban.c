#include <stdio.h>
#define SIZE 100
#define MAXLEN 33

void increment(int a[], int bit){
    while (a[bit] == 1) {
        a[bit] = 0;
        bit += 1;
    }
    a[bit] = 1;
}

void decrement(int a[], int bit){
    a[bit] = 0;
}

int decDivMod2(char a[], int len){
    int c = 0;
    for (int i = 0; i < len; i++){
        c = (c % 2) * 10 + a[i];
        a[i] = c / 2;
    }
    return c % 2;
}

int main(){
    int n[SIZE + 1] = {0};
    char k[MAXLEN + 1] = {0};
    fgets(k, MAXLEN, stdin);
    int len = 0;
    while (k[len] != 10){
        k[len] -= 48;
        len++;
    }

    int bit = 0;
    while (bit < SIZE){
        n[bit++] = decDivMod2(k, len);
    }

    int pos = 1;
    for (int a = 0; a < 2; a++){
        int t[SIZE + 1];
        for (int i = 0; i < SIZE + 1; i++) t[i] = n[i];
        int get[SIZE] = {0};

        for (int bit = 0; bit < SIZE; bit++){
            if (t[bit]) {
                get[bit] = 1;
                if (pos) decrement(t, bit);
                else increment(t, bit);
            }
            pos = !pos;
        }
        if (t[SIZE]) puts("NO");
        else {
            for (int i = 0; i < SIZE; i++) if (get[i]) printf("%d ", i);
            puts("");
        }
        pos = 0;
    }
}