#include <stdio.h>
#include <string.h>

int main(){
    char name[3][20] = {"张三", "李四", "王五"};
    int scores[3] = {88, 95, 76};

    printf("   --- 员工数据面板 ---\n");

    for(int i = 0; i < 3; i++){
        printf("员工姓名: %s, 绩效得分: %d\n",name[i],scores[i]);

        if(strlen(name[i]) > 10){
        printf("警告: 名字过长，可能存在异常！\n");
        }
    }
        return 0;
}