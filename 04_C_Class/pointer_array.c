#include <stdio.h>

int main() {
    int arr[3] = {10, 20, 30};
    int *p = arr; 

    printf("方式一，传统下标: %d\n", arr[1]);
    
    printf("方式二，指针加法: %d\n", *(p + 1)); 
    
    return 0;
}