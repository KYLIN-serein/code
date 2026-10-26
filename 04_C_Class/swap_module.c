#include <stdio.h>

void swap_wrong(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap_right(int *a, int *b) {
    int temp = *a; 
    *a = *b;       
    *b = temp;    
}

int main() {
    int user1_points = 500;
    int user2_points = 1000;

    printf("交换前: user1 = %d, user2 = %d\n", user1_points, user2_points);

    swap_wrong(user1_points, user2_points);
    printf("swap_wrong后: user1 = %d, user2 = %d\n", user1_points, user2_points);

    swap_right(&user1_points, &user2_points);
    printf("swap_right后: user1 = %d, user2 = %d\n", user1_points, user2_points);

    return 0;
}