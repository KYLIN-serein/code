#include <stdio.h>

struct Contact{
    char name[20];
    int age;
};

int main(){
    struct Contact book[100];
    int count = 0;
    printf("--- 欢迎使用微型通讯录 ---\n");
    printf("请输入联系人姓名: ");
    scanf("%s",book[0].name);
    printf("请输入联系人年龄:");
    scanf("%d",&book[0].age);
    count = 1;
    printf("\n--- 通讯录列表 ---\n");
    printf("姓名: %s, 年龄: %d\n", book[0].name, book[0].age);

    return 0;
}   