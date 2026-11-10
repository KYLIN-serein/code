#include <stdio.h>
#include <stdlib.h>

int arr[30005];

int cmp(const void *a,const void *b){
    int p1 = *(int*)a;
    int p2 = *(int*)b;

    return((p1 > p2) - (p1 < p2));
}

int main(){
    int w,n;
    scanf("%d %d",&w,&n);
    for(int i = 0;i < n;i++){
        scanf("%d",&arr[i]);
    }

    qsort(arr,n,sizeof(arr[0]),cmp);

    int left = 0;
    int right = n - 1;
    int group = 0;

    while(left <= right){
        if(arr[left] + arr[right] > w){
            group++;
            right--;
        } else if(arr[left] + arr[right] <= w){
            group++;
            left++;
            right--;
        }
    }
    printf("%d",group);
    return 0;
}