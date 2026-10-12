#include <iostream> 
#include <string>

int main() {
    std::string name;

    std::cout << "请输入你的名字：";
    std::getline(std::cin,name);

    std::cout << "你好，" << name << "！\n";
    std::cout << "你的名字有" << name.length() << "个字符长。\n";

    return 0;

}