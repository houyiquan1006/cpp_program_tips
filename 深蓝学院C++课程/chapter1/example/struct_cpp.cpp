#include <iostream>


// 结构体通常使用  .  操作符号来访问该元素 。 
// c++ 之中，结构体也是可以引入 函数的，如下所示：
struct Point{
    int x;
    int y;
    void change_x()
    {
        x = x + 1 ;
        y = y + 1 ;
    }
};

int main()
{
    Point P;
    P.x = 4 ;
    P.y = 5 ;
    std::cout<< "origin X: "<<P.x << " origin y: "<<P.y << std::endl;
    P.change_x();

    std::cout<<"change X: "<<P.x<< " change y: "<<P.y<<std::endl;
    std::cout<<"exit main function. "<<std::endl;
    return 0;
}