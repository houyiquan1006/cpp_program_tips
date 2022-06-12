#include<iostream>
#include<cstring>

/********** 数组--c字符串 *********************
 - C 字符串本质上也是数组
 - C 语言提供了额外的函数来支持C字符串相关的操作： strlen,strcmp...

***************************************************/

int main()
{
    char str[]="Hello";  // 也是数组，但是字符串后面被隐式的添加了一个 “/0” 
    char str2[]={'H','e','l','l','o'}; // 也是数组，但是字符串后面没有添加 “/0” 
    char str3[]={'H','e','l','l','o','\0'}; // 也是数组，但是字符串后面显式添加 “/0” 
    auto ptr = str;   // ptr 的类型弱化为了 char*  ，因为后面有隐式添加的 结束符号，所以长度可求；
    auto ptr2 = str2; // ptr 的类型弱化为了 char*  ，因为后面没有添加 结束符号，所以长度不可求；
    auto ptr3 = str3; // ptr 的类型弱化为了 char*  ，因为后面有显式添加的 结束符号，所以长度可求；

    // 求解数组的长度
    std::cout<<"str[] length: "<<strlen(str)<<std::endl;
    std::cout<<"ptr[] length: "<<strlen(ptr)<<std::endl;

    std::cout<<"str2[] length: "<<strlen(str2)<<std::endl;  // 现在它的长度就不一定是 5 了，结果不一定正确，因为没有结束符号“\0”
    std::cout<<"ptr2[] length: "<<strlen(ptr2)<<std::endl;  // 现在它的长度就不一定是 5 了，结果不一定正确，因为没有结束符号“\0”

    std::cout<<"str3[] length: "<<strlen(str3)<<std::endl;  
    std::cout<<"ptr3[] length: "<<strlen(ptr3)<<std::endl;  

    return 0;    
}