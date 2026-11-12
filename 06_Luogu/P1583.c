#include <stdio.h>
#include <stdlib.h>

struct person{
    int id;
    int w;
};

int cmp(const void *a,const void *b){
    struct person *p1 = (struct person *)a;
    struct person *p2 = (struct person *)b;

    if(p1 -> w != p2 -> w){
        return ((p2 -> w > p1 -> w) - (p2 -> w < p1 -> w));
    } else {
        return ((p1 -> id > p2 -> id) - (p1 -> id < p2 -> id));
    }
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);

    int E[11];
    for(int i = 1;i <= 10;i++){
        scanf("%d",&E[i]);
    }

    struct person p[20005];
    for(int i = 0;i < n;i++){
        scanf("%d",&p[i].w);
        p[i].id = i + 1;
    }

    qsort(p,n,sizeof(p[0]),cmp);

    for(int i = 0;i < n;i++){
        p[i].w += E[(i + 1)%10 == 0 ? 10 : (i + 1)%10];
    }

    qsort(p,n,sizeof(p[0]),cmp);

    for(int i = 0;i < k;i++){
        printf("%d ",p[i].id);
    }
    printf("\n");
    return 0;
}