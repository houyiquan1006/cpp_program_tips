#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>

#include <random>
#include <ratio>
// #include <execution>
#include <chrono>

/******************** 泛型算法： 迭代器的分类  ********************************
* 1. 输入迭代器： 可读，可递增 —— 典型应用 find() 算法
* 2. 输出迭代器： 可写，可递增 —— 典型应用 copy() 算法
* 3. 前向迭代器： 可读写，可递增 —— 典型应用 replace 算法
* 4. 双向迭代器： 可读写，可递增递减 ——典型应用 reverse 算法
* 5. 随机访问迭代器： 可读写，可递增一个整数 —— 典型应用 sort 算法
* Tips: 一些算法会根据迭代器类别的不同引入相应的优化： 如：distance 算法

* 特殊的迭代器：
 1. 插入迭代器：back_insert_iterator / front_insert_iterator / insert_iterator
 2. 流迭代器：istream_iterator / ostream_iterator
 3. 反向迭代器：
 4. 移动迭代器： move_iterator
 5. 迭代器与哨兵：（Sentinel）

* 并法算法：
 1. std::execution::seq
 2. std::execution::par   建立一些现成去处理某些排序等泛型算法操作，添加在相关算法的形参即可
 3. std::execution::par_unseq
 4. std::execution::unseq

*/
       
int main()
{
    std::istringstream str("1 2 3 4 5");
    std::istream_iterator<int> x(str);  // 流迭代器
    std::istream_iterator<int> y{};   // 输入流迭代器，使用缺省的方式

    std::cout<< *x <<std::endl;

    ++x ; //可以递增
    std::cout<< *x <<std::endl;

    for(;x!=y;++x){
        std::cout<< *x <<" ";
    }
    std::cout<<std::endl;

    std::ostream_iterator<char> oo{std::cout};
    std::ostream_iterator<int> i1{std::cout,", "};
    std::fill_n(i1,5,-1);
    *oo++ = '\n';

    std::ostream_iterator<double> i2(std::cout,": ");
    *i2++ = 3.14;
    *i2++ = 2.71;
    *oo++ = '\n';


    std::random_device rd;

    std::vector<double> vals(10000000);
    for(auto& d:vals){
        d = static_cast<double>(rd());
    }

    // for(int i = 0 ;i<5 ;i++){
    //     using namespace std::chrono;
    //     std::vector<double> sorted(vals);
    //     const auto startTime = high_resolution_clock::now();
    //     std::sort(std::execution::unseq,sorted.begin(),sorted.end());
    //     const auto endTime = high_resolution_clock::now();
    //     std::cout<<" Latency: "
    //              << duration_cast<duration<double,std::milli>>(endTime - startTime).count()
    //              <<std::endl;
    // }


    return 0 ;
}