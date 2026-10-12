#include <stdio.h>

int main(){
    int num = 0;

    printf("请输入一个整数：");
    scanf("%d",&num);

    if(num > 0) {
        printf("这是一个正数\n");
    } else if(num < 0){
        printf("这个数是一个负数\n");
    } else {
        printf("这个数是零\n");
    }

    return 0;
}