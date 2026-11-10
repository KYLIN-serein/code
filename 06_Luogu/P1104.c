#include <stdio.h>
#include <stdlib.h>

struct birth{
    int id;
    char name[100];
    int year;
    int day;
    int month;
};

int cmp(const void *a, const void *b) {
    struct birth *p1 = (struct birth *)a;
    struct birth *p2 = (struct birth *)b;
    if (p1->year != p2->year) {
        return (p1->year > p2->year) - (p1->year < p2->year);
    } else if (p1->month != p2->month) {
        return (p1->month > p2->month) - (p1->month < p2->month);
    } else if (p1->day != p2->day) {
        return (p1->day > p2->day) - (p1->day < p2->day);
    } else {
    return (p2->id > p1->id) - (p2->id < p1->id);
    }
}

int main(){
    int i = 0;
    scanf("%d",&i);
    struct birth arr[9999999];
    for(int j = 0;j < i;j++){
        scanf("%s %d %d %d",arr[j].name,&arr[j].year,&arr[j].month,&arr[j].day);
        arr[j].id = j + 1;
    }

    qsort(arr,i,sizeof(struct birth),cmp);

    for(int j = 0;j < i;j++){
        printf("%s\n",arr[j].name);
    }
    return 0;
}