#include <iostream>
#include <vector>
#include <algorithm>

/***************************** C++ 基础 -- 泛型算法  *******************************************************
 * 1.泛型算法： 可以支持多种类型的算法；
    - 重点讨论C++ 标准库中定义的算法 <algorithm>\<numeric>\<ranges>
    - 优点： 支持内建数据类型；计算逻辑存在相似性，避免重复定义；
    - 如何实现多种类型：使用迭代器作为算法与数据的桥梁；
   2. 泛型算法通常来说都不复杂，但优化足够好
   3. 一些泛型算法与方法同名，实现功能类似，此时建议调用方法而非算法：std::find V.S. std::map::find

 *********************************************************************************************************/

int main()
{
    std::vector<int> x{1,9,5,7,6,3,2,0};
    std::sort(std::begin(x),std::end(x));    // 默认从小到大排序
    for(auto p:x)
    {
        std::cout<<p<<" ";
    }
    std::cout<<std::endl;

    for(auto &p:x)    // 这样速度更快。
    {
        std::cout<<p<<" ";
    }
    std::cout<<std::endl;

    // 内建数据类型没有相关的方法读取首位等元素
    int y[15]={1,9,5,6,4,3,0};   // 可以对默认初始化的元素进行排序
    std::sort(std::begin(y),std::end(y));
    for(auto &p:y)    // 这样速度更快。
    {
        std::cout<<p<<" ";
    }
    std::cout<<std::endl;

    return 0 ;
}