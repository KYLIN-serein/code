#include <stdio.h>
#include <string.h>

int main(){
    int m;
    char n[1005];
    scanf("%d %s",&m,n);
    int len = strlen(n);
    int is_first = 1;
    for(int i = 0;i < len;i++){
        int val = n[i] - '0';

        if (val == 0) {
            continue;
        }

        if(is_first == 0){
            printf("+");
        }

        printf("%d*%d^%d",val,m,len-1-i);

        is_first = 0;
    }
    return 0;
}