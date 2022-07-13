#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

/***********************************   流的同步  *************************************************
 * 1. flush() 用于输出流同步，主动刷新缓冲区，及时缓冲区还没满足向窗口或者文件输出的条件；
 * 2. sync() 用于输入流同步，其实现逻辑是编译器所定义的。将输入缓冲区与关联数据源进行同步 sync() 可以清空缓冲区，或重填充它，或不做任何事。
 * 3. 输出流可以通过设置unitbuf 来保证每次输出后自动同步，只要有一个字节进入输出缓冲区，那么就会自动刷新缓冲区输出。
 * 4. 基于绑定tie的同步，流可以绑定到一个输出流上，这样每次在输入输出前可以刷新输出流的缓冲区；比如 cin 绑定到 cout 上。
 * 5. 缺省情况下，c++的输入输出操作会与C的输入输出函数同步。
 * 6. 可以通过sync_with_stdio 关闭该同步。
 ***********************************************************************************************/ 


int main()
{
    std::cout<<"What's your name\n"<<std::flush;     // 同等于
    std::cout<<"What's your name"<<std::endl;     // 同等于回车+换行符

    // std::string name ;
    // std::cin>>name;

    std::cout<<std::unitbuf;
    for(int i=0;i<100000;i++)
    {
        std::cout<<"log count."<<std::endl;
    }

    // 能够快速的输出到缓冲区，更快得看到输出流信息。
    std::cerr<<"finished function."<<std::endl;  


    // 解除默认情况下的 c 语言与 C++ 语言的同步
    std::ios::sync_with_stdio(false);   // 接触默认c/c++输入输出函数的同步之后，顺序就不一定是 a b c 了,有可能是 b a c
    std::cout<<"a\n";
    std::printf("b\n");
    std::cout<<"c\n";     // 此处不能使用 std::endl; 换行的目的是因为 其会强制刷新缓冲区。


    return 0 ;
}