#include <stdio.h>
#include <stdlib.h>

struct Student{
    char name[20];
    int id;
    int chinese;
    int m;
    int e;
    int totalscore;
};

int cmp(const void *a,const void *b){
    struct Student *p1 = (struct Student *)a;
    struct Student *p2 = (struct Student *)b;

    if(p1 ->totalscore != p2 ->totalscore){
        return p2 -> totalscore - p1 -> totalscore;
    } else if(p1 -> chinese != p2 -> chinese){
        return p2 -> chinese - p1 ->chinese;
    } else {
        return p1 -> id - p2 -> id;
    }
};

int main(){
    int i = 0;
    int j = 0;
    scanf("%d",&i);
    struct Student arr[i];
    for(int j = 0; j < i;j++){
        scanf("%d %d %d",&arr[j].chinese,&arr[j].m,&arr[j].e);
        arr[j].totalscore = (arr[j].chinese + arr[j].e + arr[j].m);
        arr[j].id = j + 1;
    }

    qsort(arr,i,sizeof(struct Student),cmp);
    
    for(int j = 0;j < 5;j++){
        printf("%d %d\n",arr[j].id,arr[j].totalscore);
    }
    return 0;
}