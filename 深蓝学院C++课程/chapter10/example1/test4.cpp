#include <iostream>
#include <functional>
#include <vector>

using namespace std::placeholders;

bool MyPredict(int val){
    return val > 3;
}

bool MyPredict2(int val1, int val2){
    return val1 > val2;
}

bool MyAnd(bool val1 , bool val2 ){
    return val1 && val2 ;
}

/***********************************    bind 表达式    ************************************************************
 * 1. 很多算法允许通过可调用对象自定义计算逻辑的细节
 *  - transform / copy_if / sort...
 * 2. 可调用对象
 *  - 函数指针：概念直观，但定义位置受限制；
 *  - 类： 功能强大，但书写麻烦;
 *  - bind : 基于 “已有的逻辑”  灵活配置，但描述复杂逻辑时语法可能会比较复杂难懂;
 *  - lambda 表达式：小巧灵活，功能强大;
 * 
 * 3. bind:  通过绑定的方式修改可调用对象的调用方式
 * 4. 早期的 bind 雏形： std::bind1st / std::bind2nd ; 
 *      - 具有 bind 的基本思想，但功能有限(一般只会使用一个参数的函数)
 * 5. std::bind (C++11 引入)：更加灵活的解决方案
 *  - 调用 std::bind 时，传入的参数会被复制，这可能会产生一些调用风险
 *  - 可以使用 std::ref 或 std::cref 避免复制的行为
 * 
 * 6. std::bind_front (c++ 20 引入) : std::bind 的简化形式
 ********************************************************************************************************/


int main()
{
    std::vector<int> x{1,2,3,4,5,6,7,8,9,0};
    std::vector<int> y;
    std::vector<int> z;

    std::copy_if(x.begin(),x.end(),std::back_inserter(y),MyPredict);      // 定义一个函数作为可调用对象

    for( auto &p : y ){ std::cout<<p<<" "; }
    std::cout<<std::endl;

    std::copy_if(x.begin(),x.end(),std::back_inserter(z),std::bind2nd(std::greater<int>(), 5));      // 定义一个函数作为可调用对象
    for( auto &p : z ){ std::cout<<p<<" "; }
    std::cout<<std::endl;

    /*************************************/
    auto m = std::bind(MyPredict2, _1 , 3 );      // 意思是： 将传入的第一个参数作为 val1 , 3 作为第二个参数 val2
    // auto m = std::bind(MyPredict2,std::placeholders::_1 , 3 );       // 这里的 _1 表示的是m()的形参作为 MyPredict 函数的第几个参数。
    std::cout<<m(50)<<std::endl;                        // 因为使用了 std::bind ,m(50) 即: MyPredict2( 50 , 3 )
    std::cout<<MyPredict2(50,3)<<std::endl;  

    auto n = std::bind(MyPredict2, _2 , _1 );     // std::bind(函数名， _2 , _1 ) 之后， 调用 n(v1 , v2 )  即等价于调用 MyPredict(v2, v1 ;
    std::cout<<n(3,2) <<std::endl;    // MyPredict(2 , 3 )  ，即 return 2 > 3


    auto x1 = std::bind(MyPredict2 , _1,3);
    auto x2 = std::bind(MyPredict2 , 10 , _1);
    auto x3 = std::bind(MyAnd, x1 , x2 );

    std::cout<<x3(5) <<std::endl;      // 相当于x1 =MyPredict(5 , 3 ) = true ; x2 = MyPredict(10 , 5 ) = true ;所以 x3 = MyAnd(5 , 10) = 1



    return 0;
}