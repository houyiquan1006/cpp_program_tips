#include <iostream>

/***************************** 面向对象编程 -- 结构体与对象聚合  *******************************************************/

//结构体的声明
struct Str; 

// 结构体定义 ,只要是使用就必须在该cpp文件中至少出现一次定义。
struct Str{
    int x;
    int y;
    char c;
};

// 结构体的已定义类型    将该结构体类型定义为 Mstr 类型
typedef struct mstr {
    int x;
    int y;
    char a;
} Mstr;

// 函数可以只有一个声明，别的文件中书写定义；但是结构体不行，每个使用到的cpp文件中必须有该结构体的定义。
void fun();

int main()
{
    Str mstr{1,2,'a'};      // 结构体的聚合初始化
    std::cout<< mstr.x << " "<<mstr.y<<" "<< mstr.c<<std::endl;

    fun();

    Str ystr{.x=1,.y=2, .c='a'};   // c++ 中新增的 指派初始化方式
    std::cout<< ystr.x << " "<<ystr.y<<" "<< ystr.c<<std::endl;

    return 0 ;
}
