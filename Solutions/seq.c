#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* str = malloc(sizeof(char)*51);
    scanf("%s",str);
    int len = strlen(str);

    if(len == 1){
        printf("%s",str);
        free(str);
        return 0;
    }

    int* mark = malloc(sizeof(int)*len);
    int start = len-1;
    mark[start] = 1;

    for(int i=start;i>=0;i--){
        if(str[i] >= str[start]){
            start = i;
            mark[i] = 1;
        }
    }

    for(int i=0;i<len;i++){
        if(mark[i] == 1){
            printf("%c",str[i]);
        }
    }

    free(mark);
    return 0;
}
