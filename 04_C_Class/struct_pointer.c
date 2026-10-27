#include <stdio.h>
#include <string.h>

struct Employee{
    int id;
    char arr[20];
    double salary;
};

void raiseSalary(struct Employee *p){
    p -> salary = p -> salary*1.1;
}

int main(){
    struct Employee emp1 = {1001,"张三",10000};

    printf("涨薪前：%.2f\n",emp1.salary);

    raiseSalary(&emp1);

    printf("涨薪后: %.2f\n",emp1.salary);

    return 0;
}