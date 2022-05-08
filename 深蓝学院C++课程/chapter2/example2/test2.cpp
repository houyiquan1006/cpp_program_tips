#include<iostream>

/***************   复合类型：从指针到引用  **********************
 * 指针的定义：
 *  int *p = &val ； //通过一个变量来定义
 *  int *p = nullptr ; // 通过c++11 中的方法进行初始化。 
 * 
 * 关于 nullptr :
 *  一个特殊的对象（类型为 nullptr_t ）,表示空指针；
 *  类似于 C 中的 NULL ;
 *
 * 指针与布尔之间的隐式转换：非空指针可以转换为 true ;空指针可以转换为false; 
 * 
 * 指针的主要操作：解引用、增加、减少、判断、
 * 
 * void* 指针：  ********  
 *  没有记录对象的尺寸信息，可以保存任意地址。
 *  支持判等操作
 *  因此，void* 指针可以转换为任何的指针，也接收任意的指针。
 *  所以，其字长不确定就不可以对 void* 类型进行 偏移操作，因为其不知道应该移动多少个字节。
 * 
 * 
 * *******************************************************/

void fun(void *param)
{
    std::cout<< "params address: " << param <<std::endl;
}


int main()
{
    int* p = nullptr ;
    if(p) // 此时，其地址指向为 0 （nullptr）；
    {
        std::cout<<" pointer p not empty;"<<std::endl;
    }
    else
    {
        std::cout<<" pointer p is empty;"<<std::endl;
    }

    int a = 30 ;
    p = &a;
    
    if(p)  // 此时，其地址指向不为 0 （nullptr）；
    {
        std::cout<<" pointer p not empty;"<<std::endl;
    }
    else
    {
        std::cout<<" pointer p is empty;"<<std::endl;
    }

    int b = 20 ;
  
    int *q ; // 
    q = &b ;

    std::cout<<*q<<" "<<*(q+1)<<std::endl;

    int str[5]={0,1,2,3,4};
    q = str;       // 数组的名字代表的就是数组的首地址。

    std::cout<<*q<<" "<<*(q+1)<<std::endl;
    q = q+1 ;       // 指针的偏移，偏移的步长就等于该类型所占据的字节大小，但是需要注意 “ 不要超出范围，否则会访问到别的空间，造成不安全的访问 ”
    std::cout<<*q<<" "<<*(q+1)<<std::endl;

    fun(q);   // q 是一个 int 类型的指针，但是 可以传递给 void* 类型,但是 void* 类型不能用于增删改查;

    return 0;
}