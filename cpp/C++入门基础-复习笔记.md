# 01. C++入门基础

> 本笔记由原课件《01.C++入门基础》整理而来，保留原有大纲和代码示例，压缩背景内容，并补充了重点解释、易错提示、速查表和可追溯例题。
>
> 原课件图片未复制到本笔记，需要时可查看：`D:\codexworks\learning\课件\C++初阶新版课件+(1)\assets\01\`。
>
> 复习顺序建议：先读第 6～13 节的核心语法，再回看第 2～5 节背景与学习方法，最后独立完成第 13.1 节例题。

## 1. C++课程介绍

C++ 初阶课程主要包含三个层次：

```text
C++ 语法 -> STL -> 高阶数据结构
```

原课程大约 50+ 节课、150 小时以上。本章《C++入门基础》是语法部分的第一站，重点掌握：

- C++ 与 C 的关系
- 命名空间
- C++ 输入输出
- 缺省参数
- 函数重载
- 引用
- 内联函数
- `nullptr`

## 2. C++发展历史

### 2.1 核心时间线

| 时间 | 事件 |
| --- | --- |
| 1979 年 | Bjarne Stroustrup 在贝尔实验室开始相关研究，发现 C 语言在复杂软件项目中表达能力和可维护性不足 |
| 1983 年 | 在 C 基础上加入类、封装、继承等面向对象特性，该语言被命名为 C++ |
| 1989 年 | C++ 标准化工作启动 |
| 1994 年 | 提出第一个标准化草案 |
| 1997 年 | 通过最终标准草案 |
| 1998 年 | 发布第一个正式标准 C++98 |

STL 最初由 Alexander Stepanov、Meng Lee、David R Musser 在惠普实验室开发。STL 被纳入标准是一项重要决定，也延缓了标准化进程。

### 2.2 C++版本更新

| 版本 | 阶段 | 需要记住的主要内容 |
| --- | --- | --- |
| C++98 | 第一个标准 | 引入 STL，绝大多数编译器支持 |
| C++03 | 稳定性修订 | 修复 C++98 问题，引入 `tr1` |
| C++11 | 革命性更新 | `lambda`、范围 `for`、右值引用与移动语义、变长模板参数、智能指针、标准线程库 |
| C++14 | C++11 的扩展 | 泛型 `lambda`、函数返回类型推导、二进制字面量 |
| C++17 | 表达能力增强 | `if constexpr`、结构化绑定、折叠表达式、`filesystem` |
| C++20 | 重要里程碑 | 协程、概念、模块 |
| C++23 | 小版本完善 | `if consteval`、`flat_map`、`import std` 等 |
| C++26 | 制定中 | 持续演进 |

> 学习重点不是背诵所有版本号，而是理解不同项目可能使用不同标准。现代开发至少应熟悉 C++11，并逐渐向 C++17/C++20 过渡。

### 2.3 关于 C++23 网络库

C++ 长期缺少标准网络库。`networking` 原计划进入 C++23，但最终没有纳入，因此产生了较多讨论。这个案例说明：语言标准是由提案、讨论和取舍逐步形成的，学习时不必把“某个版本包含什么”当成必须死记的内容。

## 3. C++参考文档

推荐结合使用以下文档：

| 文档 | 地址 | 特点 |
| --- | --- | --- |
| cplusplus.com | <https://legacy.cplusplus.com/reference/> | 非官方，内容更新到 C++11，但按头文件组织，容易阅读 |
| cppreference 中文版 | <https://zh.cppreference.com/w/cpp> | 官方参考中文版，信息全面 |
| cppreference 英文版 | <https://en.cppreference.com/w/> | 官方参考英文版，更新及时 |

日常查询优先使用 cppreference，遇到较旧、简短的语法示例可以辅助查看 cplusplus.com。

## 4. C++的重要性

### 4.1 编程语言排行榜

TIOBE 排名反映的是语言热度，不等于语言好坏，也不等于代码量。以下是原课件引用的 2024 年 6 月排行榜前 10 名：

| 2024 年 6 月排名 | 编程语言 | 热度 |
| --- | --- | --- |
| 1 | Python | 15.39% |
| 2 | C++ | 10.03% |
| 3 | C | 9.23% |
| 4 | Java | 8.40% |
| 5 | C# | 6.65% |
| 6 | JavaScript | 3.32% |
| 7 | Go | 1.93% |
| 8 | SQL | 1.75% |
| 9 | Visual Basic | 1.66% |
| 10 | Fortran | 1.53% |

### 4.2 C++在工作领域中的应用

| 领域 | 典型内容 |
| --- | --- |
| 大型系统软件 | 编译器、数据库、操作系统、浏览器 |
| 音视频处理 | FFmpeg、WebRTC、Mediasoup、ijkplayer |
| PC 客户端 | Windows 桌面软件，常见技术栈为 C++ + Qt |
| 服务端开发 | 游戏服务、流媒体服务、量化交易等高性能后台 |
| 游戏引擎 | UE4、Cocos2d-x 等引擎底层 |
| 嵌入式开发 | 智能手环、摄像头、扫地机器人、车载系统等 |
| 机器学习引擎 | 底层算法常用 C++，上层常使用 Python 封装 |
| 测试开发 | 测试工具、自动化测试脚本和性能测试 |

## 5. C++学习建议和书籍推荐

### 5.1 C++学习难度

C++ 属于难学难精的语言。主要难点来自历史包袱、较丰富的语法特性、手动内存管理和多范式设计。不要追求几天速成，而应通过持续写代码、回看和整理笔记逐步建立知识体系。

### 5.2 C++学习建议

1. 每节课的课堂样例都要亲自敲一遍，不能只阅读。
2. 每节课尽量整理笔记；时间不足时，至少整理重点章节。
3. 遇到编译错误时先看错误码和上下文，逐步培养独立排查能力。
4. 学习一个语法点后，尝试用一个小程序验证它的边界行为。

### 5.3 学习书籍推荐

| 书籍 | 定位 | 建议阅读阶段 |
| --- | --- | --- |
| 《C++ Primer》 | 系统讲解 C++ 语法，可作为语法字典 | 前期预习、中后期查漏 |
| 《STL源码剖析》 | 从底层实现角度剖析 STL | 课程中后期 |
| 《Effective C++》 | 55 条正确高效使用 C++ 的建议 | 中后期，工作后仍可重读 |

## 6. C++的第一个程序

C++ 基本兼容 C 的语法，因此 C 风格的程序仍可运行。区别在于：

- 源文件后缀通常改为 `.cpp`。
- Visual Studio 根据 `.cpp` 后缀调用 C++ 编译器。
- Linux 下使用 `g++` 编译，而不是 `gcc`。

### 6.1 C 风格写法

```cpp
// test.cpp
#include<stdio.h>
int main()
{
   printf("hello world\n");

   return 0;
}
```

### 6.2 C++ 风格写法

```cpp
// test.cpp
// 这里的std cout等我们都看不懂，没关系，下面我们会依次讲解
#include<iostream>
using namespace std;

