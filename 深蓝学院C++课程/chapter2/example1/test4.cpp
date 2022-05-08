#include<iostream>
#include<limits>

/********** 类型详述——字面值及其类型 *********************
字面值：在程序中直接表示为一个具体的数值或字符串的值；
每个字面值都有其类型：
    整数字面值：20（十进制）、024（八进制）、0x14（十六进制）、--int型
    浮点数：1.3、1e8、--double 型
    字符字面值：‘c’、‘\n’ -- char 型
    字符串字面值：”Hello World!!! “ --字符数组
    布尔字面值：true 、false、--bool 型
    指针字面值：nullptr 、--nullptr_t 型
    
引入自定义的后缀
    user-define 自定义后缀 （类似 int16_t 的定义方法） 


***************************************************/
int operator "" _w(long double x)
{
    return (int)x * 2 ;
}

int main()
{
    char x;
    unsigned char y;
    signed char z;

    unsigned int ux = 1;
    unsigned ux1 = 1 ;       // unsigned int == unsigned   这个比较特殊。

    int u = 3.14_w;      // 此时 3.14_w = (int)6.28 = 6
    std::cout<<"u :"<<u<<std::endl;

    return 0;
    
}