#include<iostream>
#include<type_traits>


/********** 数组--操作  *********************
求元素的个数：
    - sizeof()
    - std::size 方法      just for c++2a
    - (c)end-(c)begin 方法 just for c+2a

元素遍历：
    - 基于元素个数
    - 基于 (c)end/(c)begin
    - 基于 range -based for 循环

***************************************************/

int main()
{

    int a[3]={1,2,3};
    int b[]={1,2,3};
    auto c=a;  // 此时，类型已经弱化了，不再具备大小信息，无法求解大小。
    std::cout<<"a[3] size is: "<<sizeof(a)/sizeof(int)<<std::endl;  // 当改天把 数组类型变换之后，该求解数组大小的方式就不可取了。
    std::cout<<"a[3] size is: "<<std::size(a)<<std::endl;           // 具有更好的适应性，即便是数组大小或者类型变化值之后都是可以的。
    std::cout<<"a[3] size is: "<<std::cend(a) - std::cbegin(a)<<std::endl;    // 是一个运行时期的方法。

    std::cout<<"b[ ] size is: "<<std::size_t(b)<<std::endl;

    // 此时无论 数组 a 的长度或者是类型如何变化，该循环均可以运行。
    size_t index = 0;
    while (index < std::size(a) )
    {
        std::cout<<"a[index]: "<< a[index]<<std::endl;
        index ++ ;
    }
    
    auto ptr = std::cbegin(a);
    while(ptr != std::cend(a)) //或者是: while(ptr < std::cend(a))
    {
        std::cout<<"*ptr: "<<*ptr<<std::endl;
        ptr++;
    }
    // C++ 11 for 循环的新写法
    for(int x : a )
    {
        std::cout<<"range: "<<x<<std::endl;
    }

    return 0;    
}