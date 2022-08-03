#include <iostream>

/**************************     嵌套名字空间与匿名名字空间   *************************
 * 1. 嵌套名字空间
 *  -名字空间可以嵌套，嵌套名字空间形成嵌套域
 *  - 注意同样的名字空间定义可以出现在程序多处，以向同一个名字空间中增加声明或定义
 *  - c++ 17 开始可以简化嵌套名字空间的定义
 * 
 * 2. 匿名名字空间
 *  - 用于构造仅翻译单元可见的对象
 *  - 可用 static 代替
 *  - 可作为嵌套名字空间 
 * 
 *********************************************************************************/ 

namespace Out   
{
    namespace IN
    {
        int x ;
        
    } // namespace IN
    
    namespace IN     // 嵌套名字空间可以在程序的多处出现，这样就可以随时新增命名空间中的元素
    {
        int y;
    } // namespace IN
    
} // namespace Out

namespace IN
{
    int z;
    
} // namespace IN

namespace Out::IN     // C++17 之后，可以这样写，节省在内部嵌套使用
{   
    int m;
    
} // namespace Out::IN

    int m;


int main()
{

    return 0;
}