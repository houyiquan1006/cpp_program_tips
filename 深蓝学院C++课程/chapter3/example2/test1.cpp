#include<iostream>
#include<vector>


/********** vector —— 序列容器之一 **********************
是C++ 标准中定义的一个类模板（后续会讲解）
与内建数组相比，更侧重于易用性：
    - 可复制、可在运行期间动态改变元素个数

构造与初始化：
    - 聚合初始化
    - 其他初始化方式

其他方法：
    - 获取元素的个数、判断是否为空
    - 插入、删除元素
    - vector 的比较

vector 中元素的索引与遍历
    - [] v.s. at
    - (c)begin / (c)end 函数，V.S. (c)begin / (c)end 方法
***************************************************/
int main()
{
    // vector 是c++ 的标准库std命名空间中的类模板，
    std::vector<int> x;    // 类型是 int ，对象名字为 x ，此时没有包含元素，个数为 0 。
    std::vector<int> y;    // 缺省初始化，包含的元素个数是 0 。
    y = x ;     // 可以直接复制，但损失的是性能

    int a[3] ={1,2,3} ; // 数组的聚合初始化
    std::vector<int> b = {1,2,3}; // 聚合初始化，但是更灵活，可以动态改变大小，可复制
    std::vector<int> d = {1,2,3};
    std::vector<int> e = {4,1,2};

    // 初始化 vector 的时候，直接给定大小
    std::vector<int> c[3]; // 此时，给定了 vector 的大小为 3，并且默认初始化为 0 。

    // 获取元素的个数
    std::cout<<"vector b size: "<<b.size()<<std::endl;

    // 判断vector对象是否为空
    std::cout<<"vector x empty? "<<x.empty()<<std::endl;

    // 插入与删除 vector 的成员元素
    b.push_back(4);
    std::cout<<"vector b size: "<<b.size()<<std::endl;

    // 删除首元素
    b.pop_back();
    std::cout<<"vector b size:  "<<b.size()<<std::endl;

    // vector 对象之间的比较
    std::cout<<"b ?= d "<< (b==d) <<std::endl ; // 仅仅是当 所有元素个数和元素大小都相同，那么两个 vector 对象才是相同的
    std::cout<<"b ?= e "<< (b==e) <<std::endl ;
    
    // 比较的规则是 逐项 比较，如果相同，则比较下一个元素，直到遇见不同的两个元素为止，得出比较结果。
    std::cout<<"e > b ?"<< (e>b) <<std::endl;   


    // vector 中元素的索引-通过[]获取某位标号的值,    
    std::cout<<"b[0]: "<<b[0]<<" b[1]: "<<b[1]<<" b[2]: "<<b[2]<<std::endl;

    // 通过这个方式可能会产生越界访问, 但是可以使用 at(num) 方法，可以避免，编译的时候会检查
    std::cout<<"b[0]: "<<b.at(0)<<" b[1]: "<<b.at(1)<<" b[2]: "<<b.at(2)<<std::endl;

    // vector 元素的遍历 

    // 使用 auto 指针遍历成员
    auto ptr = b.begin();
    while(ptr != b.end())
    {
        std::cout<<*ptr<<" ";
        ptr++;
    }
    std::cout<<std::endl;

    // 使用 for range 遍历成员
    for(auto x:b)
    {
        std::cout<<x<<" ";
    }
    std::cout<<std::endl;


    return 0;
}