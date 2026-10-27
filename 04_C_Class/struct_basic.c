#include <stdio.h>
#include <string.h>

struct Employee{
    int id;
    char name[20];
    double salary;
};

int main(){
    struct Employee emp1;

    emp1.id = 1001;
    strcpy(emp1.name,"张三");
    emp1.salary = 8500.50;

    printf("工号: %d, 姓名: %s, 薪水: %.2f\n",emp1.id,emp1.name,emp1.salary);
    
    return 0;
}