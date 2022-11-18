#include <iostream>
#include <string>

using namespace std;

class Complex
{
private:
    float a;
    float b;

public:
    Complex();
    Complex(float a, float b);
    // friend ostream &operator+(ostream &os, const Complex &com);
    Complex operator+(Complex &b);
    friend ostream &operator<<(ostream &os, const Complex &com);
};
Complex::Complex()
{
    this->a = 0;
    this->b = 0;
}
Complex::Complex(float a, float b)
{
    this->a = a;
    this->b = b;
}
Complex Complex::operator+(Complex &b)
{
    Complex ans;
    ans.a = this->a + b.a;
    ans.b = this->b + b.b;

    return ans;
}
ostream &operator<<(ostream &os, const Complex &com)
{
    if (com.a != 0)
    {
        os << com.a;
    }
    if (com.b < 0)
    {
        os << " - " << -com.b << "i";
    }
    else if (com.b > 0)
    {
        os << " + " << com.b << "i";
    }
    return os;
}
int main()
{
    Complex a(2, 1);
    Complex b(3, -4);
    cout << a + b << endl;
}