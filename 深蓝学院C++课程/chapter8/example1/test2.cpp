#include <iostream>
#include <new>


/*****************************     new 的常见使用方式     *******************************************************
 * 1. 构造单一对象 / 对象数组
 * 2. nothrow new ,添加该关键字之后，系统就不会抛出异常了，即使分配内存失败。因此需要额外加一个判断内存是否分配成功。
 * 3. placement new
 * 4. new auto  
 * 5. new 与对象对齐 alignas
 *********************************************************************************************************/

struct alignas(256) Str{};   // 按照256 的地址方式对其，即地址可以被 256 整除，一般用于极致优化内存时使用。

int main()
{ 
    int* y = new int(4);   // 需要手动销毁，有可能分配不成功，抛出异常，程序停止。
    int *z = new int[5]{5,6,7,8,9};   // 需要手动销毁

    int *x = new (std::nothrow) int(2);   // 
    if( x == nullptr )
    {
        std::cout<<" heap is not available!  "<<std::endl;
    }
    else
    {
        std::cout<<" heap is availablle! "<<std::endl;
    }


    Str *s = new Str;
    std::cout<<s<<std::endl;

    return 0 ;
}