int main()
{
   cout << "hello world\n" << endl;

   return 0;
}
```

**讲解**：

- `<iostream>` 是 C++ 标准输入输出流库。
- `cout` 是标准输出对象。
- `endl` 会输出换行并刷新缓冲区。
- 原示例中 `"hello world\n" << endl` 同时包含 `\n` 和 `endl`，实际可能产生两个换行；通常写成其中一种即可。

Linux 下常见编译运行命令：

```bash
g++ -std=c++17 test.cpp -o test
./test
```

## 7. 命名空间

### 7.1 namespace 的价值

变量、函数和类都存在于某个作用域中。项目变大后，全局作用域中的名称很容易冲突。命名空间用于对标识符进行本地化，避免命名冲突和名字污染。

```cpp
#include <stdio.h>
#include <stdlib.h>

int rand = 10;
int main()
{
   // 编译报错：error C2365: "rand": 重定义；以前的定义是"函数"
   printf("%d\n", rand);
   return 0;
}
```

**讲解**：`stdlib.h` 中已经声明了 `rand` 函数，再定义同名全局变量 `rand` 就会发生重定义。C++ 引入 `namespace` 正是为了解决这类问题。

### 7.2 namespace 的定义

要点：

- 使用 `namespace 名称 { ... }` 定义。
- 命名空间中可以有变量、函数、类型。
- `namespace` 本质是定义出一个独立的域，实现名称隔离。
- 命名空间可以嵌套定义。
- 多个文件中的同名命名空间会被视为同一个命名空间。
- C++ 标准库通常放在 `std` 命名空间中。

#### 示例 1：普通命名空间

```cpp
#include <stdio.h>
#include <stdlib.h>
// 1. 正常的命名空间定义
// bit是命名空间的名字，一般开发中是用项目名字做命名空间名。
// 我们上课用的是bit，大家下去以后自己练习可以考虑用自己名字缩写，如张三：zs
namespace bit
{
   // 命名空间中可以定义变量/函数/类型
   int rand = 10;
   int Add(int left, int right)
   {
       return left + right;
   }
   struct Node
   {
       struct Node* next;
       int val;
   };
}

int main()
{
   // 这里默认是访问的是全局的rand函数指针
   printf("%p\n", rand);
   // 这里指定bit命名空间中的rand
   printf("%d\n", bit::rand);
   return 0;
}
```

**讲解**：不加限定符时访问全局的 `rand`；使用 `bit::rand` 时访问 `bit` 命名空间中的变量。`::` 是作用域限定符。

#### 示例 2：嵌套命名空间

```cpp
// 2. 命名空间可以嵌套
namespace bit
{
   // 鹏哥
   namespace pg
   {
       int rand = 1;
       int Add(int left, int right)
       {
           return left + right;
       }
   }
   // 杭哥
   namespace hg
   {
       int rand = 2;
       int Add(int left, int right)
       {
           return (left + right)*10;
       }
   }
}

