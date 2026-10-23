#include <stdio.h>
#include <string.h>

int calcTotalScore(int arr[], int len) {
    int sum = 0;
    for(int i = 0; i < len ; i++){
        sum += arr[i];
    }
    return sum;
}

int main(){
    int scores[3] = {80,90,100};
    int total = calcTotalScore(scores,3);
    printf("总成绩: %d\n",total);

    return 0;
}