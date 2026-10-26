#include <stdio.h>

int main() {
    int a = 10;
    
    printf("变量 a 的值是: %d\n", a);
    printf("变量 a 的内存地址是: %p\n", &a); 

    int *p = &a; 
    
    printf("指针 p 存的值 (即 a 的地址): %p\n", p);
    
    printf("顺着指针 p 找到的值: %d\n", *p);

    *p = 99;
    printf("通过指针修改后，a 的值变成了: %d\n", a);

    return 0;
}