int main()
{
   printf("%d\n", bit::pg::rand);
   printf("%d\n", bit::hg::rand);
   printf("%d\n", bit::pg::Add(1, 2));
   printf("%d\n", bit::hg::Add(1, 2));
   return 0;
}
```

**讲解**：`bit::pg::rand` 表示一层层进入命名空间。不同嵌套命名空间可以定义同名函数 `Add`。

#### 示例 3：多文件中的同名命名空间会合并

```cpp
// Stack.h
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

namespace bit
{
    typedef int STDataType;
    typedef struct Stack
    {
        STDataType* a;
        int top;
        int capacity;
    }ST;

    void STInit(ST* ps, int n);
    void STDestroy(ST* ps);

    void STPush(ST* ps, STDataType x);
    void STPop(ST* ps);
    STDataType STTop(ST* ps);
    int STSize(ST* ps);
    bool STEmpty(ST* ps);
}
```

```cpp
// Stack.cpp
#include"Stack.h"
namespace bit
{
    void STInit(ST* ps, int n)
    {
        assert(ps);
        ps->a = (STDataType*)malloc(n * sizeof(STDataType));
        ps->top = 0;
        ps->capacity = n;
    }

    // 栈顶
    void STPush(ST* ps, STDataType x)
    {
        assert(ps);
        // 满了， 扩容
        if (ps->top == ps->capacity)
        {
            printf("扩容\n");
            int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
            STDataType* tmp = (STDataType*)realloc(ps->a, newcapacity * sizeof(STDataType));
            if (tmp == NULL)
            {
                perror("realloc fail");
                return;
            }
            ps->a = tmp;
            ps->capacity = newcapacity;
        }
        ps->a[ps->top] = x;
        ps->top++;
    }

    //...
}
```

```cpp
// Queue.h
#pragma once
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

namespace bit
{
    typedef int QDataType;
    typedef struct QueueNode
    {
        int val;
        struct QueueNode* next;
    }QNode;
    typedef struct Queue
    {
        QNode* phead;
        QNode* ptail;
        int size;
    }Queue;

    void QueueInit(Queue* pq);
    void QueueDestroy(Queue* pq);
    // 入队列
    void QueuePush(Queue* pq, QDataType x);
    // 出队列
    void QueuePop(Queue* pq);
    QDataType QueueFront(Queue* pq);
    QDataType QueueBack(Queue* pq);
    bool QueueEmpty(Queue* pq);
    int QueueSize(Queue* pq);
}
```

```cpp
// Queue.cpp
#include"Queue.h"
namespace bit
{
    void QueueInit(Queue* pq)
    {
        assert(pq);
        pq->phead = NULL;
        pq->ptail = NULL;
        pq->size = 0;
    }

    // ...
}
```

```cpp
// test.cpp
#include"Queue.h"
#include"Stack.h"

// 全局定义了一份单独的Stack
typedef struct Stack
{
    int a[10];
    int top;
}ST;

void STInit(ST* ps){}
void STPush(ST* ps, int x){}

int main()
{
    // 调用全局的
    ST st1;
    STInit(&st1);
    STPush(&st1, 1);
    STPush(&st1, 2);
    printf("%d\n", sizeof(st1));

    // 调用bit namespace的
    bit::ST st2;
    printf("%d\n", sizeof(st2));
    bit::STInit(&st2);
    bit::STPush(&st2, 1);
    bit::STPush(&st2, 2);
    return 0;
}
```

**讲解**：`Stack.h` 和 `Stack.cpp` 中都定义了 `namespace bit`，链接时它们会被视为同一个命名空间。`test.cpp` 中还可以在全局定义另一个 `ST`，使用 `bit::ST` 即可区分。

### 7.3 命名空间的使用

编译器默认只在局部作用域或全局作用域查找名称，不会自动进入命名空间查找。

使用命名空间成员的三种方式：

| 方式 | 写法 | 项目建议 |
| --- | --- | --- |
| 指定命名空间访问 | `N::a` | 推荐 |
| 展开某个成员 | `using N::b;` | 常用成员且无冲突时使用 |
| 展开全部成员 | `using namespace N;` | 项目不推荐，练习方便 |

#### 原示例：直接访问会报错

```cpp
#include<stdio.h>
namespace bit
{
   int a = 0;
   int b = 1;
}
int main()
{
   // 编译报错：error C2065: "a": 未声明的标识符
   printf("%d\n", a);
   return 0;
}
```

#### 方式 1：指定命名空间访问

```cpp
// 指定命名空间访问
int main()
{
   printf("%d\n", N::a);
   return 0;
}
```

#### 方式 2：展开某个成员

```cpp
// using将命名空间中某个成员展开
using N::b;
int main()
{
   printf("%d\n", N::a);
   printf("%d\n", b);
   return 0;
}
```

#### 方式 3：展开全部成员

```cpp
// 展开命名空间中全部成员
using namespce N;
int main()
{
   printf("%d\n", a);
   printf("%d\n", b);
   return 0;
}
```

**注意**：

- 原课件后三个示例中的 `N` 是演示占位，实际代码中应替换为具体的命名空间，例如 `bit`。
- 最后一段的 `namespce` 是原课件中的拼写错误，正确关键字是 `namespace`。
- `using namespace std;` 在练习中方便，但在大型项目中容易引入名称冲突。

## 8. C++输入&输出

要点：

- `<iostream>` 是 Input Output Stream 的缩写。
- `std::cin` 面向窄字符标准输入流。
- `std::cout` 面向窄字符标准输出流。
- `std::endl` 插入流时相当于输出换行并刷新缓冲区。
- `<<` 是流插入运算符，`>>` 是流提取运算符；它们复用了 C 语言的位运算符号。
- C++ 输入输出能自动识别基本类型，主要依赖函数重载实现。
- C++ 流能更好地支持自定义类型的输入输出。
- 日常练习可以使用 `using namespace std;`，实际项目不建议。

```cpp
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int main()
{
   int a = 0;
   double b = 0.1;
   char c = 'x';
   cout << a << " " << b << "  " << c << endl;
   std::cout << a << " " << b << "  " << c << std::endl;

   scanf("%d%lf", &a, &b);
   printf("%d %lf\n", a, b);

   // 可以自动识别变量的类型
   cin >> a;
   cin >> b >> c;
   cout << a << endl;
   cout << b << "  " << c << endl;
   return 0;
}
```

**讲解**：

- `cout << a` 不需要像 `printf` 那样写 `%d`。
- `cin >> a` 根据 `a` 的类型读取。
- 第二个输出显式使用了 `std::cout` 和 `std::endl`，作用与 `using namespace std` 后的写法相同。

### 8.1 大量输入输出时的优化

```cpp
#include<iostream>
using namespace std;

