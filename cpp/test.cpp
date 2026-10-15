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
//顺序栈结构体定义
typedef struct Stack
{
    //动态数组指针，存栈内元素
    int* a;
    //栈顶标识，指向下一个可存放的元素的下标
    //同时代表栈内元素个数
    int top;
    //栈的容量
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
//元素入栈
void STPush(ST& rs, int x)
{
    //assert(ps)  //非空判断
    if(rs.capacity == rs.top)//满？
    {
        cout<<"扩容"<<endl;
        //新容量：原为 0 -> 4，非0 × 2
        int newcapacity = rs.capacity == 0 ? 4 : rs.capacity * 2;
        int* tmp = (int*)realloc(rs.a, newcapacity * sizeof(int));
        if(tmp == nullptr)
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
//栈顶元素显示
// int& STTop(ST& rs)
int STTop(ST& rs)
{
    // assert(rs.top > 0);
    return rs.a[rs.top - 1];
}

int main()
{
    ST st1;
    STInit(st1);
    STPush(st1, 1);
    STPush(st1, 2);
    STPush(st1, 3);
    cout << STTop(st1) << endl;

    return 0;
}
