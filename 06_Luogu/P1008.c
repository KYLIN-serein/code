#include <stdio.h>

int main(){
    for(int A = 123;A <= 329; A++){
        int B = A*2;
        int C = A*3;

        int count[10] = {0};

        count[A / 100]++;
        count[(A / 10) % 10]++;
        count[A % 10]++;

        count[B / 100]++;
        count[(B / 10) % 10]++;
        count[B % 10 ]++;

        count[C / 100]++;
        count[(C / 10) % 10]++;
        count[C % 10]++;

        int callo = 1;

        if(count[0] > 0){
            callo = 0;
        }

        for(int i = 1; i < 10; i++){
            if(count[i] != 1){
                callo = 0;
                break;
            }
        }

        if(callo == 1){
            printf("%d %d %d\n",A,B,C);
        }
    }
    return 0;
}