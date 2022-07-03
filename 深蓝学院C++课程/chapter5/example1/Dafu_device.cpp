#include <iostream>
#include <vector>

/**************************************************************************************************************

    在编程时，循环展开注重于利用批量处理，减少总处理分支数。而在串行复制数据时，当总循环次数无法被展开后循环的增量整除时，
一般就用直接跳转到展开后循环体中部的方式，完成剩余数据的复制流程。因此，根据循环展开的思想，针对串行复制数据的需要，
汤姆·达夫以每次迭代时赋最多8个值的方式，用C语言写出了一个优化实现，成功优化了串行复制的效率。

在计算机科学领域，达夫设备（英文：Duff's device）是串行复制的一种优化实现，通过汇编语言
编程时一常用方法，实现展开循环，进而提高执行效率。这一方法据信为当时供职于卢卡斯影业的
汤姆·达夫于1983年11月发明，并可能是迄今为止利用C语言switch语句特性所作的最巧妙的实现。

***************************************************************************************************************/

int main()
{

    constexpr size_t count_buffer = 20000;
    std::vector<size_t> buffer(count_buffer);

    for (size_t i = 0; i < count_buffer; ++i)
    {
        buffer[i] = i;
    }
    std::cout<<"start value is: "<<buffer[0]                           <<std::endl;
    std::cout<<"last  value is: "<<buffer[count_buffer-1]<<std::endl;

    size_t max_velue = buffer[0];

    auto ptr = buffer.begin();
    size_t i = 0;
    switch (count_buffer % 8)
        for (; i < (count_buffer + 7) / 8; i++)
        {
            case 0: max_velue = (max_velue > *ptr) ? max_velue : *ptr;   ++ptr;
            case 7: max_velue = (max_velue > *ptr) ? max_velue : *ptr;   ++ptr;
            case 6: max_velue = (max_velue > *ptr) ? max_velue : *ptr;   ++ptr;
            case 5: max_velue = (max_velue > *ptr) ? max_velue : *ptr;   ++ptr;
            case 4: max_velue = (max_velue > *ptr) ? max_velue : *ptr;   ++ptr;
            case 3: max_velue = (max_velue > *ptr) ? max_velue : *ptr;   ++ptr;
            case 2: max_velue = (max_velue > *ptr) ? max_velue : *ptr;   ++ptr;
            case 1: max_velue = (max_velue > *ptr) ? max_velue : *ptr;   ++ptr;
        }

    std::cout << "result max_velue is : " << max_velue << std::endl;

    return 0;
}