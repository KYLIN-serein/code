# 2026-10-29 Day12 学习笔记：微型通讯录 V2.0 —— 主循环、菜单与查找

今天，我们的通讯录从一个“只能运行一次的程序”，正式进化成了拥有主循环、多分支菜单、以及查找功能的“真正软件”。同时，踩爆了 `switch` 穿透和变量作用域的坑。

---

## 📖 第一部分：软件骨架 —— 死循环与菜单

**工程思维**：真实的软件（如微信、浏览器）在用户点击关闭之前，主程序是永远运行的。我们用 `while(1)` 配合 `switch-case` 来实现这个交互面板。

### 1. 主循环与菜单
```c
while (1) {
    printf("\n===== 通讯录 V2.0 =====\n");
    printf("1. 添加联系人\n");
    printf("2. 查找联系人\n");
    printf("3. 显示所有联系人\n");
    printf("0. 退出系统\n");
    printf("请输入你的选择: ");
    scanf("%d", &choice);

    switch (choice) {
        // ... 分支逻辑
    }
}
```
- `while(1)` 是死循环，保证菜单一直显示。
- 只有当用户输入 `0`，触发 `case 0` 里的 `return 0;` 时，才会直接掀桌子结束整个 `main` 函数。

---

## 🧠 第二部分：今日致命踩坑复盘（极其重要）

### 踩坑 1：失踪的 `break` 与 Switch 穿透
- **错误现象**：在 `case 3`（显示全部）执行完后，程序没有回到菜单，而是直接打印了“已退出系统”，然后关闭了。
- **原因**：`case 3` 末尾忘记写 `break;`。程序像多米诺骨牌一样，顺着往下执行了 `case 0` 的代码。这就是 `switch` 的**穿透（Fall-through）**。
- **铁律**：**每一个 `case` 下面处理完逻辑后，必须顺手敲上 `break;`**。

### 踩坑 2：`case` 里的变量作用域冲突
- **错误现象**：如果在 `case 2` 里定义了 `int found = 0;`，而没加大括号，可能会报编译错误。
- **工程纠正**：在 `switch` 里，多个 `case` 共享同一个作用域。如果要在 `case` 里定义新变量，**必须用大括号 `{}` 把该 `case` 的代码包起来**，形成独立的局部作用域。

---

## 💻 第三部分：通讯录 V2.0 完整代码

### 1. 核心代码 (`address_book.c`)
```c
#include <stdio.h>
#include <string.h>

struct Contact {
    char name[20];
    int age;
};

int main(){
    struct Contact book[100];
    int count = 0; 
    int choice;

    while (1) {
        printf("\n===== 通讯录 V2.0 =====\n");
        printf("1. 添加联系人\n");
        printf("2. 查找联系人\n");
        printf("3. 显示所有联系人\n");
        printf("0. 退出系统\n");
        printf("请输入你的选择: ");
        scanf("%d", &choice);

        switch (choice){
        case 1: // 添加功能
            // 工程优化：防止越界
            if (count >= 100) {
                printf("通讯录已满，无法添加！\n");
                break;
            }
            printf("请输入姓名和年龄: ");
            scanf("%s %d", book[count].name, &book[count].age);
            count++; 
            printf("添加成功！当前共有 %d 人。\n", count);
            break;

        case 2: { // 查找功能（加大括号防作用域冲突）
            char target[20];
            printf("请输入要查找的姓名: ");
            scanf("%s", target);
            
            int found = 0;
            for (int i = 0; i < count; i++) {
                // 字符串比较神器 strcmp
                if (strcmp(book[i].name, target) == 0) {
                    printf("-> 找到了！姓名: %s, 年龄: %d\n", book[i].name, book[i].age);
                    found = 1;
                    break; 
                }
            }
            if (found == 0) {
                printf("-> 抱歉，通讯录里没有叫 %s 的人。\n", target);
            }
            break;
        }

        case 3: // 显示全部
            printf("\n===== 所有联系人 =====\n");
            if (count == 0) {
                printf("通讯录空空如也...\n");
            } else {
                for(int i = 0; i < count; i++){
                    // %-10s 保证排版像表格一样整齐
                    printf("%d. 名字：%-10s  年龄：%d\n", i+1, book[i].name, book[i].age);
                }
            }
            break; // ⚠️ 补上了这个，防止穿透

        case 0: 
            printf("已退出系统，再见！\n");
            return 0;

        default:
            printf("输入无效，请重新选择！\n");
            break;
        }
    }
    return 0;
}
```

### 2. 硬核解析：`strcmp` 比较字符串
```c
if (strcmp(book[i].name, target) == 0)
```
- 为什么不能用 `==`？因为数组名代表内存地址，`==` 比较的是门牌号是否相同，永远为假。
- `strcmp(a, b)` 会逐字比对内容。如果一模一样，返回 `0`。
- **死记硬背**：`strcmp(...) == 0` 代表相等。

---

## 🎯 下一步计划（通讯录 V3.0 预告）
目前的数据存在内存里，一旦选择 `0` 退出系统，所有的联系人都会灰飞烟灭。下一阶段，我们将学习 C 语言最后的绝杀技能：**文件操作（File I/O）**，让数据永久保存在硬盘里！