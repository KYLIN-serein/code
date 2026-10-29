#include <stdio.h>
#include <string.h>

struct Contact {
    char name[20];
    int age;
};

int main(){
    struct Contact book[100];
    int count = 0; 
    int choice;

     while (1) {
        printf("\n===== 通讯录 V2.0 =====\n");
        printf("1. 添加联系人\n");
        printf("2. 查找联系人\n");
        printf("3.显示所有联系人\n");
        printf("0. 退出系统\n");
        printf("请输入你的选择: ");
        scanf("%d", &choice);

        switch (choice){
        case 1:
         printf("请输入姓名和年龄 (例如: 张三 20): ");
                scanf("%s %d", book[count].name, &book[count].age);
                count++; 
                printf("添加成功！当前共有 %d 人。\n", count);
                break;

        case 2:
        char target[20];
                printf("请输入要查找的姓名: ");
                scanf("%s", target);
                
                int found = 0;
                for (int i = 0; i < count; i++) {
                    if (strcmp(book[i].name, target) == 0) {
                        printf("-> 找到了！姓名: %s, 年龄: %d\n", book[i].name, book[i].age);
                        found = 1;
                        break; 
                    }
                }
                if (found == 0) {
                    printf("-> 抱歉，通讯录里没有叫 %s 的人。\n", target);
                }
                break;

        case 3:
            printf("\n===== 所有联系人 =====\n");
            if (count == 0) {
                printf("通讯录空空如也...\n");
            } else {
                for(int i = 0; i < count; i++){
                    printf("%d. 名字：%-10s  年龄：%d\n", i+1, book[i].name, book[i].age);
                }
            }
            break;

        case 0: 
            printf("已退出系统，再见！\n");
            return 0;

            default:
                printf("输入无效，请重新选择！\n");
        }
    }
    return 0;
}