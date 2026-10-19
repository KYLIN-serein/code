#include <stdio.h>
int main(){
    int arr[5] = {2,5,4,3,1};

    for(int i = 0; i < 5-1; i++){
        for(int j = 0; j < 5-1-i; j++){
            if(arr[j] > arr[j+ 1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("从小到大排序后的结果: ");
    for(int i = 0; i < 5; i++){
        printf("%d",arr[i]);
    }

    printf("\n");
    return 0;
}