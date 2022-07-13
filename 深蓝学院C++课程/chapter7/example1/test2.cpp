#include<iostream>
#include<sstream>
#include<string>

/************      流的定位      *******************************************************************************************
 * 1. tellg() \ tellp() 获取输入输出流的位置，若失败则会返回 -1 ；
 * 2. 设置流的位置：seekg() / seekp() 用于设置输入\输出流的位置；该函数有两个重载版本，分别是 设置绝对\相对位置。
 *      绝对位置：传入 pos_type 进行设置
 *      相对位置： 通过偏移量（字符个数 ios_base::beg） + 流位置符号的方式设置，ios_base::cur \ ios_base::end
 * 
 **********************************************************************************************************************/ 


int main()
{
    std::ostringstream s;
    std::cout<<s.tellp()<<"\n";
    s<<'s';
    std::cout<<s.tellp()<<"\n";
    s<<"ello, world ";
    std::cout<<s.tellp()<<"\n";

    s<<3.14<<"\n";
    std::cout<<s.tellp()<<"\n"<<s.str();
    

    std::string str = "Hello, world";
    std::istringstream in(str);
    std::string word;
    in >> word ;
    std::cout<< "After reading the word \""<<word
                    << "\"tellg() returns " <<in.tellg()<<"\n";


    std::string str2 = "Hello, world";
    std::istringstream in2(str2);
    std::string word1,word2;

    in2 >> word1 ;      // 检测到中间的空格，格式化输入流则会结束。
    in2.seekg(0);        // 回溯 位置到流的第0位。
    in2 >> word2 ;

    std::cout<<"word1 = "<<word1<<"\n"
                    <<"word2 = " <<word2 <<"\n";


    std::ostringstream os("hello, world");
    os.seekp(7);
    os<<'W';
    os.seekp(0,std::ios_base::end);    // 设置输出流的位置在文件末尾。
    os<<"!";
    os.seekp(0);
    os<<'H';

    std::cout<<os.str()<<"\n";


    return 0;
}