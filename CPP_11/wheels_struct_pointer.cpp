#include <iostream>
using namespace std;

struct Wheels
{
    double x;
    double y;
    char c;
    std::string name;
    bool state;
};

int main()
{
    Wheels temp = {1.0, 2.0, 'a', "Robotics X", true};
    Wheels *wheels_t = &temp;
    std::cout << "change before: "
              << "x: " << wheels_t->x << "\t"
              << "y: " << wheels_t->y << "\t"
              << "c: " << wheels_t->c << "\t"
              << "name: " << wheels_t->name << "\t"
              << "bool state: " << wheels_t->state << std::endl;

    *wheels_t = {};
    std::cout << "change after:  "
              << "x: " << wheels_t->x << "\t"
              << "y: " << wheels_t->y << "\t"
              << "c: " << wheels_t->c << "\t"
              << "name: " << wheels_t->name << "\t"
              << "bool state: " << wheels_t->state << std::endl;

    return 0;
}