#include <stdio.h>
int main() {
   int arr[5];

  printf("请输入5个整数: ");

    for(int i = 0;i < 5;i++){
        scanf("%d",&arr[i]);
    }

for(int i = 0; i < 5/2; i++){
    int temp = arr[i];
    arr[i] = arr[4-i];
    arr[4-i] = temp;
}

printf("反转后的结果是: ");

for(int i = 0; i < 5; i++){
    printf("%d ",arr[i]);
}

printf("\n");
return 0;

}