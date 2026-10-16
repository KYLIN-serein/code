# 2026-10-17 Day5 学习笔记：C语言 do-while 循环与前端 CSS 区块布局

今天彻底拿下了 C 语言循环的最后一块拼图（do-while），并在前端成功实现了带样式的“个人学习计划卡片”。

---

## 📖 第一部分：C语言 `do-while` 循环详解

### 1. 什么是 `do-while` 循环？
它是 `while` 的兄弟，唯一的区别在于**检查条件的时机**：
- **`while`**：先看条件，再干活。（条件不成立，一次都不干）
- **`do-while`**：**先干一次活，再看条件。**（不管条件成立不成立，至少干一次）

### 2. 核心语法
```c
do {
    // 循环体（要干的事）
} while (条件);  // ⚠️ 致命重点：while后面的括号末尾，必须有一个分号！
```

### 3. 实战代码：`do_while_demo.c`
```c
#include <stdio.h>

int main() {
    int num;
    int sum = 0; // 用来存所有输入数字的总和

    do {
        printf("请输入一个整数（输入0结束）: ");
        scanf("%d", &num); // ⚠️ 千万别漏 & 
        
        if (num != 0) {
            sum = sum + num; // 如果不是0，就把它加到总和里
        }
        
    } while (num != 0); // 只要不是0，就继续循环

    printf("你输入的所有数字之和是: %d\n", sum);
    return 0;
}
```

### 4. 逐句大白话解析
1. `do {`：先斩后奏。电脑一看到 `do`，直接冲进大括号执行。
2. `scanf("%d", &num);`：接收输入。这里不需要像 `while` 那样在循环外先写一遍。
3. `if (num != 0) { sum = sum + num; }`：如果输入的不是0，就加到总和中。
4. `} while (num != 0);`：执行完一轮后，判断 `num != 0` 是否成立。成立就跳回前面，不成立就往下走。**注意末尾的分号，漏掉直接报错！**

---

## 🌐 第二部分：Web 前端 HTML 与 CSS 进阶

### 1. 前端核心概念：区块与类
- **`<div class="card">`**：网页里最常用的“大盒子”。本身没有外观，用来把一堆内容打包在一起。`class="card"` 是给它贴个标签，方便 CSS 统一指挥。
- **CSS 的 `.card { ... }`**：`.` 开头的名字代表“类选择器”。意思是“只要 `class` 叫 `card`，就乖乖听我指挥”。

### 2. 实战代码：`index.html` 中的卡片
```html
<div class="card">
    <h2>我的大一学习计划</h2>
    <p>目标：大一顺利进入蓝桥杯集训队，并保持前端课程优秀。</p>
    <ul>
        <li class="highlight">每天刷1道C语言算法题</li>
        <li>每周写1篇Markdown笔记</li>
        <li>每天坚持Git提交</li>
    </ul>
</div>
```

### 3. 配套 CSS 样式
```html
<style>
    body {
        background-color: #f4f4f9;
        font-family: "Microsoft YaHei", sans-serif;
    }
    .card {
        background-color: white;       /* 白色背景 */
        width: 400px;                  /* 宽度固定为400像素 */
        padding: 20px;                 /* 内边距 */
        border-radius: 10px;           /* 圆角 */
        box-shadow: 0 4px 8px rgba(0,0,0,0.1); /* 阴影，立体感 */
        margin: 50px auto;             /* ⚠️ 上下50像素，左右自动居中（魔法词 auto） */
    }
    .highlight {
        color: red;                    /* 红色字体 */
        font-weight: bold;             /* 粗体 */
    }
</style>
```

---

## 🧠 第三部分：今日踩坑记录（极其重要！）

1. **`while` 循环体内忘记更新条件**
   - 之前写 `count_positive.c` 时，`while` 大括号里面忘记写 `scanf` 重新读取输入，导致 `num` 永远是同一个值，程序陷入死循环。**必须确保循环体内有能改变循环条件的代码！**
2. **`scanf` 漏掉 `&` 导致段错误（Segmentation fault）**
   - 在 `count_positive.c` 第 15 行漏写了 `&`，编译器只给黄字警告，但运行时报 `Segmentation fault` 并崩溃。
   - **铁律：C语言只要用 `scanf` 接收普通变量，必须加 `&`！**
3. **`do-while` 末尾漏分号**
   - `do { ... } while (条件);` 最后的分号必须写，这是它独有的语法规则。
4. **`gcc` 编译命令漏写 `&&`**
   - 漏写 `&&` 会把后面的运行命令当成第二个输入文件，报 `input file is the same as output file`。正确的命令是 `gcc 源文件.c -o bin/目标名 && ./bin/目标名`。
5. **警惕 AI 插件（Copilot）的幽灵代码**
   - 灰色斜体代码只是 AI 预测，按 `Tab` 会自动填入。**大一阶段强烈建议禁用，以防丧失独立写代码的能力！**
6. **终端卡死自救**
   - 如果程序死循环，按 `Ctrl + C` 强制终止。

---

## 🎯 今日小结与下一步计划
1. **C语言**：掌握了 `do-while`，彻底理清了 `while` 和 `do-while` 的区别（至少执行一次）。
2. **前端**：掌握了 HTML 的 `<div>` 区块和 CSS 的 `.class` 类选择器，成功用 `margin: 50px auto` 实现了卡片居中。
3. **Git**：每天坚持提交，养成肌肉记忆。

**明天目标**：
1. C语言进入新章节：**一维数组**（这是数据结构和算法的基石）。
2. 前端：开始了解 CSS 的“弹性布局（Flexbox）”，解决目前页面元素靠左的排版问题。