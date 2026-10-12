#include <stdio.h>

int main() {
    double num = 0;
    printf("请输入一个数：");
    scanf("%lf",&num);

    printf("默认打印：%f\n",num);
    printf("保留一位小数：%.1f\n",num);
    printf("保留二位小数：%.2f\n",num);

    return 0;

}