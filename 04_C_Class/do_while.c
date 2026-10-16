#include <stdio.h>
int main(){
    int num;
    int sum = 0;

    do {
        printf("请输入一个整数（输入0结束）:");
        scanf("%d",&num);
        if (num != 0){
            sum = sum + num;
        } 
    } while (num != 0);
    printf("你输入的所有数字之和是: %d\n",sum);
    return 0;
}