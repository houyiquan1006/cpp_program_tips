
/**    1、获得 linux 下系统时间 && 使用 ofstream  输出数据到 文件中  ***********************

例子：
void open ( const char * filename,  
            ios_base::openmode mode = ios_base::in | ios_base::out );  
  
void open(const wchar_t *_Filename,  
        ios_base::openmode mode= ios_base::in | ios_base::out,  
        int prot = ios_base::_Openprot)；

filename    操作文件名
mode        打开文件的方式
prot          打开文件的属性   //基本很少用到，在查看资料时，发现有两种方式

ios::in 	为输入(读)而打开文件
ios::out 	为输出(写)而打开文件
ios::ate 	初始位置：文件尾
ios::app 	所有输出附加在文件末尾
ios::trunc 	如果文件已存在则先删除该文件
ios::binary 	二进制方式
 
-------------------------------------------------------------------------------------------------------------------------/

struct timeval tv;
gettimeofday(&tv,NULL);

获取时间：
    s 秒： tv.tv_sec ;
    ms 毫秒: tv.tv_sec * 1000 + tv.tv_usec / 1000 ;
    us 微秒: tv.tv_sec*1000000 + tv.tv_usec; 
***********************************************************************/

#include<sys/time.h>    
#include <fstream>
#include<iostream>
using namespace std;

ofstream outFile0("imu_acc_z_data0.txt");

struct timeval tv;
gettimeofday(&tv, NULL) ;
outFile0.open("imu_acc_z_data0.txt", ios::out | ios::app );   // 时间单位 ms
outFile0<<( (tv.tv_sec*1000 + tv.tv_usec / 1000)  - begin_time) << "\t"
                <<save_p0 << "\t" << save_p1 << "\t" <<save_p2 << "\t" << save_p3   << "\t"
                <<Rpy_0     << "\t" <<Rpy_1     << "\t" <<Rpy_2     << "\t" 
                <<acc_0      << "\t" <<acc_1      << "\t" <<acc_2      << "\t" 
                <<vel_0      << "\t" <<vel_1       << "\t" <<vel_2       << "\t" 
                <<Z_left_h  << "\t" <<Z_right_h << "\n" ;
outFile0.close();

// -------------------------------------         end          ---------------------------------------------------------------------


