#include <iostream>

using namespace std;

class Sample
{
private:
    int n;

public:
    Sample();
    ~Sample();
    Sample(int x);
    void setN(int n);
    int getN();
};

Sample::Sample()
{
    this->n = 0;
}
Sample::Sample(int x)
{
    this->n = x;
}
void Sample::setN(int n)
{
    this->n = n;
}
int Sample::getN()
{
    return n;
}
Sample::~Sample()
{
    cout << n << " ~Sample() is Called" << endl;
}
int main()
{
    Sample x, y;
    Sample z(10);
    Sample *w;
    w = new Sample(1000);
    {
        delete w;
    }
    x.setN(1);
    y.setN(2);
    cout << "x.n: " << x.getN() << endl;
    cout << "y.n: " << y.getN() << endl;
    cout << "z.n: " << z.getN() << endl;
}