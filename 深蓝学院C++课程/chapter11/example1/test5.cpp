#include <iostream>
#include <string>

/***************************** 面向对象编程 -- 构造、析构、复制成员函数  *******************************************************
 * 1. 构造函数：构造对象时调用的函数
 *      - 名称与类名字相同，无返回值，可以包含多个版本（重载）
 *      - （c++  ）代理构造函数
 * 
 * 2. 初始化列表：区分数据成员的初始化与赋值
 *      - 通常情况下可以提升系统性能
 *      - 一些情况下必须使用初始化列表（如类中包含引用成员）
 *      - 注意元素的初始化顺序与其声明顺序相关，与初始化列表中的顺序无关；
 *      - 使用初始化列表覆盖类内成员初始化的行为,即用 后定义的成员初始化先定义的成员，此时就会造成未定义的问题。
 * 
 * 3. 缺省构造函数：不需要提供实际参数就可以调用的构造函数
 *  - 如果类中没有提供任何构造函数，那么在条件允许的情况下，编译器会合成一个缺省构造参数
 *  - 合成的缺省构造参数会使用缺省初始化其数据成员；
 *  - 调用缺省构造函数时避免 most vexing parse；
 *  - 使用 default 关键字定义缺省构造函数；
 * 
 * 4. 单一参数构造函数
 *  - 可视化为一种类型转换函数
 *  - 可以使用 explict 关键字避免求值过程中的隐式转换
 * 
 * 5. 拷贝构造函数：接收一个当前类右值引用对象的构造函数
 *  - 可以从输入对象中“窃取”资源，只要确保传入对象处于合法状态即可；
 *  - 当某些特殊成员函数（如拷贝构造函数）未定义时，编译器可以合成一个；
 *  - 通常声明为不可抛出异常的函数
 *  - 注意右值引用对象用作表达式时的左值

 *********************************************************************************************************/

class Str{
    public: 
        // Str(int input)    // 构造函数的重载
        // {   
        //     std::cout<< input <<std::endl;
        //     std::cout<<" here 2 "<<std::endl;
        // }

        // Str()
        // {
        //     std::cout<<"Str constructioner is called "<<std::endl;
        // }

        // Str(int input = 3 )   // 缺省构造函数是缺省参数
        // {
        //     std::cout<< input <<std::endl;   
        // }

        // Str(const std::string& val)    // 缺省构造函数的方式构造 x ，但是效率比较低
        // {
        //     std::cout<< str <<std::endl;      // 此时，由于还没有传递该成员函数，因此，打印的值不对。
        //     str = val;
        // } 

        Str(const std::string& val, int init_x , int &p_i):str(val) ,x(init_x),ref(p_i)     // 使用初始化列表的方式构造类的成员函数，效率很高
        {
            std::cout<< str <<std::endl;
        }

        // Str() : Str(3)      // 代理构造函数,当初始化类的对象的时候，若没有参数传递进来，那么将默认调用另外一个构造函数  Str(3) 并且会被先执行，然后在是执行原本的构造函数，因此称为代理。
        // {
        //     std::cout<<" here 1 "<<std::endl;
        // }
        void print()
        {
            std::cout<< str <<std::endl;
        }

        private:
            int x;
            int& ref;      // 引用成员变量的初始化
            std::string str;
};

class test
{
    explict test(int value):x(value)
    {

    }
    private:
        int x;
};

int main()
{
    // Str str(2);
    // Str str2;
    
    int x = 3;
    int& ref = x;
    Str str2("Tencent Robotics X", 1 , ref);

    return 0 ;
}