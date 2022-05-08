#include<iostream>

/***************   指针：一种间接类型  **********************
 * 特点：
 *      可以“指向”不同的对象；
 *      具有相同的尺寸；
 *
 * 相关操作：
 *      & 取地址符；
 *      * 解引用操作符； 
 *  
 * *******************************************************/

// 全局指针变量 ，系统默认会对其进行初始化为空指针，给其地址为 0（NULL），此时很特殊不可读其值 ：如 std::cout<< *pd <<std::endl; 将发生段错误 。
int *pd;   

int main()
{
    int x = 30 ;
    int y = 20 ;

    int *p = &x;
    std::cout<<" *p: "<<*p<<" p: "<<p<<std::endl;

    p=&y;
    std::cout<<" *p: "<<*p<<" p: "<<p<<std::endl;

    char a = 'c';
    char *pa;     // * 代表的 P 是一个指针对象 
    pa = &a;

    std::cout<<" &a: "<<(&a)<<" a: "<<a<<std::endl;
    std::cout<<" *pa: "<<*pa<<" pa: "<<pa<<std::endl;  // * 代表的是一个解引用符号  

    *pa = 'b';    // 通过 * 号，向指针比变量所指向地址 赋值（修改其值） 。
    std::cout<<" *pa: "<<*pa<<" pa: "<<pa<<std::endl;  // * 代表的是一个解引用符号  

    int *pe;      // 函数内部定义缺省的指针变量 ，系统会给其分配一个随机的地址，每次运行程序，地址都可能不相同。
    
    std::cout<<" pd: "<<pd<<std::endl;   // 未初始化，不可读其地址所指向的值，否则产生段错误
    std::cout<<" pe: "<<pe<<" *pe: "<<*pe<<std::endl;

    // 给指针初始化时，必须使用同一类型的变量对其初始化，之后才可以通过 赋值操作修改其指向地址所存储的 值 ；否则运行时候会产生段错误。
    int d = 40 ;
    int e = 50 ; 
    
    // *pd = 40;  
    // *pe = 50;
    pd = &d;
    pe = &e;
    std::cout<<" pd: "<<pd<<" *pd: "<<*pd<<std::endl;
    std::cout<<" pe: "<<pe<<" *pe: "<<*pe<<std::endl;

    // 使用对应类型对其初始化之后，才可以直接通过赋值操修改其所指向地址的真值 。
    *pd = 60;  
    *pe = 70;
    std::cout<<" pd: "<<pd<<" *pd: "<<*pd<<std::endl;
    std::cout<<" pe: "<<pe<<" *pe: "<<*pe<<std::endl;


    return 0;
}