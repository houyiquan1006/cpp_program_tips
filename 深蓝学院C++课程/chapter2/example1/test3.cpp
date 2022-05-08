#include<iostream>
#include<limits>

/********** 类型详情*********************
类型可以划分为基本类型和复杂类型
    基本（内建）类型： C++ 语言中所支持的类型；
        数值类型：
            字符类型：（char, char16_t, char32_t ）
            整数类型： 
                带符号整数类型： short 、int、long、long long ；
                无符号整数类型： unsigned + 带符号整数类型；
            浮点类型：
                float 、double 、long double；
        
        void：

    复杂数据类型：由基本数据类型组合、变种多产生的类型，可能是标准库引入，或者是自定义；

char : 是否带符号 ??
    C++ 中并没有规定char 是有符号还是无符号的，不同的编译器，规定不同；

整数在内存中的保存方式，大端？？   小端？？
    需要通过程序来测试，判读网络通信当中，双方的数据保存方式，后续强制转换；

C++11 中 引入了固定尺寸的 整数类型
    如： int32_t

***************************************************/
int main()
{
    char x;
    unsigned char y;
    signed char z;

    unsigned int ux = 1;
    unsigned ux1 = 1 ;       // unsigned int == unsigned   这个比较特殊。

    std::cout<<"char min-num: "<<(int)std::numeric_limits<char>::min()<<" ";
    std::cout<<"max-num: "<<(int)std::numeric_limits<char>::max()<<std::endl;

    std::cout<<"unsigned char min-num: "<<(int)std::numeric_limits<unsigned char>::min()<<" ";
    std::cout<<"max-num: "<<(int)std::numeric_limits<unsigned char>::max()<<std::endl;

    std::cout<<"signed char min-num: "<<(int)std::numeric_limits<signed char>::min()<<" ";
    std::cout<<"max-num: "<<(int)std::numeric_limits<signed char>::max()<<std::endl;

    return 0;
    
}