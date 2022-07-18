#include <iostream>

/******************** delete 删除对象********************************
 * 1. 销毁单一对象 \ 对象数组；
 * 2. 销毁 placement delete ，使用结构体的析构函数释放对象的堆内存。
 * 3. 使用 new 和  delete 分配和构造对象的注意事项：
 *          根据分配的单一对象或者数组的new 方式，选择对应的 delete 销毁堆内存的方式；
 *          不能 delete 一个非 new 返回的内存，但是可以 delete 一个指向为（nullptr ）的空指针；
 *          同一块内存不能 delete 多次；
 * 4. 调整系统自身的 new / delete 行为
 *          ---- 不要轻易使用；
 ***********************************************************/ 

struct Str{
    ~Str()
    {
        std::cout<<"str is called."<<std::endl;
    }
};

int main()
{
    int *x = new int;     // int * x是定义的一个指针，该指针指向的是一个有new 创建并且分配的堆内存。
    x = nullptr;
    delete x;     // delete 消除的是该指针所指向的内存，并没有消除 int* x 自己，其指向并没有变，但是指向的内存没了。

    int *y = new int(4);
    delete []y;

    // placement new 的方式在堆上分配内存，placement 的意思就是: 分配内存和在所分配的内存上构造对象是分步进行的。
    char ch[sizeof(int)];     // 分配内存
    int *ptr = new(ch) int(100);   // 在所分配的内存上构造对象。
    
    Str *str2 = new(ch) Str;
    str2->~Str();     // 使用结构体的析构函数，主动释放结构体类型的堆内存。



    return 0 ;
}