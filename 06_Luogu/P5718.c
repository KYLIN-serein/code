#include <stdio.h>

int getmin(int arr[] ,int n){
    int min = arr[0];
        for(int i = 1;i < n;i++){
            if(arr[i]<min){
                min = arr[i];
            }
        }
        return min;
}

int arr[100005];

int main(){
int n = 0;
scanf("%d",&n);
int arr[n];
for(int i = 0;i < n; i++){
    scanf("%d",&arr[i]);
}
    int min_val = getmin(arr,n);

    printf("%d",min_val);
    return 0;
}
