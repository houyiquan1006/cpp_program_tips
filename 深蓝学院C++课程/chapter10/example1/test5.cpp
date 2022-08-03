#include <iostream>
#include <vector>
#include <functional>

/***********************************    lambda 表达式    **********************************************
 * 1.lambda 表达式 （https://leanpub.com/cpplambda）
 *  - 为了更灵活地实现可调用对象而引入
 *  - c++11 ~ c++20 持续更新
 *      c++11 引入 lambda 表达式
 *      c++14 支持初始化捕获、泛型 lambda 
 *      c++17 引入constexptr  lambda *this 捕获
 *      c++20 引入concepts ， 模板 lambda 
 *  - lambda 表达式会被编译器翻译成类进行处理
 *
 * 2. lambda 表达式的基本组成部分:  
    - 参数与函数体
    - 返回类型
    - 捕获：针对函数体中使用的局部自动对象进行捕获
        - 捕获值、引用捕获与混合捕获
        - this 捕获
        - 初始化捕获 （c++14 ）
        - *this 捕获（C++17 ）
    - 说明符
        - mutable / constexpr(C++17) / consteval(C++20)
    - 模板形参 （C++ 20）
 ********************************************************************************************************/


int main()
{
    // lambda 表达式的参数与语句体
    auto x = [](int val){return val > 3 ;};     // 最后的 ； 号是不可少的
    std::cout<< x(5) <<std::endl;

    // lambda 表达式的返回值自动推导
    auto y = [](int val){
        if(val > 3)
        {
            return 0;    // 此时可以自动推导返回值类型。
        }
        else
        {
            return 1;   // 所有的返回值都是同一个类型的，c++ 可以自动推导
        }
    };  //  ； 号 不能省略
    std::cout<< y(5) <<std::endl;

    // lambda 表达式的返回值类型的指定
    auto z = [](int val) -> double       // " -> double"  指定返回值的类型是 double 
    {
        if( val < 0)
        {
            return -1.f;     // 此时 1.f 和 1.6 类型不一致了，所以需要指定返回值类型
        }
        else
        {
            return 1.6;
        }
    };
    std::cout<< z(5) <<std::endl;

    // lambda 表达式的值捕获 ，static 或者全局类型的变量是不需要捕获的，可以直接使用，只有像这种局部的变量才是需要捕获的
    int value = 10 ;
    int value2 = 5;
    auto p = [value](int val)  // [] 捕获一个值，只用使用该符号 捕获某个变量的值，这样在 lambda 语句体中才能使用这个变量，语句体中操作不会改变原始的值
    {
        // ++value ;   // 这里的值捕获是一个拷贝，和原始的变量对象地址之间无关联
        return val > value;
    };
    std::cout<< p(5) <<" value: " << value <<std::endl;

    // lambda 表达式的引用捕获/混合捕获，那么在lambda 的语句体中对捕获的操作将会影响该值
    auto q = [&value,value2](int val)
    {
        value = value +value2;
        return val > value ;
    };
    std::cout<< q(5) <<" value: " << value <<std::endl;

    // lambda 初始化捕获,这里不是值捕获。定一个和 value 相同类型的 value ，并且使用 value 进行初始化。两个 alue 的归属是不冲突且不同的
    auto m = [value = value](int val)   // 初始化捕获可以提升程序的性能。
    {
        return val > value;
    };
    std::cout<< m(100) <<std::endl;

    return 0;
}