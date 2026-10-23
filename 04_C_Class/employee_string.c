#include <stdio.h>
#include <string.h>

int main(){
    char name[20] = "张三";
    char dept[] = "_研发部";

    printf("名字占用字符数: %d\n", (int)strlen(name));

    strcat(name,dept);
    printf("拼接后的结果: %s\n",name);

    return 0;
}