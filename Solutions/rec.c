#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define pt points[i]

struct point{
    int x1,y1,x2,y2;
};

void swap(int *p1, int *p2) {
    int* tmp = p1;
    p1 = p2;
    p2 = tmp;
}

void fillarray(struct point *point,int* T){
    if(point->x1 > point->x2) swap(&point->x1,&point->x2);
    if(point->y1 > point->y2) swap(&point->y1,&point->y2);
    for(int i=point->x1;i<point->x2;i++){
        for(int j=point->y1;j<point->y2;j++){
            T[((i+100)*201)+(j+100)] = abs(-1+ T[((i+100)*201)+(j+100)]);
        }
    }
}

int main() {
    int N;
    scanf("%d",&N);
    struct point* points = malloc(sizeof(struct point)*N);
    for(int i=0;i<N;i++){
        scanf("%d %d %d %d",&pt.x1,&pt.y1,&pt.x2,&pt.y2);
    }

    int *T = malloc(sizeof(int)*201*201);
    memset(T,0,sizeof(int));
    for(int i=0;i<N;i++){
        fillarray(&pt,T);
    }

    int cnt = 0;
    for(int i=0;i<201*201;i++){
        if(T[i]==1){
            cnt += 1;
        }
    }

    printf("%d",cnt);
    free(T);
    free(points);

    return 0;
}
