#include <iostream>

/***************************** 嵌套类和局部类  *******************************************************
 * 1. 嵌套类：在类中定义的类
 *  -   嵌套类具有自己的域，与外围类的域形成嵌套关系
 *      - 嵌套类中的名称查找失败时会在其外围类中继续查找
 *  - 嵌套类与外围类单独拥有各自的成员
 * 
 * 2. 局部类：可以在函数内部定义的类
 *  - 可以访问外围函数中定义的类型声明、静态对象与枚举
 *  - 局部类可以定义成员函数，但成员函数的定义必须位于类内部
 *  - 局部类不能定义静态数据成员
 ********************************************************************************************************/

class Out
{
public:
    int val = 1;    // 外层定义的 val
    int outval = 2;   // 只有外层定义了
    class In{
        public:
            int val = 0;    // 内层定义的 val
    };
};

int main()
{
    Out::In obj;     
    std::cout<< obj.val <<std::endl;       // 此时会优先查找内层的 val ，只有当内层的 val 没有查找到的时候，才会退而求其次查找外层的 val
    Out obj2;
    std::cout<< obj2.outval <<std::endl;    // 嵌套类与外围类各自拥有各自的成员

    return 0 ;
}