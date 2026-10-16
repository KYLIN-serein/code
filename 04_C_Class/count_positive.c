#include <stdio.h>

int main(){
int sum = 0;
int count = 0;

printf("请输入一个整数（输入0结束）：\n");
scanf("%d",&sum);

while (sum != 0)
{
    if (sum > 0){
        count++;
    }
    scanf("%d",&sum);
}
printf("你一共输入了%d个正数。",count);
return 0;
}
