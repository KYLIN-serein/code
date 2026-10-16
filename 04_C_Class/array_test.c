#include <stdio.h>
int main () {
    int arr[5] = {10, 20, 30, 40, 50,};
    int max_val = arr[0];

    for (int i = 1; i < 5; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    printf("该数组最大数是：%d\n",max_val);
    return 0;
}
