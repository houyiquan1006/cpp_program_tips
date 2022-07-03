#include<iostream>
#include<vector>


/**************************************************
基于范围的 for 循环语句  

break 和 continue;

***************************************************/


int main()
{
    std::vector<int> arr{1,2,3,4,5};

    for(int a : arr)
        std::cout<<a<<std::endl; 

    std::vector<std::string> str{"h","e","l"};

    for(std::string v :  str)
        std::cout<<v<<"\n";

std::cout<<"break    demo: ";
for(int j=0;j<2;j++)
{
    for(int k = 0 ;k<5;k++)     // break 只会跳出这个循环
    {
        if(k == 2 ) break;
        std::cout<<j<<k<<" ";
    }
}

std::cout<<" \ncontinue demo: ";
for(int j=0;j<2;j++)
{
    for(int k = 0 ;k<5;k++)     // break 只会跳出这个循环
    {
        if(k == 2 ) continue;
        std::cout<<j<<k<<" ";
    }
}


    return 0;
    
}