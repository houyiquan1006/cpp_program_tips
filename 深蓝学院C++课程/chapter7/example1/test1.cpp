#include<iostream>
#include<fstream>

/****************     流的状态     **************************
 * 1. 流的状态：iostate (badbit不可恢复的状态, failbit输入输出操作失败，格式化提取作物的失败状态, eofbit关联的输入序列已经达到了文件末尾)
 * 2. 流的状态的检测：通过流的状态函数，返回该流对应的 bool 值.
 * 3. 通常来说，当流处于某种错误状态的时候，插入\提取操作就不会失效.
 * 4. 流当中提供的clear() 函数，其缺省值默认就是true,其默认会将流的状态设置为 goodbit 的正常状态 。
 * 5. 流的异常捕获：捕获和设置流的异常掩码。异常掩码确定在那些错误状态出现时抛出 failure 类型异常。（返回异常掩码、设置异常掩码为 except）
 * 
 * ******************************************************************/

int main()
{
    int x;
    std::cin>>x;

    std::cout<<std::cin.good()
                    <<std::cin.fail()
                    <<std::cin.bad()
                    <<std::cin.eof()
                    <<static_cast<bool>(std::cin) << std::endl;


    int ivalue;
    try{
        std::ifstream in("in.txt");
        in.exceptions(std::ifstream::failbit);
        in >> ivalue;
    }
    catch(std::ios_base::failure & fail)
    {
        // 处理异常的程序
        std::cout<<"cin exception. "<<std::endl;
    }

    return 0;
}