#include<iostream>
using namespace std;

// int main(){cout<<"Hello World!\n";}

//示例 1：引用传参实现交换
// void swap(int& rx, int& ry){
//     int tmp = rx;
//     rx = ry;
//     ry = tmp;
// }
// int main(){
//     int x = 9, y = 1;
//     cout<<x<<' '<<y<<endl;
//     swap(x, y);
//     cout<<x<<' '<<y<<endl;
// }

//示例 2：引用传参改造栈
typedef struct Stack
{
    int* a;
    int top;
    int capacity;
}ST;
//初始化栈（rs 为待初始化栈的引用，n 为栈的大小，默认为4）
void STInit(ST& rs, int n = 4)
{
    //a为栈首地址，malloc返回int类型指针，指向一段连续空间，大小为n个int的大小
    rs.a = (int*)malloc(n * sizeof(int));
    rs.top = 0;
    //栈的元素为 n 个
    rs.capacity = n;
}


//