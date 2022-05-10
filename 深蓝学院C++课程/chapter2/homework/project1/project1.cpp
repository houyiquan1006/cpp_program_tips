#include<iostream>
#include<random>
#include<sys/time.h>

int main()
{
    // 运算的 两个算子
    double num1 ;
    double num2 ;

    // 真实的结果
    double real_sum;
    
    // 用户输入的结果
    double client_sum;

    // 记录 答题正确和答题错误的数目 
    int answer_right_num = 0;
    int answer_error_num = 0;
    int i = 0 ;
    
    //记录用户的输入： 本次测验一共多少道题
    int calculate_num = 0;

    // 记录用户的输入： 计算范围
    int range = 0;
    
    //记录用户的输入：是否包含乘除法
    char multi_divi_flag = '\0';

    // 根据用户输入，得到随机的计算符号
    int state_num ;

    // 定义获取系统时间所需的数据结构对象
    struct timeval tv;
    
    // 记录用户答题的时间
    double min_cost_time_ms = 100000000.0 ;    // 默认答题时间无穷大
    double average_cost_time = 0.0 ;
    double curr_cost_time_ms;
    double begin_time_ms;      // 

    // 以时间作为随机数种子，确保每次运行的伪随机数子不一样；
    std::srand( (unsigned)time( NULL ) );  
    
    //用户交互 设置计算参数,输入字符非法检测
    std::cout<<"please setting the number: (int)";
    std::cin>>calculate_num;
    if( ! std::cin.good() ){ std::cout<< "input type invaid!!! "<<std::endl; return 0; }
    
    std::cout<<"please setting the range: ";
    std::cin>>range;
    if( ! std::cin.good() ){ std::cout<< "input type invaid!!! "<<std::endl; return 0; }

    std::cout<<"please conform whether multiplication and division ard included: \nInput 'y' or 'n' :";
    std::cin>>multi_divi_flag;
    if( ! std::cin.good() ){ std::cout<< "input type invaid!!! "<<std::endl; return 0; }
   
    // 判断是否 含有乘除运算 
    if( multi_divi_flag == 'n' ) { state_num = 2 ; }
    else if( multi_divi_flag == 'y' ) { state_num = 4; }
    else{ std::cout<<"input error: "<<std::endl;  return 0; }

    std::cout<<"Ready to Starts: \n"<<std::endl;
    while( i < calculate_num ) 
    {
        // 获取两个随机数
        num1 = random() % range ;
        num2 = random() % range ;
        
        // 随机选择运算符号，并计算运算结果
        switch( ( random() % state_num ) )
        {
            case 0:
                real_sum = num1 + num2 ;
                std::cout<<i+1<<": "<<num1 <<" + "<<num2<<" = ";
                break;
            case 1:
                real_sum = num1 - num2 ;
                std::cout<<i+1<<": "<<num1 <<" - "<<num2<<" = ";
                break;
            case 2:
                real_sum = num1 * num2 ;
                std::cout<<i+1<<": "<<num1 <<" * "<<num2<<" = ";
                break;
            case 3:
                // 检测分母为 0 的非法情况
                if(num2 == 0) { continue; }
                real_sum = num1 / num2  ;
                std::cout<<i+1<<": "<<num1 <<" / "<<num2<<" = ";
                break;
            default:
                break;
        }

        // 记录 答题开始的时间
        gettimeofday(&tv,NULL);
        begin_time_ms = tv.tv_sec * 1000 + tv.tv_usec / 1000 ;  // ms
        //等待用户的输入结果：
        std::cin>>client_sum ;
        
        // 计算答题耗费时间
        gettimeofday(&tv,NULL);
        curr_cost_time_ms = ( tv.tv_sec * 1000 + tv.tv_usec / 1000 ) - begin_time_ms ;
        
        // 记录有史以来最短答题时间 ;
        if( min_cost_time_ms > curr_cost_time_ms ){ min_cost_time_ms = curr_cost_time_ms ; }
        
        // 计算累计答题时间
        average_cost_time += curr_cost_time_ms ; 

        // 记录答题正确和错误的数量
        if(client_sum == real_sum ) { answer_right_num ++ ; }
        else { answer_error_num ++ ; }

        i ++ ;
    }

    // 统计结果，向终端打印输出。
    if( i == calculate_num && i != 0)
    {
        average_cost_time /= calculate_num ; 
        std::cout<<"\n ********** the result below *************** \n"
                 <<"Total pratice num: "<<calculate_num<<"\n"
                 <<"answer_right num: "<<answer_right_num<<"\n"
                 <<"answer_error_num: "<<answer_error_num<<"\n"
                 <<"average_cost_time_ms: "<<average_cost_time<<" ms"<<"\n"
                 <<"min_cost_time_ms: "<<min_cost_time_ms<<" ms"<<"\n"
                 <<"*********************************************** "<<std::endl ;

    }        
    return 0;
}