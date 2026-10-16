#include <stdio.h>
int main() {
    int arr[5];

    printf("请输入 5 个整数（按回车分隔）:");

    for (int i = 0;i < 5; i++){
        scanf("%d",&arr[i]);
    }

    printf("你刚才输入的数字是: ");
    for(int i = 0;i < 5 ;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

int max_val = arr[0];
for(int num = 1;num < 5; num++) {
    if(arr[num] > max_val) {
        max_val = arr[num];
    }
}
printf("最大值为：%d\n",max_val);

    return 0;
}