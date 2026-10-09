#include <iostream>

int main(){
    int a , b;
    char op;

    std::cout << "请输入表达式（例如：3+5）:";
    std::cin >> a >> op >> b;

    if(op=='+'){
        std::cout <<"结果：" << a + b<< "\n";
    } else if(op=='-'){
        std::cout <<"结果：" << a - b<< "\n";
    } else {
        std::cout << "暂不支持该运算符\n";
    }

    return 0;
}