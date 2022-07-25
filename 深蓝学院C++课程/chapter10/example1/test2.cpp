#include <iostream>
#include <vector>
/*****************************   泛型算法的分类   *******************************************************
 * 1. 读算法：给定迭代区间，读取其中的元素并进行计算；
    - std::accumulate / std::find / std::count
   2. 写算法：向一个迭代区间中写入元素
    - 单纯写操作：fill / fill_n
    - 读 + 写操作：transform / copy
    - 注意：写操作时，一定要保证输出区间足够大
   3. 排序算法： std::sort / std::unique(删除连续相同的元素，通常先 std::sort 之后再 std::unique)
 *********************************************************************************************************/

int main()
{
    std::vector<int> x{1,2,3,4,5};
    for(auto &p:x){ std::cout<<p<<" ";}
    std::cout<<std::endl;
    std::fill(x.begin(),x.end(),0);
    for(auto &p:x){ std::cout<<p<<" ";}
    std::cout<<std::endl;

    std::fill_n(x.begin(),5,2);   // 从 x.begin() 开始，所有的元素都fill为 2 ；
    for(auto &p:x){ std::cout<<p<<" ";}
    std::cout<<std::endl;

    std::fill_n(std::begin(x),5,3);  // 从 std::begin(x) 开始，将后面的 5 个元素全部置3
    for(auto &p:x){ std::cout<<p<<" ";}
    std::cout<<std::endl;
    return 0 ;
}