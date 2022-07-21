#include <iostream>
#include <array>
#include <type_traits>

/*****************************     容器: 序列容器  array  *******************************************************
 * 1. array : 元素个数固定的序列容器；
 * 2. vector: 元素连续存储的序列容器；
 * 3. forward_list / list: 基于链表 \ 双向链表的容器；
 * 4. deque: vector 与 list 的折中；
 * 5. basic_string: 提供对字符串专门的支持；
 * 6. 需要使用元素类型类实例化容器模板，从而构造可以保存具体类型的容器；
 * 7. 不同的容器所提供的接口大致相同，但根据容器性质的差异，其内部实现与复杂度不同；
 * 8. 对于复杂过高的操作，提供相对较难使用接口或者不提供相应的接口；
 * 
 * 
 * array 容器模板：具有固定长度的容器，其内部维护了一个内建数组，与内建数组相比提供了复制操作（数组变量是不能直接进行复制的）;
 * 提供的接口：
 *  - 构造（隐式的）；
 *  - 成员类型：value_type 等；
 *  - 元素访问：[] , at , front, back, data.
 *  - 容量相关（平凡实现）：empty ，size , max_size
 *  - 填充与交换：fill,  swap ;   有该功能，但是其内部实现的很困难，非常消耗资源，不建议使用;
 *  - 比较操作： < , > , = 。 有一个前提，其存储的元素需要支持比较，否则没有比较意义啦。
 *  - 迭代器
 *********************************************************************************************************/

int main()
{
    // 构造一个array 序列容器，固定长度为3，类型为 int；
    std::array<int,3> a = {1,2,3}; 

    // 成员类型
    std::cout<< ( ( std::is_same_v<std::array<int,3>::value_type,char> ) ? "int" : "char" ) << std::endl ;

    //元素访问 ，容量相关
    std::cout<<a.front()<<"  "<<a.back()<<"  "<< a.size()<<std::endl;
    std::cout<<a.at(0)<<"  "<<a.at(1)<<"  "<< a.at(2)<<std::endl;
    //std::cout<<a[4]<<std::endl;     // 超过长度 ，可能会越界而不报错，是未定义的，不安全。
    //std::cout<<a.at(4)<<std::endl;  // 安全操作，当超过长度限制的时候，会产生段错误而不会越界。
    int *b;
    b = a.data();                                     // array::data() 函数返回的是。
    std::cout<<*b<<"  "<<*(b+1)<<"  "<<*(b+2)<<std::endl;

    // 填充与交换
    a.fill(100);    // 将array 中的所有元素全换为 100

    // 比较：
    std::array<int,3> c={1,2,3};
    std::array<int,3> d={4,5,6};
    if(c > d)
        std::cout<<"c>d"<<std::endl;
    else if( c < d)
        std::cout<<"c<d"<<std::endl;
    else
        std::cout<<"c==d"<<std::endl;


    return 0 ;
}