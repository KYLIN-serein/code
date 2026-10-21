#include <stdio.h>

int getMax(int arr[],int n){
    int max = arr[0];
    for(int i = 1 ;i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

void bubbleSort(int arr[],int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1-i; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int scores[5];
    printf("请输入5个学生的成绩:");
    for(int i = 0;i < 5;i++){
        scanf("%d",&scores[i]);
    }

    int max_scores = getMax(scores,5);
    printf("最高分是: %d\n",max_scores);

    bubbleSort(scores,5);

    printf("成绩从小到大排序为:");
    for(int i = 0; i < 5;i++){
        printf("%d ",scores[i]);
    }
    printf("\n");

    return 0;
}