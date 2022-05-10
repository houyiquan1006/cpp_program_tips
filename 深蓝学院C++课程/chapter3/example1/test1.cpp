#include<iostream>
#include<type_traits>


/********** 数组——引入 *********************
数组：将多个类型相同的数据串连在一起，所组成的类型；
    类型 变量名[exp]   : exp >= 1 ;

数组的初始化方式：
    - 缺省初始化：   int a[10] ;
    - 聚合初始化：   int b[3]= {1,2,3} ;   // 未完全初始化的部分，系统会用 0 替代 ；

注意事项：
    - 不能使用 auto 来声明数组类型 ；
    - 数组不能复制 ；
    - 元素个数必须是一个常量表达式（编译期可计算的值） ；
    - 字符串数组的特殊性 ；

***************************************************/
int main()
{
    int a;     // 类型是 int
    int b[10]; // 类型是 int[10]
    // 通过类型判断API 检验变量的类型
    std::cout<<std::is_same<int[10],decltype(b)>::value<<std::endl;

    const int num = 3 ;

    int c[num] ;
    std::cout<<"number of the arry c: "<<sizeof(c) / sizeof(int)<<std::endl;   // 验证定义的数组大小是 3 ，和 说明 常量表达式或者说数字是可以作为 数组内部的大小的

    char str[] = "hello";    // 其有一个特殊性，其后面默认会添加一个 结束字符 ‘/0’ ，因此，其类型是 char[6]
    char str2[] = {'H','e','l','l','o'};  // 

    std::cout<<std::is_same<char[6],decltype(str)>::value <<std::endl;
    std::cout<<std::is_same<char[5],decltype(str2)>::value <<std::endl;


    return 0;
    
}