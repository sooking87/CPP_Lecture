#include <iostream>

using namespace std;

class Negative
{
};
class Sample
{
private:
    int n;
    int m;

public:
    Sample();
    Sample(int n, int m);
    Sample(Sample &a);
    ~Sample();
    void setN(int n);
    int getN();
    void setM(int m);
    int getM();
    // 연산자 오버로딩
    Sample operator+(Sample &a);
    friend Sample operator-(Sample &a, Sample &b);
    friend ostream &operator<<(ostream &os, Sample x);
};

Sample::Sample()
{
    this->n = 0;
    this->m = 0;
    cout << "Sample() is Called" << endl;
}
Sample::Sample(int n, int m)
{
    this->n = n;
    this->m = m;
    cout << "Sample(int n, int m) is Called" << endl;
}
Sample::Sample(Sample &a)
{
    this->n = a.n + 1000;
    this->m = a.m + 1000;
    cout << "Copy Sample is Called" << endl;
}
Sample::~Sample()
{
    cout << "[" << n << ", " << m << "] ~Sample() is Called" << endl;
}

void Sample::setN(int n)
{
    this->n = n;
}
int Sample::getN()
{
    return n;
}
void Sample::setM(int m)
{
    this->m = m;
}
int Sample::getM()
{
    return m;
}
// 연산자 오버로딩
Sample Sample::operator+(Sample &a)
{
    Sample x;
    x.n = this->n + a.n;
    x.m = this->m + a.m;

    return x;
}
Sample operator-(Sample &a, Sample &b)
{
    Sample x;
    x.n = a.n - b.n;
    x.m = a.m - b.m;

    return x;
}
ostream &operator<<(ostream &os, Sample x)
{
    os << x.n << ", " << x.m << endl;
    return os;
}
int main()
{
    Sample x;
    x.setN(5);
    x.setM(2);
    Sample y(10, 20);
    // cout << "y.getM(): " << y.getM() << endl;
    Sample y2(y);
    cout << "y2.getM(): " << y2.getM() << endl;
    Sample y3;
    y3 = y2 + y;

    // cout << "x.getM(): " << x.getM() << endl;
    // cout << "y3.getM(): " << y3.getM() << endl;
    cout << x << endl;
    cout << y << endl;
    cout << y2 << endl;
}
// 결과가 왜 이렇게 나오는지?