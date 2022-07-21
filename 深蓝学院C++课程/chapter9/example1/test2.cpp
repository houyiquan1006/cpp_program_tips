#include <iostream>
#include <vector>


/*****************************     容器：序列容器 vector    *******************************************************
 * 1. vector 容器模板：元素数量可变
 std::vector<T> : 其包含属性：（当前大小）size_t size ,  （该vector 的最大大小）size_t cap ,  （存储实际值的指针）T* buffer 通过预先分配内存来提升调用效率。

 * 2. 提供的接口：
 *  - 与 array 相似，但有其特殊性；
 *  - 容量相关接口： capacity / reserve / shrink_to_fit
 *  -  附加元素接口： push_back / emplace_back
 *  - 元素插入接口： insert / emplace , 从某个位置插入值。
 *  - 元素删除接口： pop_back / erase  / clear ，删除最后一个元素（无损耗），删除指定位置的元素（消耗比较大，可能导致需要将后面的元素往前挪动）/ 删除所有元素
 * 3. 注意：
 *  - vector 不提供push_front / pop_front ，可以使用insert /erase 模拟，但是效率不高。
 *  - swap 下来效率最高
 *  - 写操作可能会失效，比如正在往其中插入元素的时候。
 *********************************************************************************************************/

int main()
{ 
    std::vector<int> a{1};   // 和 std::array 相比，构造该类型对象的时候，不需要指定大小，其大小是动态变化的。
    std::cout<<a.size() << " "<<a.max_size() <<std::endl;    // 当前大小 / 后期最大可扩充的大小 

    std::vector<int> b;
    b.reserve(1024);  // 指定该对象的元素数量为：1024
    std::cout<<b.size() << "  "<<b.max_size()<<std::endl;

    // 元素插入
    std::vector<std::string> c;
    c.push_back("hello");   //内部使用: C字符串 转 string ，然后再末尾插入；
    c.emplace_back("hello");     // 直接插入，相比 push_back 少了一次对象的拷贝或移动；
    std::cout<<c.at(0)<<" " <<c.at(1)<<std::endl;


    //  元素交换
    a.swap(b);  // 之后，a的buffer指针指向的是b原来的buffer指针，bbuffer指针指向的是原来 a buffer 的指针；



    return 0 ;
}