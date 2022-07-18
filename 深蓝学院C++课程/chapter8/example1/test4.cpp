#include <iostream>
#include <memory> // 智能指针的头文件

/***********************************    3种智能指针    ************************************************************
 * 1. 使用 new 和 delete 创建和销毁内存的时候，其所有权是不清晰的，容易产生不销毁或者多次销毁的问题；
 * 2. shared_ptr :  基于引用计数的共享内存解决方案，程序执行完毕后自动清除内存，并且不会被销毁多次，shared_ptr 的指针不要使用 delete 去显示的销毁；
 * 3. unique_ptr : 独占指针资源，不可进行指针复制行为，但是可以通过std::move() 或者 函数返回值的方式进行资源共享，unique_ptr 的指针需要规定销毁机制；
 * 4. weak_ptr : 防止循环引用而引入的智能指针，是基于 shared_ptr 构造的。weak_ptr 可以和shared_ptr 共享一段内存，但是并不会增加该段内存的引用计数。
 *          所以，为了使用引用计数这个好的功能，通常情况下，需要通过weak_ptr 类中的 lock() 方法获取该指针所指向的内存是否可用。
 *          若可用，则将利用 lock函数将其转换成 shared_ptr 类型的指针，以利用引用计数这个智能的机制。
 ********************************************************************************************************/


struct Str{

    std::weak_ptr<Str> m_nei;      // 改为 std::weak_ptr 即可
    ~Str(){
        std::cout<<"~ Str() is called\n";
    }
    
};

int main()
{
    // 智能指针对象是一个类的对象，因为其有析构函数，所以程序执行完毕之后会自动清除内存，而且不会被销毁多次，不会造成内存泄漏，故很“智能”。
    std::shared_ptr<int> x(new int(3)); // 等效于 int* x(new int(3)); 引用计数为 1
    std::cout << "x use count: " << x.use_count() << std::endl;
    {
        std::shared_ptr<int> y = x; // 引用计数为 2
        std::cout << "x use count: " << x.use_count() << " y use count: " << y.use_count() << std::endl;
    }   // 该域执行完毕之后，其中的内容会被删除，指针的指向会被释放一次，所以该智能指针的引用计数值会减少。

    std::cout<<"x use count: "<<x.use_count()<<std::endl;

    std::unique_ptr<int> m(new int(3));
    std::cout<<"m point address is: "<<m.get()<<std::endl;
    std::unique_ptr<int> n = std::move( m );    // 不能够使用该种方式进行复制，但是可以通过移动的方式进行资源共享，也可以使用函数返回值的方式，共享unique_ptr 的资源。


    // shared_ptr 造成循环引用 
    std::shared_ptr<Str> p(new Str{});      // p 引用计数为 1
    std::shared_ptr<Str> q(new Str{});      // q 引用计数为 1

    // 如果结构体内存成员使用了 shared_ptr 的话，造成了循环的引用，此时是不能正常地自动实现 销毁的，此时可以使用 weak_ptr 解决循环引用。
    p->m_nei = q;           // q 的引用计数为 1，因为 weak_ptr 不会在引用的时候对计数值加一。
    q->m_nei = p;           // q 的引用计数为 1，因为 weak_ptr 不会在引用的时候对计数值加一。

    std::cout<<"q use count: "<<q.use_count()<<std::endl;
    std::cout<<" p use count: "<<q.use_count()<<std::endl;

    if( auto ptr = p->m_nei.lock() ; ptr )
    {
        std::cout<<" Can access pointer.  "<< std::endl;
    }
    else
    {
        std::cout<<"can not access pointer."<<std::endl;
    }
    return 0;
}