#include <iostream>
#include <string>
#include <string_view>
// #include <span>     // C++ 20 才有的 ,gcc高版本的编译器才支持
#include <vector>
#include <stack>
#include <queue>

// #include <ranges> 

/***********************  适配器与生成器 *******************************************
 *1、basic_string_view (c++17 )
 *  - 可以基于 std::string , C字符串，迭代器构造
 *  - 提供成本较低的操作接口，只能读，没有原始数据类型的所有权，通常作为函数的参数，不作为函数的返回值。
 *  - 不可进行写操作
 *
 *2、span (c++ 20 )
 *   - 可以基于 c 数组  、array等构造，是非字符串的；
 *   - 可读写；******
 * 
 * 3、接口适配器
 *  - stack / queue / priority_queue
 *  - 对底层序列容器进行封装，对外展现栈、队列与优先级队列的接口
 *  - priority_queue 在使用时，其内部包含的元素需要支持比较操作
 * 
 * 4、数值适配器（c++20 ） std::ranges::XXX_view , std::ranges::XXX , std::views::XXX
 *  - 可以将一个输入区间中的值变换后输出
 *  - 数值适配器可以组合，引入复杂的数值适配器逻辑
 * 
 * 5、生成器 （c++ 20 ）
 *  - std::ranges::itoa_view, std::
 * 
 **********************************************************************************/ 
void fun(std::string_view str)    // std::string_ view 更加具有适配性，可以适配 char* ,还可以适配 std::string
{
    // std::cout<<sizeof(std::string_view) <<std::endl;   // std::string_view 没有原始 string 或 char* 的所有权。
    if( !str.empty()) 
    {
        std::cout<<str[0]<<std::endl;
    }
}

// void fun2(std::span<int> input)
// {
//     for(auto p : input)
//     {
//         std:cout<<p<<" ";
//     }
//     std::cout<<std::endl;
// }


int main()
{
    fun("123456");     // C语言的 char* 类型
    fun(std::string("12345"));   // c++ 的std::string 类型

    // int a[3] = {1,2,3};
    // std::vector<int> s1{1,2,3};
    // fun2(a);
    // fun2(s1);

    std::stack<int , std::vector<int>> p;
    p.push(3);
    p.push(4);

    return 0;
}