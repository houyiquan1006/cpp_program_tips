#include <iostream>
using namespace std;

// class info{
//     public:
//         info():type(1),name('a'){
//             InitReset();
//             std::cout<<"construction 0"<<std::endl;
//         }
//         info(int i):type(i),name('a'){
//             InitReset();
//             std::cout<<"construction 1"<<std::endl;
//         }
//         info(char e):type(1),name(e){
//             InitReset();
//             std::cout<<"construction 2"<<std::endl;
//         }
//     private:
//         void InitReset(){}
//         int type;
//         char name;
// };


class info{
    public:
        info():type(1),name('a'){
            InitReset();
            show_value();
            std::cout<<"construction 0"<<std::endl;
            
        }
        info(int i):info(){
            type = i ;
            name = 'a';
            std::cout<<"construction 1"<<std::endl;
        }
        info(char e, double data):info(){
            name = e;
            another = data;
            std::cout<<"construction 2"<<" after another: "<<another<<std::endl;
        }

    private:
        void InitReset(){
            std::cout<<"Initial InitReset function;"<<std::endl;
        }
        void show_value(){
            std::cout<<"type: "<<type << " name: "<<name<<" another: "<<another<<std::endl;
        }
        int type;
        char name;

        double another = 0;
};

int main()
{
    char chr = 'l';
    info info0 = info(chr);

    double temp = 200.0;
    info info1 = info(chr, temp);

    return 0;
}