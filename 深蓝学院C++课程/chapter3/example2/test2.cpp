#include<iostream>
#include<vector>


/********** vector: itear 迭代器  *********************
迭代器：
    - 模拟指针的行为
    - 包含多种类别，每种类别支持的操作不同
    - vector 对应随机访问迭代器
        · 解引用与下标访问
        · 移动
        · 两个迭代器相减求距离
        · 两个迭代器比较

vector 相关的其他内容：
    - 添加元素可能使迭代器失效
    - 多维 vector 
    - 从 . 到 -> 操作符
    - vector 内部定义的类型
        · size_type
        · iterator / const_iterator


***************************************************/

int main()
{
    std::vector<int> x1={1,2,3};
    auto b = std::begin(x1);

    // 通过解引用访问元素的值
    std::cout<<"vector values: "<<*b<<" "<<*(b+1)<<" "<<*(b+2)<<std::endl;
    // 通过下标访问元素的值
    std::cout<<"vector values: "<<b[0]<<" "<<b[1]<<" "<<b[2]<<std::endl;

    // 移动 / 交换 值
    int temp  = b[0];
    b[0] = b[2];
    b[2] = temp ;
    // 通过下标访问元素的值
    std::cout<<"vector values: "<<b[0]<<" "<<b[1]<<" "<<b[2]<<std::endl;

    int temp2  = *b;
    *b = *(b+2);
    *(b+2) = temp2 ;
    // 通过解引用访问元素的值
    std::cout<<"vector values: "<<*b<<" "<<*(b+1)<<" "<<*(b+2)<<std::endl;

    // vector 元素相减 求解元素之间的距离
    auto begin = std::begin(x1);
    auto end = std::end(x1); 
    std::cout<<"vector distance: "<< end - begin <<std::endl;
    auto begin_value = x1.begin() ;    // 指的是 x1 这个 vector 对象的首元素 ,因为是auto ，所以类型全部弱化为 指针类型，需要解引用符号 get 其值
    auto end2_value = x1.end() ;        // 指的是 x1 这个 vector 对象的尾元素
    std::cout<<"begin_value: "<<*begin_value<<" end_value: "<<*end2_value<<std::endl;

    // 迭代器之间的比较，需要两个迭代器都指向同一个 vector 


    // 二维的 vector ，操作元素之后，可能使得原来的迭代器失效。
    std::vector<std::vector<int>> xx;

    xx.push_back(std::vector<int>());  // 使用缺省初始化的方式初始化多维 vector 对象
    xx[0].push_back(1);
    std::cout<<"vector<vector>: "<<xx[0][0]<<std::endl;

    // 直接使用聚合初始化方式给 多维 vector 赋值
    std::vector<std::vector<double>> yy = {{1.2,2.3,3.4,4.5},{2.1,3.2,4.3} };
    std::cout<<"yy[1][2]: "<<yy[1][2]<<std::endl;

    // 从 . 到 ->
    std::vector<int> mm;
    std::vector<int> *nn;
    nn = &mm;

    std::cout<<"vector mm size: "<<mm.size()<<std::endl;
    std::cout<<"vector mm size: "<<(*nn).size()<<std::endl; 
    // 此时，vector int 类型的指针就可以使用 vector 中的方法
    std::cout<<"vector mm size: "<<nn->size()<<std::endl; 

    // 
    
    return 0;    
}