int main()
{
   // 在io需求比较高的地方，如部分大量输入的竞赛题中，加上以下3行代码
   // 可以提高C++IO效率
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   return 0;
}
```

**讲解**：

- `ios_base::sync_with_stdio(false)` 关闭 C++ 流与 C 标准 IO 的同步。
- 关闭同步后，不应再混用 `scanf/printf` 和 `cin/cout`，否则输出顺序可能异常。
- `cin.tie(nullptr)` 解绑 `cin` 与 `cout`，减少不必要的刷新。
- `endl` 会强制刷新，输出量很大时应优先使用 `'\n'`。

## 9. 缺省参数

缺省参数又称默认参数。函数声明或定义时给形参指定默认值，调用时若未传实参则使用默认值。

规则：

1. 全缺省：所有形参都有默认值。
2. 半缺省：只有部分形参有默认值。
3. 半缺省必须从右向左连续缺省。
4. 调用函数时只能从左向右连续传参，不能跳过中间参数。
5. 声明与定义分离时，缺省值只能写在声明中。

### 9.1 单个缺省参数

```cpp
#include <iostream>
#include <assert.h>
using namespace std;

void Func(int a = 0)
{
   cout << a << endl;
}

int main()
{
   Func();     // 没有传参时，使用参数的默认值
   Func(10);   // 传参时，使用指定的实参
   return 0;
}
```

### 9.2 全缺省和半缺省

```cpp
#include <iostream>
using namespace std;

// 全缺省
void Func1(int a = 10, int b = 20, int c = 30)
{
   cout << "a = " << a << endl;
   cout << "b = " << b << endl;
   cout << "c = " << c << endl << endl;
}

// 半缺省
void Func2(int a, int b = 10, int c = 20)
{
   cout << "a = " << a << endl;
   cout << "b = " << b << endl;
   cout << "c = " << c << endl << endl;
}

int main()
{
   Func1();
   Func1(1);
   Func1(1,2);
   Func1(1,2,3);

   Func2(100);
   Func2(100, 200);
   Func2(100, 200, 300);
   return 0;
}
```

**讲解**：

- `Func1()` 使用全部默认值。
- `Func1(1)` 只提供第一个实参，后面的参数使用默认值。
- `Func2(int a, int b = 10, int c = 20)` 是合法的半缺省，因为默认参数从右向左连续。
- `void f(int a = 1, int b)` 不合法，不能跳过左侧参数给默认值。

### 9.3 声明与定义分离

```cpp
// Stack.h
#include <iostream>
#include <assert.h>
using namespace std;

typedef int STDataType;
typedef struct Stack
{
    STDataType* a;
    int top;
    int capacity;
}ST;

void STInit(ST* ps, int n = 4);
```

```cpp
// Stack.cpp
#include"Stack.h"
// 缺省参数不能声明和定义同时给
void STInit(ST* ps, int n)
{
    assert(ps && n > 0);
    ps->a = (STDataType*)malloc(n * sizeof(STDataType));
    ps->top = 0;
    ps->capacity = n;
}
```

```cpp
// test.cpp
#include"Stack.h"

