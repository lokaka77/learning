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
/*
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
*/
//const引用要点：
// 引用 const 对象时必须使用 const 引用。
// const 引用可以引用普通对象，权限可以缩小。******
// 普通引用不能引用 const 对象，否则是权限放大。
// 表达式结果、类型转换结果通常会产生临时对象；
//临时对象具有常性，必须使用 const 引用。******

//const引用：只读
//普通引用：读写
//const对象：只读
//普通对象：读写

//[补充例题·力扣] 88. 合并两个有序数组

//开新数组
/*class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums(n+m, 0);
        for(int i = 0, j = 0, k = 0; i < n + m; i++){
            if(j < m && k < n){
                if(nums1[j] <= nums2[k]){
                    nums[i] = nums1[j++];
                }
                else{
                nums[i] = nums2[k++];
                }
            }
            else{
                if(j==m){
                    nums[i] = nums2[k++];
                }
                else{
                nums[i] = nums1[j++];
                }
            }
        }
        for(int i = 0; i<m+n; i++){
            nums1[i]=nums[i];
        }        
    }
};*/

//双指针逆序


// [补充例题·力扣] 283. 移动零
/*class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0, n = 0;
        for(int i = 0, tmp = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                n++;
            }
            else{
                tmp = nums[i];
                nums[j++] = tmp;
            }
        }
        while(n--){
            nums[j++] = 0;
        }
    }
};*/