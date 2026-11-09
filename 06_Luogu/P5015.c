#include <stdio.h>
int main(){
    char ch;
    int count = 0;

    while((ch = getchar()) != '\n'){
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
            count++;
        }
    }
    printf("%d",count);
    return 0;
    
}