int main()
{
    ST s1;
    STInit(&s1);

    // 确定知道要插入1000个数据，初始化时一把开好，避免扩容
    ST s2;
    STInit(&s2, 1000);
    return 0;
}
```

**讲解**：

- 默认值写在 `Stack.h` 的声明中。
- `Stack.cpp` 的定义中不再重复默认值。
- `STInit(&s1)` 使用 `n = 4`，`STInit(&s2, 1000)` 使用显式参数。

## 10. 函数重载

C++ 允许同一作用域中出现同名函数，只要形参列表不同。函数重载让调用更灵活。

可以构成重载：

- 参数个数不同。
- 参数类型不同。
- 参数类型顺序不同。

不能仅靠返回值不同构成重载，因为调用时可能无法根据返回值区分。

```cpp
#include<iostream>
using namespace std;

// 1、参数类型不同
int Add(int left, int right)
{
    cout << "int Add(int left, int right)" << endl;
    return left + right;
}

double Add(double left, double right)
{
    cout << "double Add(double left, double right)" << endl;
    return left + right;
}

// 2、参数个数不同
void f()
{
    cout << "f()" << endl;
}

void f(int a)
{
    cout << "f(int a)" << endl;
}

// 3、参数类型顺序不同
void f(int a, char b)
{
    cout << "f(int a,char b)" << endl;
}

void f(char b, int a)
{
    cout << "f(char b, int a)" << endl;
}

// 返回值不同不能作为重载条件，因为调用时也无法区分
//void fxx()
//{}
//
//int fxx()
//{
//    return 0;
//}

// 下面两个函数构成重载
// f()但是调用时，会报错，存在歧义，编译器不知道调用谁
void f1()
{
    cout << "f()" << endl;
}

void f1(int a = 10)
{
    cout << "f(int a)" << endl;
}

int main()
{
    Add(10, 20);
    Add(10.1, 20.2);
    f();
    f(10);
    f(10, 'a');
    f('a', 10);
    return 0;
}
```

**讲解**：

- `Add(10, 20)` 调用 `int` 版本。
- `Add(10.1, 20.2)` 调用 `double` 版本。
- `f(10, 'a')` 与 `f('a', 10)` 依靠参数顺序区分。
- `f1()` 和 `f1(int a = 10)` 虽然构成重载，但调用 `f1()` 时会与 `f1(10)` 产生歧义，实际项目中应避免这种设计。

### 10.1 函数重载补充

以下情况也值得注意：

- `void f(int& x)` 与 `void f(const int& x)` 参数类型不同，可以重载。
- `void f(int* p)` 与 `void f(int a)` 可以重载。
- 普通函数和模板函数也可能参与重载，但模板相关内容留到后续章节学习。
- 调用时如果存在多个都能匹配的重载，编译器可能报“有歧义”。

## 11. 引用

### 11.1 引用的概念和定义

引用不是新变量，而是给已有变量取别名。引用和被引用对象共用同一块内存。

```text
类型& 引用别名 = 引用对象;
```

```cpp
#include<iostream>
using namespace std;
int main()
{
    int a = 0;
    // 引用：b和c是a的别名
    int& b = a;
    int& c = a;
    // 也可以给别名b取别名，d相当于还是a的别名
    int& d = b;
    ++d;
    // 这里取地址我们看到是一样的
    cout << &a << endl;
    cout << &b << endl;
    cout << &c << endl;
    cout << &d << endl;
    return 0;
}
```

**讲解**：`a`、`b`、`c`、`d` 指向同一个地址。修改任何一个，都会影响同一个值。

### 11.2 引用的特性

1. 引用定义时必须初始化。
2. 一个变量可以有多个引用。
3. 引用一旦绑定一个对象，就不能再绑定其他对象。

```cpp
#include<iostream>
using namespace std;
int main()
{
    int a = 10;

    // 编译报错："ra": 必须初始化引用
    //int& ra;
    int& b = a;
    int c = 20;
    // 这里并非让b引用c，因为C++引用不能改变指向，
    // 这里是一个赋值
    b = c;
    cout << &a << endl;
    cout << &b << endl;
    cout << &c << endl;
    return 0;
}
```

**讲解**：`b = c` 不是让 `b` 改为引用 `c`，而是把 `c` 的值赋给 `b` 所引用的 `a`。因此 `&a` 与 `&b` 仍相同。

### 11.3 引用的使用

引用主要用于：

- 引用传参：减少拷贝，直接修改原对象。
- 引用返回值：提高效率，并允许通过返回引用修改原对象。

#### 示例 1：引用传参实现交换

```cpp
void Swap(int& rx, int& ry)
{
   int tmp = rx;
   rx = ry;
   ry = tmp;
}
int main()
{
   int x = 0, y = 1;
   cout << x <<" " << y << endl;
   Swap(x, y);
   cout << x << " " << y << endl;
   return 0;
}
```

**讲解**：调用 `Swap(x, y)` 时，`rx` 是 `x` 的别名，`ry` 是 `y` 的别名，因此交换发生在原变量上。

#### 示例 2：引用传参改造栈

```cpp
#include<iostream>
using namespace std;
typedef int STDataType;
typedef struct Stack
{
   STDataType* a;
   int top;
   int capacity;
}ST;

