#include <iostream>

/***************************** 异常处理 与 构造 析构函数之间的关系  *******************************************************
 * 1. 异常与构造、析构函数
 *  - 使用 function-try-block 保护初始化逻辑
 *  - 在构造函数中抛出异常
 *      - 已经构造的成员会被销毁，但本类本身的析构函数不会被调用；**** 因此需要做好相应的清理工作替代析构函数
 * 
 * 2. 描述函数是否会抛出异常
 *  - 如果函数不会抛出异常，则应表明以为系统提供更多优化空间
 *      - c++ 98 的方式：throw() / throw(int,char)
 *      - c++ 11 后的改进：noexcept / noexcept(false)
 * 
 * 3. noexcept(限定符)
 *  - 限定符： 接收 true /false 表示是否会抛出异常
 *  - 操作符： 接收一个表达式，根据表达式是否可能抛出异常返回 true /false 
 *  - 在声明了 noexcept 的函数中抛出异常会导致 terminate 被调用，程序终止
 *  - 不作为函数重载依据，但函数指针、虚拟函数重写时要保持形式一致
 * 
 *********************************************************************************************************/


void fun() noexcept     // 表示的是这个函数不会抛出异常
{

}

void fun2() noexcept(false)   // 显示的表示这个函数可能会抛出异常
{

}

void fun3()
{
    throw std::runtime_error("error input");    // 抛出一个异常， 运行期间的错误
}

int main()
{

    std::cout<< noexcept( fun() ) << std::endl;     // 不会抛出异常，所以返回的值是 true
    std::cout<< noexcept( fun2() ) << std::endl;   // 可能会抛出异常，所以返回的值是 false 
    

    try{
        fun3();
    }
    catch (std::runtime_error& e)
    {
        std::cout<< e.what() <<std::endl;    // 将抛出的异常捕获，并且将其中的内容打印出来
    }

    return 0 ;
}