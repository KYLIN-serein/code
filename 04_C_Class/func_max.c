#include <stdio.h>

int getMax(int a, int b){
    if(a > b){
        return a;
    } else {
        return b;
    }
}

int main(){
    int x = -30;
    int y = 20;
    int max_val = getMax(x , y);
    printf("%d 和 %d 中的最大值是: %d\n",x,y,max_val);
    return 0;
}