void STInit(ST& rs, int n = 4)
{
   rs.a = (STDataType*)malloc(n * sizeof(STDataType));
   rs.top = 0;
   rs.capacity = n;
}

// 栈顶
void STPush(ST& rs, STDataType x)
{
   assert(ps);
   // 满了， 扩容
   if (rs.top == rs.capacity)
   {
       printf("扩容\n");
       int newcapacity = rs.capacity == 0 ? 4 : rs.capacity * 2;
       STDataType* tmp = (STDataType*)realloc(rs.a, newcapacity * sizeof(STDataType));
       if (tmp == NULL)
       {
           perror("realloc fail");
           return;
       }
       rs.a = tmp;
       rs.capacity = newcapacity;
   }
   rs.a[rs.top] = x;
   rs.top++;
}

// int STTop(ST& rs)
int& STTop(ST& rs)
{
   assert(rs.top > 0);
   return rs.a[rs.top];
}

int main()
{
   // 调用全局的
   ST st1;
   STInit(st1);
   STPush(st1, 1);
   STPush(st1, 2);
   cout << STTop(st1) << endl;
   STTop(st1) += 10;
   cout << STTop(st1) << endl;
   return 0;
}
```

**讲解**：

- `STInit(ST& rs)` 使用引用传参，调用端不再需要 `&st1`。
- `int& STTop(ST& rs)` 返回栈顶元素的引用，所以 `STTop(st1) += 10` 可以修改栈中元素。
- 原课件代码有两处应特别注意：`STPush` 中 `assert(ps)` 的 `ps` 未定义；栈顶返回应返回 `rs.a[rs.top - 1]`。这里保留原代码是为了学习时练习纠错。

#### 示例 3：引用替代指针简化接口

```cpp
#include<iostream>
using namespace std;
typedef struct SeqList
{
    int a[10];
    int size;
}SLT;

// 一些主要用C代码实现版本数据结构教材中，使用C++引用替代指针传参，目的是简化程序，避开复杂的指针，但是很多同学没学过引用，导致一头雾水。
void SeqPushBack(SLT& sl, int x)
{}

typedef struct ListNode
{
    int val;
    struct ListNode* next;
}LTNode, *PNode;

// 指针变量也可以取别名，这里LTNode*& phead就是给指针变量取别名
// 这样就不需要用二级指针了，相对而言简化了程序
//void ListPushBack(LTNode** phead, int x)
//void ListPushBack(LTNode*& phead, int x)
void ListPushBack(PNode& phead, int x)
{
    PNode newnode = (PNode)malloc(sizeof(LTNode));
    newnode->val = x;
    newnode->next = NULL;
    if (phead == NULL)
    {
        phead = newnode;
    }
    else
    {
        //...
    }
}

