#include <iostream>
#include <initializer_list>
/***************************************************************************************************************
 * 1. 函数中，形参的拷贝初始化顺序是不确定的，跟函数形参中的前后位置并没有关系，是是随机的,和编译器版本有关系，C++17 会强制省略复制对象。
 * 2. C++ 标准库中的 初始化列表，可以用于在 函数形参列表中，一次性初始化很多同类型的参数,而且不同位置调用的时候，形参列表的长度是可以变化的。
 * 3. 在定义函数的时候，当初始化列表类型（initializer_list）作为返回值时，会出现警告，不宜使用。
 * 4. 函数返回值和结构体相绑定，可以返回多个值。
 * 5. c++17 新增[nodiscard] 属性，强制规定在只用该函数时，必须用一个变量或者对象来存储函数的返回值。
 * 
 * *************************************************************************************************************/

struct Str
{
    Str() = default;
    Str(const Str&)
    {
        std::cout << "Copy constructor is called. " << std::endl;
    }
};

struct Str_2{
    int x;
    int y;
};

void fun(int x, int y)
{
    std::cout << "function x: " << x << " y: " << y << std::endl;
}

void fun2(Str s)
{

}

void int_lists(std::initializer_list<int> par)
{
    std::cout<<"initializer_lists"<<std::endl;
}


// initializer_list 包含的是两个指针，分别指向列表的起始和结束位置，但是因为函数在执行完毕之后会被销毁，
// 所以返回值列表所在的内存空间同样也会被销毁，故是不明确的指针应用。
std::initializer_list<int> fun3()
{
    std::cout<<"return as initializer_list."<<std::endl;
    return{1,2,3,4,5,6};
}


Str_2& fun4()
{
    static Str_2 str;
    str.x = 1 ;
    str.y = 1;
    return str;
}

Str_2 fun5()
{
    Str_2 str;
    str.x = 1 ;
    str.y = 1;
    return str;
}

[[nodiscard]] int fun6()
{
    int a = 3 ;
    return a;
}

int main()
{
    int a = 0;
    // 未定义 的函数操作，因为形参的初始化顺序不定，每次编译的结果都可能不一样。
    fun(a++, a++);
    std::cout << "after a: " << a << std::endl;

    int b = 0;
    fun(++b, ++b);
    std::cout << "after b: " << b << std::endl;

    Str var;
    fun2(var);      // 展示的是函数调用的过程中，会有形参的拷贝初始化的过程。

    // 使用初始化列表的方式初始化函数参数
    int_lists({1,2,3,4,5,6,7,8,9,0});
    int_lists({1});

    auto x = fun3();

    auto str = fun5();    // 可以同时返回两个参数，因为函数返回类型号是 str 结构体类型.
    std::cout<<"str.x: "<<str.x<<" "<<" str.y: "<<str.y<<std::endl;

    auto& [v1,v2] = fun4();   // c++17 支持的新的语法规则。
    std::cout<<"str.x: "<<v1<<" "<<" str.y: "<<v2<<std::endl;

    fun6();   // 直接这样使用，会产生警告。必须用变量来接收该函数的返回值

    int f6 = fun6();

    return 0;
}