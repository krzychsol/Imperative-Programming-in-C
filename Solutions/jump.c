#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d",&n);
    int* t1 = malloc(n*(sizeof(int)));
    int* t2 = malloc(n*(sizeof(int)));


    for (int i = 0; i < n; i++) {
        scanf("%d %d", &t1[i], &t2[i]);
    }
    int shift = 41;
    int size = t1[n-1];
    int* tab = calloc(size + 2*shift, sizeof(int));
    for (int b = 0; b < n; b++) tab[t1[b] + shift] = t2[b];

    free(t1);
    free(t2);

    int flag = 1;
    int last = 0;

    //Faza Pierwsza
    while (flag){
        flag = 0;
        for (int j = 0; j < size + 2*shift; j ++){

            while (tab[j] >= 3){
                tab[j-2] += 1;
                tab[j] -= 3;
                tab[j+2] += 1;
                flag = 1;
            }
        }
    }
    for(int i = size + 2*shift - 1;i >= 0;i--)
    {
        if(tab[i] != 0)
        {
            last = i;
            break;
        }
    }
    //Faza druga
    last --;
    int idx = last;
    while (idx > - 1){

        if (tab[idx] > 0 && tab[idx + 1] > 0){
            tab[idx] --;
            tab[idx+1] --;
            tab[idx+2] ++;
            idx += 2;
        }

        else if (tab[idx] == 2 && tab[idx - 1] > 0) idx -= 1;

        else if (tab[idx] == 2 && tab[idx + 1] == 0){
            tab[idx - 2] += 1;
            tab[idx] -= 2;
            tab[idx+1] += 1;
            idx += 1;
        }

        else if (tab[idx] == 3){
            tab[idx-2] += 1;
            tab[idx] -= 3;
            tab[idx+2] += 1;
            idx += 2;
        }
        else idx --;
    }
    for (int c = 0; c < size + 2*shift; c++){
        if (tab[c] != 0) printf("%d ",c - shift);
    }

    free(tab);
    return 0;
}

