#include<iostream>
#include<type_traits>

/*************** 类型别名与类型自动推导 **********************
可以引入类型别名，从而可以引入特殊含义或者便于使用，（如： size_t )
两种引入类型别名的方式：
    -typedef int val;     // 原始名称写在开头，新的名称写在结尾
    - using val = int (c++11 ) // 新的名称写在开头，老的名称写在结尾

类型别名与指针、引用的关系：
    - 应该将指针类型别名视为一个整体，在此基础上引入常量表示指针为常量的类型；
    - 不能通过类型别名构造引用的引用
**********************************************************/

typedef int myint;
using myint2 = int;   // C++11 标准

// 定义一个别名，该别名代表具有四个元素的 char 类型
typedef char mychararr[4] ;
using mychararr2 = char[4] ;    // C++11 标准

using RefInt = int& ;
using RefRefInt = RefInt& ;   // 不能通过类型别名构造引用的引用，其类型还是和 int& 是一致的 。

int main()
{
    myint x = 0 ;
    myint2 y = 2 ;

    std::cout<<"myint size: "<<sizeof(myint)<<std::endl;
    std::cout<<"myint2 size: "<<sizeof(myint2)<<std::endl;

    // 判断这两个类型是否一致,类型一致返回 1 ，不一致返回 0
    std::cout << std::is_same<int&, RefInt>::value <<std::endl;
    std::cout << std::is_same<RefRefInt, RefInt>::value <<std::endl;

    return 0;
}