int main()
{
    PNode plist = NULL;
    ListPushBack(plist, 1);
    return 0;
}
```

**讲解**：

- `LTNode*& phead` 等价于 `PNode& phead`，是对指针变量的引用。
- 修改 `phead` 会直接修改 `plist`，因此不再需要二级指针 `LTNode**`。

### 11.4 const 引用

要点：

- 引用 `const` 对象时必须使用 `const` 引用。
- `const` 引用可以引用普通对象，权限可以缩小。
- 普通引用不能引用 `const` 对象，否则是权限放大。
- 表达式结果、类型转换结果通常会产生临时对象；临时对象具有常性，必须使用 `const` 引用。

```cpp
int main()
{
   const int a = 10;
   // 编译报错：error C2440: "初始化": 无法从"const int"转换为"int &"
   // 这里的引用是对a访问权限的放大
   //int& ra = a;
   // 这样才可以
   const int& ra = a;
   // 编译报错：error C3892: "ra": 不能给常量赋值
   //ra++;
   // 这里的引用是对b访问权限的缩小
   int b = 20;
   const int& rb = b;
   // 编译报错：error C3892: "rb": 不能给常量赋值
   //rb++;
   return 0;
}
```

```cpp
#include<iostream>
using namespace std;
int main()
{
   int a = 10;
   const int& ra = 30;

   // 编译报错: "初始化": 无法从"int"转换为"int &"
   // int& rb = a * 3;
   const int& rb = a*3;
   double d = 12.34;
   // 编译报错："初始化": 无法从"double"转换为"int &"
   // int& rd = d;
   const int& rd = d;
   return 0;
}
```

**讲解**：

- `const int& ra = 30` 绑定的是临时对象。
- `const int& rd = d` 中，`double` 转 `int` 也会产生临时对象，因此需要 `const` 引用。
- `const` 引用延长了临时对象的生命周期。

### 11.5 指针和引用的关系

| 比较项 | 引用 | 指针 |
| --- | --- | --- |
| 概念 | 已有变量的别名，通常不额外开辟空间 | 保存地址的变量，通常需要空间 |
| 初始化 | 定义时必须初始化 | 建议初始化，语法上不是必须 |
| 重绑定 | 初始化后不能引用其他对象 | 可以改变指向 |
| 访问对象 | 直接访问 | 需要解引用 |
| `sizeof` | 结果为引用类型的大小 | 结果为地址大小，32 位通常 4 字节，64 位通常 8 字节 |
| 安全性 | 较少出现空引用、野引用问题 | 容易出现空指针、野指针 |

## 12. inline

`inline` 修饰的函数称为内联函数。编译器会在调用点尝试展开函数，从而减少建立函数栈帧的开销。

要点：

- `inline` 只是给编译器的建议，编译器可以选择不展开。
- 适合频繁调用的短小函数。
- 递归函数、代码较多的函数通常不适合内联。
- 主要目的是替代容易出错的 C 宏函数。
- 调试版本通常默认不展开内联，便于调试。
- 内联函数不建议声明与定义分离，否则可能出现链接错误。

### 12.1 内联函数示例

```cpp
#include<iostream>
using namespace std;
inline int Add(int x, int y)
{
    int ret = x + y;
    ret += 1;
    ret += 1;
    ret += 1;
    return ret;
}
int main()
{
    // 可以通过汇编观察程序是否展开
    // 有call Add语句就是没有展开，没有就是展开了
    int ret = Add(1, 2);
    cout << Add(1, 2) * 5 << endl;
    return 0;
}
```

### 12.2 宏函数的常见问题

```cpp
#include<iostream>
using namespace std;
// 实现一个ADD宏函数的常见问题
//#define ADD(int a, int b) return a + b;
//#define ADD(a, b) a + b;
//#define ADD(a, b) (a + b)
// 正确的宏实现
#define ADD(a, b) ((a) + (b))
// 为什么不能加分号?
// 为什么要加外面的括号?
// 为什么要加里面的括号?
int main()
{
    int ret = ADD(1, 2);
    cout << ADD(1, 2) << endl;
    cout << ADD(1, 2)*5 << endl;
    int x = 1, y = 2;
    ADD(x & y, x | y);  // -> (x&y+x|y)
    return 0;
}
```

**讲解**：

- 宏末尾加分号可能导致 `if`、表达式调用时多出分号。
- 外层括号保证整个表达式参与外层运算。
- 内层括号保证带运算符的参数不会改变优先级。
- 正确展开后，`ADD(x & y, x | y)` 实际是 `((x & y) + (x | y))`。
- 宏在预处理阶段替换，不方便调试；`inline` 函数保留类型检查，更安全。

### 12.3 inline 声明与定义分离

```cpp
// F.h
#include <iostream>
using namespace std;
inline void f(int i);
```

```cpp
// F.cpp
#include "F.h"
void f(int i)
{
    cout << i << endl;
}
```

```cpp
// main.cpp
#include "F.h"
int main()
{
    // 链接错误：无法解析的外部符号 "void __cdecl f(int)" (?f@@YAXH@Z)
    f(10);
    return 0;
}
```

**讲解**：内联函数需要在调用点看到完整定义。声明放在头文件、定义放在另一个源文件时，调用点无法展开，可能导致链接错误。简单做法是将完整定义放在头文件中。

## 13. nullptr

`NULL` 是宏。在不同语言模式下可能被定义为：

```cpp
#ifndef NULL
    #ifdef __cplusplus
        #define NULL    0
    #else
        #define NULL    ((void *)0)
    #endif
