#include <iostream>

/***************************** 面向对象编程 -- 访问限定符号与友员  *******************************************************
 * 1.使用 public / private /protected 限定类成员的访问权限
 *      - 访问权限的引入使得可以对抽象数据类型进行封装
 *      - 类与结构体缺省访问权限的区别
 * 
 * 2. 使用友元打破访问权限限制 —— 关键字 friend 
 *      - 声明某个类或某个函数是当前类的友元 —— 慎用
 *      - 在类内首次声明友元类或友元函数
 *          - 注意使用限定名称引入友元并非友元类（友元函数）的声明
 *      - 友元函数的类内定义
 *      - 隐藏友元（hidden friend ）：常规名称查找无法找到
 *          - 好处：减轻编译器负担，防止误用
 *          - 改变隐藏友元的缺省行为：在类外声明或定义函数
 *********************************************************************************************************/

struct Str{
    int get_x()
    {
        return x;
    }
    int get_y()
    {
        return y ;
    }
    private: 
        int x = 0;

    public:
        int y = 1;
};

class OBJ_2;
int main();

class OBJ{
    
        friend OBJ_2;    // 告诉编译器 ，OBJ_2 是 OBJ 的一个友元，友元是可以访问该类别的所有成员，无论是 public / private 
        inline static int x;  // 并且对外成为 友元的 成员，必须使用 inline static 的方式 进行

        void fun()
        {
            std::cout << x <<std::endl;
        }
        friend void fun(const OBJ& val)
        {
            std::cout<< val.x <<std::endl;
        }
};

class OBJ_2{

public:
    void Get_OBJ_X()       // 因为已经在 OBJ 中使用 friend 声明过了 OBJ_2 是 OBJ 的友元，因此 OBJ_2 可以访问 OBJ 中所有的函数成员
    {
        std::cout << OBJ::x <<std::endl;
    }
};

int main()
{
    Str str;
    std::cout<< str.get_x() << std::endl;
    std::cout<< str.get_y() << std::endl;
    // std::cout<< str.x << std::endl;      // 因为 x 是私有成员，因此不能直接访问，需要通过该类的成员函数类访问，但可以通过友元来打破这个权限
    std::cout<< str.y << std::endl;

    OBJ_2 obj_2;
    obj_2.Get_OBJ_X();


    // 隐藏友元查找的调用方式，如果不使用该传值的方式，那么编译的时候是无法找到该函数的 fun() （即使已经 在 OBJ  中使用 friend 声明了该函数全局有效）
    OBJ obj_3;
    fun(obj_3);

    return 0 ;
}