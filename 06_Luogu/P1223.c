#include <stdio.h>
#include <stdlib.h>

struct water {
    int id;
    int time;
};

int cmp(const void *a, const void *b) {
    struct water *p1 = (struct water *)a;
    struct water *p2 = (struct water *)b;

    if (p1->time != p2->time) {
        return p1->time - p2->time;
    } else {
        return p1->id - p2->id;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    struct water arr[10005]; 
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i].time);
        arr[i].id = i + 1; 
    }

    qsort(arr, n, sizeof(struct water), cmp);

    double total_sum = 0;
    long long current_wait = 0; 

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i].id); 
        total_sum += current_wait; 
        current_wait += arr[i].time; 
    }
    printf("\n");
    printf("%.2f", total_sum / (double)n);
    return 0;
}