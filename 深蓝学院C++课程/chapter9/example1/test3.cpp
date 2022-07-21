#include <iostream>
#include <list>

/********************   容器：序列容器 list   ********************************
 * 1. list 容器模板：双向链表，与 vector 相比，list具有：
 *  - 插入、删除成本较低，改一下头和尾指针即可。但随机访问成本较高；
 *  - 提供了pop_front / splice 接口，将list开头的元素弹出，并且缩小list 的大小 / 
 *  - 写操作通常不会改变迭代器的有效性；
 ***********************************************************/ 


int main()
{
    // list 是由双向链表构成的，分别有两个指针分别指向 list 的起始和结束位；
    std::list<int> a={1,2,3};
    for (auto ptr = a.begin(); ptr != a.end() ; ++ptr)
    {
        std::cout<<*ptr<<" ";
    }
    std::cout<<std::endl;


    a.pop_front();
    for (auto ptr = a.begin(); ptr != a.end() ; ++ptr)
    {
        std::cout<<*ptr<<" ";
    }
    std::cout<<std::endl;

    return 0 ;
}