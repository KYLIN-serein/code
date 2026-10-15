#include <stdio.h>
int main() {
    int sum = 0;
    int i = 1;
    while (i <= 100) {
    sum = sum + i;
    i++;
    }
    printf("从1到100的和为：%d\n",sum);
    return 0;
    
}