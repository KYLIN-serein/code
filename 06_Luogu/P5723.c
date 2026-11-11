#include <stdio.h>

int is_zhishu(int n){
    if(n <= 1){
        return 0;
    }
    for(int i = 2;i * i <= n;i++){
        if(n%i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int L;
    scanf("%d",&L);
    int sum = 0;
    int count = 0;

    for(int i = 2; ;i++){
        if(is_zhishu(i)){
            if(sum + i > L){
                break;
            }
            printf("%d\n",i);
            sum += i;
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}