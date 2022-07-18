#include <iostream>
#include <memory> // 智能指针的头文件
#include <vector>
#include <stdio.h>
#include <stdlib.h>

/***********************************    动态内存的相关问题    **********************************************
 * 1. sizeof 不会返回动态分配类型的大小；
 * 2. 使用分配器（ allocator ）来分配内存；
 * 3. 使用malloc / free 来管理内存； c语言中的内存分配和释放,malloc 接收的是字节数。
 * 4. 使用aligned_alloc 来分配对其内存；
 * 5. 动态内存与异常安全；
 * 6. C++ 对于垃圾回收的支持；
 ********************************************************************************************************/


int main()
{
    int* ptr = new int(3);
    std::cout<<"new ptr:  "<<sizeof(ptr)<<std::endl;       // 无论分配多少内存，其指针的大小就是一致的。

    std::vector<int> x;
    std::cout<<"vector x: " <<sizeof(x)<<std::endl;     // 该 x 中包含一个指针，指向 vector  的内存首地址，除此之外，还会有其他的一些相关信息，这些加起来一共是 24 字节。

    /* 
    int *y = malloc(sizeof(int));    // 参数传递的是所需要的字节数量。
    free(y);
    */  

    return 0;
}