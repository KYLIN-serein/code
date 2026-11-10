#include <stdio.h>

int main(){
    int n,m;
    char map[105][105];
    scanf("%d %d",&n,&m);
    for(int i = 0;i<n;i++){
        scanf("%s",map[i]);
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(map[i][j] == '*'){
                printf("*");
            } else {
                int count = 0;

                for(int dx = -1;dx <= 1;dx++){
                    for(int dy = -1;dy <= 1;dy++){

                        int nx = i + dx;
                        int ny = j + dy;

                        if(nx >= 0 && nx < n && ny >= 0 && ny <m){
                            if(map[nx][ny] == '*'){
                                count++;
                            }
                        }
                    }
                }
                printf("%d",count);
            }
        }
        printf("\n");
    }
    return 0;
}