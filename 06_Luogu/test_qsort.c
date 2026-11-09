#include <stdio.h>
#include <stdlib.h>

struct Student{
    char name[20];
    int score;
};

int cmp(const void *a,const void *b){
    struct Student *p1 = (struct Student *)a;
    struct Student *p2 = (struct Student *)b;

    return p2->score - p1->score;
}

int main(){
    struct Student stus[3] = {
        {"张三", 85},
        {"李四", 95},
        {"王五", 90}
    };
    qsort(stus,3,sizeof(struct Student),cmp);
    for (int i = 0; i < 3; i++) {
        printf("名字: %-10s 成绩: %d\n", stus[i].name, stus[i].score);
    }

    return 0;
}