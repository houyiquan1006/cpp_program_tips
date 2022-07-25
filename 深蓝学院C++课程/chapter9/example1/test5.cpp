#include <iostream>
#include <memory> // 智能指针的头文件
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <set>

/***********************  容器：关联容器  set \ map .......  *******************************************
 *1、关联容器可以分为两类：
 *  -  set \ map \ multiset \ multimap 底层使用红黑树实现；
 *  -  unordered_xxx 底层使用hash表实现；
 * 
 * 2、 set: 
 *  - 通常来说，元素需要支持使用  < 比较大小，因为使用的红黑树作为实现方式，不然不知道放置在红黑树的什么地方。
 *  - 或者采用自定义的比较函数来引入大小关系
 *  - 插入元素： insert / emplace / emplace_hint
 *  - 删除元素：erase      删除set表中已有的元素，
 *  - 访问元素：find / contains ， find: 查找set关联容器中的某个值，若有该值即会返回该值 ，若没有则会返回 set中最后的一个值。
 *  - 修改元素：extract ，因为需要保持红黑树的结构特征，不能随便修改节点的值，需要使用特殊的方法，修改值会重新排布红黑树每个节点的值。
 *  - set 迭代器所指向的对象是 const 的，不能通过其修改元素；
 * 
 * 3、map :
 *  - 树中的每一个结点是一个 std::pair
 *  - 键(pair.first)需要支持使用 < 比较大小
 *  - 或者采用自定义的比较函数来引入大小关系
 *  - 访问元素：find / contains / [] / at , 通过at(键值) 访问元素，若没有则会出现异常，以保证不会出现未定义的动作。
 *  -  注意
 *      - map 迭代器所指向的对象是 std::pair ，其键是 const 类型
 *      - [] 操作不能用于常量对象
 * 
 * 4、multiset / multimap
 *  - 与 set / map 类似，但允许重复的键
 *  - 元素访问
 *          - find 返回首个查找的到的元素
 *          - count 返回元素个数
 *          - lower_bound / upper_bound / equal_range 返回查找到的区间
 **********************************************************************************/ 

struct Str{
    int x;
};

bool Mycomp(const Str& val1 , const Str& val2)
{
    return val1.x > val2.x ;
}

void fun(const std::map<int,bool>& m)
{
    // m[3]  , 在函数中不能这样写，因为这是编译期间的行为，而不是运行期间
    auto ptr = m.find(3);    // 在传入的关联容器中查找键为 3 的元素，如果有则返回，没有则执行别的操作。
    if(ptr != m.end() )
    {
        std::cout<<ptr->second<<std::endl;
    }
    else
    {
        std::cout<<"can not find this value."<<std::endl;
    }
}


int main()
{
  std::cout<< "*************************     1      *************************** /n "<<std::endl;
    // 关联容器 set
    std::set<int> s{100,3,56,7};    // 键是其中的每个元素，值是 0 或者 1 ，即是否有该元素。与此同时，set中的元素不能重复，在使用size() 求解set大小的时候，相同部分只会计数一次
    // 根据红黑树的特征存储实际数值，左子树小于右子树的值，故遍历 set 的时候，s 的值应该是  3  7 56 100
    for(auto ptr = s.begin() ; ptr!=s.end() ; ++ptr) { std::cout<<*ptr<<" "; }      // set 默认使用 中序遍历
    std::cout<<std::endl;

    // 使用 std::greater<>修改遍历时候的大小打印关系
    std::set<int, std::greater<int>> s2{3,100,56,7};
    for(auto ptr = s2.begin() ; ptr!=s2.end() ; ++ptr) { std::cout<<*ptr<<" "; }      // set 默认使用 中序遍历
    std::cout<<std::endl;

    // 自定义set 中的大小比较方法,并生成一个关联容器。
    std::set<Str, decltype(&Mycomp) > s3( {Str{3}, Str{5}}, Mycomp);
    s3.insert(Str{100});
    
    for(auto ptr = s3.begin() ; ptr!=s3.end() ; ++ptr) { std::cout<<ptr->x<<" "; }      // set 默认使用 中序遍历
    std::cout<<std::endl;

    s3.emplace(Str{100});     // 插入的元素和现有相同，不会插入。
    for(auto ptr = s3.begin() ; ptr!=s3.end() ; ++ptr) { std::cout<<ptr->x<<" "; }      // set 默认使用 中序遍历
    std::cout<<std::endl;

    s3.erase(Str{100});
    for(auto ptr = s3.begin() ; ptr!=s3.end() ; ++ptr) { std::cout<<ptr->x<<" "; }      // set 默认使用 中序遍历
    std::cout<<std::endl;

    s3.erase(Str{3});   // erase 删除的是 set 关联容器中值为3的键
    for(auto ptr = s3.begin() ; ptr!=s3.end() ; ++ptr) { std::cout<<ptr->x<<" "; }      // set 默认使用 中序遍历
    std::cout<<std::endl;

    s3.erase(Str{10});   // erase 删除的是 set 关联容器中值为10的键，因为没有该值，所以没对 set 关联容器做修改。
    for(auto ptr = s3.begin() ; ptr!=s3.end() ; ++ptr) { std::cout<<ptr->x<<" "; }      // set 默认使用 中序遍历
    std::cout<<std::endl;

    /*************************************************************************************************************/


  std::cout<< "*************************     2      *************************** /n "<<std::endl;
    std::map<int,bool> m{{1,false}};
    m.insert(std::pair<const int,bool>(2, false));   // 插入元素，其第一位(键)，必须为const int 类型（可比较）
    for(auto p : m) { std::cout<<p.first << " "<<p.second<<std::endl; }
    m.erase(1);
    for(auto& [k,v] : m) { std::cout<<k<< " "<<v<<std::endl; }
    
    // [] 操作：当键没有 100 的时候，map 关联容器会自动新建节点，然后融入到map关联容器中，其键为 100 ，值为int类型的 0 。
    // [] 操作：其是一个运行期的操作，不可以写在编译器，即不建议在 main 之外的函数中使用。
    std::cout<<m[100]<<std::endl;    
    for(auto& [k,v] : m) { std::cout<<k<< " "<<v<<std::endl; }

    fun(m);
    m.insert({3,false});    
    fun(m);


    std::cout<< "*************************     3      *************************** /n "<<std::endl;
    std::multiset<int> multi_s{1,3,1};
    for(auto i : multi_s ){ std::cout<< i <<" ";}    // 仍然采用的是 红黑树的存储方式
    std::cout<<std::endl; 

    auto ptr2 = multi_s.find(1);
    ptr2++;  // 因为 multset 关联容器有两个 1 元素，此处返回的是第一个 1 元素，所以即使++操作之后，还是1
    std::cout<<*ptr2<<std::endl;

    for(auto i : multi_s ){ std::cout<< i <<" " ;}
    std::cout<<std::endl;

    // 键为1的元素区间
    auto b = multi_s.lower_bound(1);
    auto e = multi_s.upper_bound(1);
    for(auto ptr = b ; ptr != e ; ++ptr)
    {
        std::cout<<*ptr<<std::endl;   // 打印该区间的值
    }

    return 0;
}





/* 
红黑树：
    二叉树中，所有非叶子节点中，左子树的值都小于右子树，且左右分支最多相差一层。
这种左右大小特征一致的情况，在查找数据的时候可以很快查找（二分法查找）。




*/