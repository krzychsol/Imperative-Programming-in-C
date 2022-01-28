#include <stdio.h>
#include <stdlib.h>

int is_sole(int* r, int* g, int* b, int i){
    if ((r[i] == 0 && g[i] == 0 && b[i] >= 1) || (r[i] == 0 && g[i] >= 1 && b[i] == 0) || (r[i] >= 1 && g[i] == 0 && b[i] == 0))
        return 1;
    return 0;
}

int get_max(int* R, int* G, int* B, int n){
    int m = -1;
    int * col;
    int ret_col;
    for (int i = 0; i < n; ++i) {
        if (!is_sole(R, G, B, i)){
            if (m == -1 || R[i] > col[m]) {col = R; m=i;}
            if (m == -1 || G[i] > col[m]) {col = G; m=i;}
            if (m == -1 || B[i] > col[m]) {col = B; m=i;}
        }
    }
    if (col==R) ret_col=0;
    if (col==G) ret_col=1;
    if (col==B) ret_col=2;

    return 10*m + ret_col;
}

int get_best(int* r, int* g, int* b, int colour, int n, int M, int second){
    int m = -1;
    int m_val;
    for (int i = 0; i < n; ++i) {
        if (i == M || i == second) continue;
        if (colour == 0) {
            if (m == -1 || g[i] + b[i] < m_val) {m = i; m_val=g[i]+b[i];}
        }
        if (colour == 1){
            if (m == -1 || r[i] + b[i] < m_val) {m = i; m_val=r[i]+b[i];}
        }
        if (colour == 2){
            if (m == -1 || r[i] + g[i] < m_val) {m = i; m_val=r[i]+g[i];}
        }
    }

    return m;
}

int should_end(int* R, int* G, int* B, int n){
    for (int i = 0; i < n; ++i) {
        if (!is_sole(R, G, B, i)) return 0;
    }
    return 1;
}

int main(){
    int n;
    scanf("%d", &n);

    int* R = calloc(n, sizeof(int));
    int* G = calloc(n, sizeof(int));
    int* B = calloc(n, sizeof(int));
    int isred, isblue, isgreen;

    for (int i = 0; i < n; ++i) {
        scanf("%d", &R[i]);
        if(R[i] > 0) isred=1;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &G[i]);
        if(G[i] > 0) isgreen=1;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &B[i]);
        if(B[i] > 0) isblue=1;
    }

    if(n < isblue+isred+isgreen) {printf("-1"); return 0;}

    int m, c, steps=0;
    int n_red, n_blue, n_green;

    while (!should_end(R, G, B, n)){
        m = get_max(R, G, B, n);
        c = m%10;
        m/=10;

        if (c==0) {
            n_green = get_best(R, G, B, 1, n, m, m);
            n_blue = get_best(R, G, B, 2, n, m, m);
            if (n_green == n_blue){
                if (G[n_blue] + R[n_blue] < R[n_green] + B[n_green]){
                    n_green = get_best(R, G, B, 1, n, m, n_blue);
                }
                else{
                    n_blue = get_best(R, G, B, 2, n, m, n_green);
                }
            }

            G[n_green] += G[m];
            steps += G[m];
            G[m] = 0;
            B[n_blue] += B[m];
            steps += B[m];
            B[m] = 0;
            continue;
        }
        if (c==1) {
            n_red = get_best(R, G, B, 0, n, m, m);
            n_blue = get_best(B, R, G, n, 2, m, m);
            if (n_red == n_blue){
                if(B[n_red] + G[n_red] < R[n_blue] + G[n_blue]){
                    n_blue = get_best(R, G, B, 2, n, m, n_red);
                }
                else{
                    n_red = get_best(R, G, B, 0, n, m, n_blue);
                }
            }

            R[n_red] += R[m];
            steps += R[m];
            R[m] = 0;
            B[n_blue] += B[m];
            steps += B[m];
            B[m] = 0;
            continue;
        }
        if (c==2){
            n_red = get_best(R, G, B, 0, n, m, m);
            n_green = get_best(G, R, B, 1, n, m, m);
            if (n_red == n_green){
                if (G[n_red] + B[n_red] < R[n_green] + B[n_green]){
                    n_green = get_best(R, G, B, 1, n, m, n_red);
                }
                else{
                    n_red = get_best(R, G, B, 0, n, m, n_green);
                }

            }

            R[n_red] += R[m];
            steps += R[m];
            R[m] = 0;
            G[n_green] += G[m];
            steps += G[m];
            G[m] = 0;
            continue;
        }

    }

    printf("%d", steps);

}

