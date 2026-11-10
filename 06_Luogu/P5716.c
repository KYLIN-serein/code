#include <stdio.h>

int main(){
    int y,m;
    scanf("%d %d",&y,&m);
    int day[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if((y%4 == 0) && (y%100 != 0) || (y%400 == 0)){
        day[2] = 29;
    }
    printf("%d",day[m]);
    return 0;
}