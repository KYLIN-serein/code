#include <stdio.h>

struct Contact{
    char name[20];
    int age;
};

int main(){
    struct Contact book[100];
    int count = 3;
    printf("--- 欢迎使用微型通讯录 ---\n");
    printf("请输入联系人姓名以及年龄(多个请分列行 name1 age1 name2 age2): ");
    for(int i = 0; i < count;i++){
        scanf("%s %d",book[i].name,&book[i].age);
    }
    printf("\n--- 通讯录列表 ---\n");
    for(int i = 0;i < count;i++){
    printf(" %d. 姓名: %s 年龄: %d\n",i + 1,book[i].name, book[i].age);
    }

    return 0;
}