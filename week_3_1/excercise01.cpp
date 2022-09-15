#include <iostream>

// 선언 + 정의
void myfunc();
void myfunc(int a);
void myfunc(double a);

int main()
{
    myfunc();
    myfunc(5);
    myfunc(5.0);
}

void myfunc()
{
    std::cout << "my" << std::endl;
}

void myfunc(int a)
{
    std::cout << "int" << a << std::endl;
}

void myfunc(double a)
{
    std::cout << a << std::endl;
}