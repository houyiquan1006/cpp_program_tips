#include<iostream>
#include<string>


/********** string:    *********************************
是c++ 标准库中定义的一个类模板特别化别名，用于内建字符串的代替品
与内建字符串相比，更侧重与易用性
    - 可复制、可在运行期间动态改变字符个数     （终究是通过牺牲性能换来的编程易用性）

构造与初始化
其他方法
    - 尺寸相关方法(size/empty)
    - 比较
    - 赋值
    - 拼接
    - 索引
    - 转换为 C 字符串


***************************************************/

int main()
{
    std::string x = "hello world";
    std::string y = x;

    // 字符串拼接
    // y = "hello world" + "!" ;  // 这种方法是错误的，可以用以下方式替换
    y = std::string("hello world")+"!";
    y = y + "!";
    std::cout<<y<<std::endl;   // print hello world!

    // 字符串的长度
    std::cout<<"string x size : "<<x.size()<<std::endl;

    // string 字符串的赋值
    y = "new string.";
    std::cout<<"new y: "<<y<<std::endl;

    auto ptr = y.c_str();   // 将string 转换为 c 字符串 char* z指针，并且指向字符串的首地址
    std::cout<<ptr<<std::endl;     // new string 
    std::cout<<*ptr<<std::endl;   // 单独指的是该字符串首地址的元素，即字符 ‘n'

    return 0;    
}