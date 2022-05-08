#include<iostream>
#include<limits>


/********** 类型描述  *********************
类型详述：
    类型是一个编译期间的概念，可执行文件中不存在类类型的概念，
    c++ 是强类型语言；
    引入类型是为了更好的描述程序，防止误用；
    类型描述了：    
        存储所需要的尺寸；
        取值空间（超过可能会移除）
        对齐信息；(alignof)——结构体的字节数.
        可执行的操作；

std::numeric_limits 为模板类，在编译平台提供基础算术类型的极值等属性信息，
    取代C语言中的所采用的预处理常数。常用于判断给定的基础类型在当前系统上的最大值、最小值。
    使用的时候需要包含 <limits> 头文件。

***************************************************/

struct Str{
    char b;  // 1个字节
    int x;   // 4个字节
};

struct Str2{
    char b;
    double z;
};

struct Str3{
    int x;
    double z;
};

struct Str4{
    char b;
    int x;
    double z;
};

int main()
{
    int x = 10 ;   // 初始化语句，声明一个变量(对象)，其是一个整型
    char y = 'a';  // 定义一个字符类型变量

    std::cout<<sizeof(int)<<std::endl;   // 四个字节，4*8bit ～ 【-2^31， 2^31 -1 】
    std::cout<<sizeof(x)<<std::endl;     // 四个字节，在存储的时候是按照4为基础递增递减的

    std::cout<<sizeof(char)<<std::endl;  // 一个字节
    std::cout<<sizeof(y)<<std::endl;     // 一个字节

    std::cout<<std::numeric_limits<int>::min()<<std::endl;   // int 可以存储的最小数值是 -2147483648
    std::cout<<std::numeric_limits<int>::max()<<std::endl;   // int 可以存储的最大数值是 2147483647

    std::cout<<(int)std::numeric_limits<char>::min()<<std::endl;     // 特殊的操作，前面需要家一个（int）强制类型符号。
    std::cout<<(int)std::numeric_limits<char>::max()<<std::endl;

    std::cout<<"char alignof: "<<alignof(char)<<std::endl;      //对齐信息，1
    std::cout<<"int alignof: "<<alignof(int)<<std::endl;        //对齐信息，4
    std::cout<<"double alignof: "<<alignof(double)<<std::endl;  //对齐信息，8

    Str str;
    std::cout<<"Str sizeof: "<<sizeof(Str)<<std::endl;    // 按照前面的意思 char + int 的字节总数是 5，但是因为对其信息，其大小是 4+4 = 8 ；对其大的部分

    Str2 str2;
    std::cout<<"Str2 sizeof: "<<sizeof(Str2)<<std::endl;    // 按照前面的意思 char + double 的字节总数是 9，但是因为对其信息，其大小是 8+8 = 16 ；对其大的部分
    
    Str3 str3;
    std::cout<<"Str3 sizeof: "<<sizeof(Str3)<<std::endl;    // 按照前面的意思 int + double 的字节总数是 12，但是因为对其信息，其大小是 8+8 = 8 ；对其大的部分

    Str4 str4;
    std::cout<<"Str4 sizeof: "<<sizeof(Str4)<<std::endl;    // 按照前面的意思 char + int + double 的字节总数是 13，但是因为对其信息，其大小是 4+4+8 = 16 ；对其大的部分


    return 0;
    
}