#endif
```

问题：

- C++ 中 `NULL` 可能是整数 `0`。
- 使用 `f(NULL)` 想调用指针重载时，实际可能调用整数版本。
- C++11 引入 `nullptr`，它是特殊关键字，可以转换为任意指针类型，但不能隐式转换为整数类型。

```cpp
#include<iostream>
using namespace std;
void f(int x)
{
   cout << "f(int x)" << endl;
}
void f(int* ptr)
{
   cout << "f(int* ptr)" << endl;
}
int main()
{
   f(0);

   // 本想通过f(NULL)调用指针版本的f(int*)函数，但是由于NULL被定义成0，调用了f(int x)，因此与程序的初衷相悖。
   f(NULL);
   f((int*)NULL);
   // 编译报错：error C2665: "f": 2 个重载中没有一个可以转换所有参数类型
   // f((void*)NULL);

   f(nullptr);
   return 0;
}
```

**讲解**：

- `f(0)` 调用整数版本。
- `f(NULL)` 在 C++ 中也常调用整数版本。
- `f((int*)NULL)` 显式转成 `int*` 后调用指针版本。
- `f((void*)NULL)` 无法自动转换为 `int*`，会产生重载匹配错误。
- 现代 C++ 应统一使用 `nullptr`。

| 空值写法 | 类型特性 | 现代 C++ 建议 |
| --- | --- | --- |
| `NULL` | 可能是宏 `0`，容易产生重载歧义 | 不推荐 |
| `0` | 整数字面量 | 空指针场景不推荐 |
| `nullptr` | 可转换为任意指针类型，不转换为整数 | 推荐 |

### 13.1 本章补充例题

> 本节例题为复习补充，并非原课件内容。

#### [补充例题·力扣] 88. 合并两个有序数组

出处：[LeetCode 88. 合并两个有序数组](https://leetcode.cn/problems/merge-sorted-array/)

题目：将 `nums2` 合并到 `nums1` 中，使结果仍为有序数组。

```cpp
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};
```

复杂度：

- 时间复杂度：`O(m + n)`
- 空间复杂度：`O(1)`

**讲解**：从 `nums1` 的尾部向前填写，避免覆盖尚未处理的前部元素。参数使用 `vector<int>&`，体现了引用传参。

#### [补充例题·力扣] 283. 移动零

出处：[LeetCode 283. 移动零](https://leetcode.cn/problems/move-zeroes/)

题目：将数组中的 `0` 移动到末尾，同时保持非零元素相对顺序。

```cpp
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int write = 0;

        for (int read = 0; read < nums.size(); ++read) {
            if (nums[read] != 0) {
                nums[write++] = nums[read];
            }
        }

        while (write < nums.size()) {
            nums[write++] = 0;
        }
    }
};
```

复杂度：

- 时间复杂度：`O(n)`
- 空间复杂度：`O(1)`

**讲解**：`write` 记录下一个非零元素写入位置，第一次扫描压缩非零元素，第二次扫描补零。整个过程只在原数组上操作。

#### [补充例题·牛客] BM17 二分查找-I

出处：[牛客 BM17 二分查找-I](https://www.nowcoder.com/practice/d3df40bd23594118b57554129cadf47b)

题目：在无重复数字的升序数组中找到目标值，存在则返回下标，否则返回 `-1`。

```cpp
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}
```

复杂度：

- 时间复杂度：`O(log n)`
- 空间复杂度：`O(1)`

**讲解**：每轮比较中点后排除一半搜索区间。`mid = left + (right - left) / 2` 可避免 `left + right` 溢出。

#### [补充例题·牛客] BM18 二维数组中的查找

出处：[牛客 BM18 二维数组中的查找](https://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e)

题目：在每行、每列都递增的二维数组中判断目标值是否存在。

```cpp
#include <vector>
using namespace std;

bool Find(int target, vector<vector<int> >& array) {
    if (array.empty() || array[0].empty()) {
        return false;
    }

    int row = 0;
    int col = array[0].size() - 1;

    while (row < array.size() && col >= 0) {
        if (array[row][col] == target) {
            return true;
        }
        if (array[row][col] > target) {
            --col;
        } else {
            ++row;
        }
    }

    return false;
}
```

复杂度：

- 时间复杂度：`O(m + n)`
- 空间复杂度：`O(1)`

**讲解**：从右上角出发，当前值大于目标时左移，小于目标时下移。每一步排除一整行或一整列。

### 13.2 复习自测清单

| 题目 | 平台 | 重点 |
| --- | --- | --- |
| 88. 合并两个有序数组 | [力扣](https://leetcode.cn/problems/merge-sorted-array/) | 引用参数、从后向前原地合并 |
| 283. 移动零 | [力扣](https://leetcode.cn/problems/move-zeroes/) | 引用参数、原地处理 |
| BM17 二分查找-I | [牛客](https://www.nowcoder.com/practice/d3df40bd23594118b57554129cadf47b) | `O(log n)`、边界控制 |
| BM18 二维数组中的查找 | [牛客](https://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e) | `O(m + n)`、逐步排除 |

### 13.3 本章复习速查

| 主题 | 核心结论 |
| --- | --- |
| 命名空间 | 用 `namespace` 隔离名称，项目推荐 `名称::成员` 访问 |
| 标准库 | C++ 标准库通常位于 `std` 命名空间 |
| 输入输出 | 使用 `cin/cout`，自动识别基本类型 |
| 大量 IO | 关闭同步、解绑 `cin/cout`，优先使用 `'\n'` |
| 缺省参数 | 只能从右向左连续缺省，声明与定义只能一处给默认值 |
| 函数重载 | 看参数个数、类型、顺序，不能只看返回值 |
| 引用 | 别名，定义必须初始化，不能重新绑定 |
| `const` 引用 | 可以缩小权限，不能放大权限；临时对象需要 `const` 引用 |
| `inline` | 编译器建议展开，适合短小频繁调用函数 |
| 空指针 | 现代 C++ 使用 `nullptr` |

复习时建议依次自问：

1. 为什么需要命名空间？
2. 缺省参数从哪一侧开始缺省？
3. 函数重载的依据是什么？
4. 引用与指针有什么区别？
5. `const int&` 为什么可以绑定临时对象？
6. `inline` 和宏函数有什么区别？
7. 为什么 C++11 要引入 `nullptr`？
