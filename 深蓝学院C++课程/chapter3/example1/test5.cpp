#include<iostream>


/********** 多维数组--  *********************
本质： 数组的数组
    - int a[3][4]

多维数组的聚合初始化： 一层大括号 V.S. 多层大括号
多维数组的索引与遍历：
    - 使用多个中括号来索引
    - 使用多重循环来遍历；

指针与多维数组
    - 多维数组可以隐式转换为指针，但只有最高维会进行转换，其他维度的信息会被保留
    - 使用类型别名来简化多维数组指针声明
    - 使用指针来遍历多维数组

***************************************************/

int main()
{
    int a[3][4]; // 缺省初始化
    int b[3][4] = {1,2,3,4,5}; // 聚合初始化,
    int b2[3][4] = {{1,2,3,4},{5,0,0,0},{0,0,0,0}}; // 聚合初始化
    //转换为指针的话，会去掉最高位的指针

    std::cout<<"b strlen: "<<std::cend(b[2]) - std::cbegin(b[0])<<std::endl; // 多维数组的首地址至少需要提供某一维度作为首地址信息
    std::cout<<"b strlen: "<<std::size(b)<<std::endl;                // 只能够求解多维数组的某一维度的长度
    std::cout<<"b strlen: "<<sizeof(b) / sizeof(int)<<std::endl;     // 通用的求解多为数组长度的做法

    auto ptr1 = std::cbegin(b[0]);
    std::cout<<*ptr1<<std::endl;   // 刚好就是该多维数组的其中0维度的第一个元素（首地址）
    while( ptr1 < std::cend(b[2]))  // 是最后一维度的最后一个元素的地址
    {
        std::cout<<*ptr1<<" ";
        ptr1++;
    }
    std::cout<<std::endl;

    auto ptr2 = std::cbegin(b[0]);
    for(int i=0;i<sizeof(b)/sizeof(int);i++)
    {
        std::cout<<*ptr1<<" ";
        ptr1++; 
    }
    std::cout<<std::endl;
    
    //多维数组轮巡
    for(auto& i:b)
    {
        for(auto& j:i)
        {
            std::cout<<j<<" ";
        }
    }
    std::cout<<std::endl;
    
    //多维数组轮巡
    for(int i = 0; i < 3; i++ )
    {
        for(int j = 0; j < 4; j++ )
        {
            std::cout<<b[i][j]<<" ";
        }
    }
    std::cout<<std::endl;

    


    return 0;    
}