#include <stdio.h>

int isPossible(long long int s, long long int t, char* op, long long int inst, char* ret, long long int* best){
    if(s==t){
        if (inst < *best){
            *best = inst;
            for (long long int i = 0; i < inst; ++i) {
                ret[i] = op[i];
            }
            ret[inst] = '\0';
            return 1;
        }
    }

    if(s>t || inst > *best) return 0;

    if(s>1){
        op[inst] = '*';
        isPossible(s*s, t, op, inst + 1, ret, best);
    }
    if (s>0) {
        op[inst] = '+';
        isPossible(s+s, t, op, inst + 1, ret, best);
    }

    return 0;
}

int main(){
    long long int s;
    long long int t;
    scanf("%lld %lld", &s, &t);

    char op[1000000]={0};
    char ret[1000000]={0};
    long long int best=1<<30;

    if (t == 0){
        printf("-");
        return 0;
    }
    if (t==1 && s!=0){
        if (s!=1) printf("/");
        return 0;
    }

    isPossible(s, t, op, 0, ret, &best);
    op[0] = '/';
    isPossible(1, t, op, 1, ret, &best);

    if(best == 1<<30){
        printf("NO");
        return 0;
    }

    for (int i = 0; ret[i]; ++i) {
        printf("%c", ret[i]);
    }

    return 0;
}