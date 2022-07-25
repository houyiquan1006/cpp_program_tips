#include <iostream>
#include <memory> // 智能指针的头文件
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <unordered_set>

/***********************  容器：关联容器  unordered_set / ....._map / ....._multiset / ...._multimap  *******************************************
 *1、与 map /set 相比查找性能更好，哈希表来实现的，其元素的存储顺序和红黑树有差异
    2、但插入操作一些情况下会慢
    3、其键需要支持两个操作
        - 转换为 hash 值 （通过一个哈希函数）
        - 判等
    4、除 == ， != 外，不支持容器级的关系运算
           但 == ， != 速度较慢
           自定义 hash 与判等函数，
 **********************************************************************************/ 

int main()
{
    std::unordered_set<int> s{3,1,5,4,1};
    for(auto ptr : s ){ std::cout<<ptr<<" \t";}

    return 0;
}





/* 
哈希表：
    一种数据存储的方法，




*/