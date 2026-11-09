#include <stdio.h>

int main(){
    FILE *fp = fopen("tset.txt","w");

    if (fp == NULL) {
        printf("文件打开失败！\n");
        return 1;
    }

    fprintf(fp, "你好，这是我写入的第一行数据\n");
    fprintf(fp, "张三 20\n");

    fclose(fp); 
    printf("写入成功！\n");

    return 0;
}