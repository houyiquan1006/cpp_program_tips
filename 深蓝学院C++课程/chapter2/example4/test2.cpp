#include<iostream>
#include<type_traits>

/***************   类型的自动推导  **********************
从C++11 开始，可以通过初始化表达式自动推导对象类型
自动推导类型并不意味着弱化类型，对象还是强类型；
自动推导的几种常见形式：
    - auto :最常见的形式，但是会产生  “类型退化”
    - const auto / constexpr auto 推导出常量 / 常量表达式
    - auto& ：推导出引用类型，避免类型退化
    - decltype(exp) 返回exp 表达式的类型号（左值加引用）
    - decltype(val) 返回val 的类型
    - decltype(auto) 从C++ 14开始，简化 decltype 使用
    - concept auto 从C++ 20 开始支持，表示一系列类型 (std::integral auto x = 3)




************************************************************/



int main()
{
    int x = 3.5 + 15l ;  // 15l 是 long 类型，int + long 类型 ==> 
    auto d = 3.5 + 15l ;  // auto 是一个自动推导的类型，其将根据 = 后面的类型决定，主要参考不丢失精度为主，及默认用最高数据精度的类型
    std::cout<< "d: "<<d <<std::endl;

    // auto 类型自动推导时必须至少有一个作为参照，否则没有依据， 无法推导，因此还是一个强类型
    auto y = "123456" ;
    std::cout<<"y: "<<y <<std::endl;

    // auto 会产生类型退化
    int x1 = 5;
    int& ptr = x1;
    auto ptr2 = ptr ;  // int& 类型退化成了 int ；
    auto& ptr3 = ptr ; // auto 加上& 之后，就不会产生类型退化 ；

    std::cout<<std::is_same<int,decltype(ptr2)>::value <<std::endl;   
    std::cout<<std::is_same<int&,decltype(ptr2)>::value <<std::endl;

    std::cout<<std::is_same<int,decltype(ptr3)>::value <<std::endl;   
    std::cout<<std::is_same<int&,decltype(ptr3)>::value <<std::endl;

    int x2[3] = {1,2,3};  // 数组默认也会产生类型退化，但是 /使用 auto& 就会避免类型退化
    auto x3 = x2;
    auto& x4 = x2;

    std::cout<<std::is_same<int*,decltype(x3)>::value <<std::endl;   
    std::cout<<std::is_same<int(&)[3],decltype(x4)>::value <<std::endl;

    // decltype(exp) 该关键字将返回 exp 的类型 .
    decltype(x1) ptr4 = x1 ;   // 该关键字强调了 在自动类型推导的过程中，不会产生类型退化
    std::cout<< std::is_same<int,decltype(ptr4)>::value<<std::endl;

    // decltype(vel) // 将自动推导表达式的类类型，如下所示：
    std::cout<< std::is_same<double,decltype(3.5+5l)>::value<<std::endl;   // 1  decltype(3.5+5l) = double
    std::cout<< std::is_same<double,decltype(3.5)>::value<<std::endl;      // 1  decltype(3.5) = double
    std::cout<< std::is_same<int,decltype(5)>::value<<std::endl;           // 1  decltype(5) = int
    std::cout<< std::is_same<long,decltype(5l)>::value<<std::endl;         // 1  decltype(5l) = long
    


    return 0;
}