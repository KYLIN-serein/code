#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char word[15],article[1000000005];
    scanf("%s",word);
    getchar();
    fgets(article,1000000005,stdin);

    int len_w = strlen(word);
    int len_a = strlen(article);

    for(int i = 0;i < len_w;i++){
        word[i] = tolower(word[i]);
    }
    for(int i = 0;i < len_a;i++){
        article[i] = tolower(article[i]);
    }

    int count = 0;
    int first_pos = -1;
    char *p = article;

    while((p = strstr(p,word)) != NULL){
        int left_ok = (p == article) || (*(p - 1) == ' ');
        int right_ok = (*(p + len_w) == ' ') || (*(p + 1) == '\n') || (*(p + 1) == '\0');

        if(left_ok && right_ok){
            count++;
            if (first_pos == -1) {
                first_pos = p - article;
            }
        }
        p++;
    }
    if(count == 0){
        printf("-1");
    } else {
        printf("%d %d",count,first_pos);
    }
    return 0;
}