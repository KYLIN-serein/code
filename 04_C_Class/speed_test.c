#include <stdio.h>
int main() {
int i = 0;
do {
    printf("do-while 执行了一次，i = %d\n",i);
    i++;
} while (i < 3);

int choice = 2;
switch (choice)
{
case 1: printf("选1\n");break;
case 2: printf("选2\n");break;
default : printf("无效\n");
}
return 0;
}