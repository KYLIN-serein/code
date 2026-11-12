#include <stdio.h>
#include <string.h>

struct student{
    char name[25];
    int qimo;
    int banji;
    char ganbu;
    char xibu;
    int lunwen;
    int money;
};

int main(){
    int n;
    scanf("%d",&n);

    struct student stu[105];
    int total_money = 0;
    int max_money = -1;
    int max_index = 0;

    for(int i = 0;i < n;i++){
        scanf("%s %d %d %c %c %d",stu[i].name,&stu[i].qimo,&stu[i].banji,&stu[i].ganbu,&stu[i].xibu,&stu[i].lunwen);
        int m = 0;
        if(stu[i].qimo > 80 && stu[i].lunwen >= 1) m += 8000;
        if(stu[i].qimo > 85 && stu[i].banji > 80) m += 4000;
        if(stu[i].qimo > 90) m += 2000;
        if(stu[i].qimo > 85 && stu[i].xibu == 'Y') m += 1000;
        if(stu[i].banji > 80 && stu[i].ganbu == 'Y') m += 850;

        stu[i].money = m;
        total_money += m;

        if(stu[i].money > max_money){
            max_money = stu[i].money;
            max_index = i;
        }
    }

    printf("%s\n",stu[max_index].name);
    printf("%d\n",stu[max_index].money);
    printf("%d\n",total_money);

    return 0;
}