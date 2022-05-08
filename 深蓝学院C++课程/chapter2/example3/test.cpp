#include<iostream>

/***************   常量类型与常量表达式 **********************
常量与变量相对，表示不可以修改的对象；
    使用 const 声明常量对象；
    是编译期的概念，编译器利用其：
        防止非法操作；
        优化程序逻辑；

常量指针与顶层常量（top-level const）：
    const int* p;
    int* const p
    const int* const p;
    常量指针可以指向变量 ；

**********************************************************/

int main()
{
    const int a = 30 ;  // 该常量不能再被修改;

    int c = 3 ;
    int d = 9 ;
    int* const ptr = &c ;   // 常量指针 ，可以指向一个变量，和引用有类似指出 ，
    // ptr = & d ; // 不能再次让 const 指针指向一个其他变量

    std::cout<<" ptr2: "<< *ptr <<std::endl;
    *ptr += 1 ;
    std::cout<<" ptr2 + 1: "<< *ptr <<std::endl;


    const int * ptr2 = & c ;
    //  *ptr2 = 5 ; // 这个是一个常量 int 指针变量，只是指向一个指针变量所指向的值，并不能修改其值，也不能再次修改其指向内存中的值，
    std::cout<<" ptr2: "<<*ptr2 <<std::endl;
    


    return 0;
}