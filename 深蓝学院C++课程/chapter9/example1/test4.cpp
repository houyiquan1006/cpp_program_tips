#include <iostream>
#include <forward_list> // 智能指针的头文件

/*****************************   容器：序列容器 forward_list  /  deque / list 的折中 ***************************
 * 1.  forward_list 容器模板：单向链表
 *  - 目标： 一个成本较低的线性表实现，因此，其具体实现的时候，每个 node 只包含最关键的信息，其余的均没有，所以有一些操作就不再被支持。
 *  - 其迭代器只支持递增操作，因此无： rbegin/rend 
 *  - 不支持 size
 *  - 不支持 pop_back / push_back  。 没有记录最后一个元素的指针，因此不支持往后面插入元素，弹出元素操作。
 *  - XXX_after 操作
 * 
 * 2. deque 容器模板： vector 与 list 的折中, 一个 node 包含多个元素，node 之间使用指针连接，该种结构使得随机插入元素比vector快，但是又没有 list 快。
 *  - push_back / push_front 速度较快
 *  - 在序列中间插入、删除速度较慢
 * 
 * 3. basic_string 容器模板： 实现字符串相关的接口
 *  - 使用 char 实例化出 std::string
 *  - 提供了如： find \ substr 等字符串特有的接口
 *  - 提供了数值与字符串转换的接口 （std::stoi \ std::stol \ std::stdoll ; XXX.to_string() ）
 *  - 针对短字符串的优化（short string optimization : SSO）
 * 
 ********************************************************************************************************/

int main()
{
    std::forward_list<int> a={1,2,3,4,5,6};    // 构造一个单向链表，并且操作只能递增，相当于一直只能往单向链表的后面走。

    

    return 0;
}