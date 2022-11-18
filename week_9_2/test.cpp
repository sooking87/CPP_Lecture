#include <iostream>

using namespace std;

class Sample
{
    int n;

public:
    Sample();
    Sample(int x);
    Sample(Sample &a);
    ~Sample();
    void setN(int x);
    int getN();
};
Sample::Sample()
{
    n = 0;
    cout << "Sample() is Called" << endl;
}
Sample::Sample(int n)
{
    this->n = n;
    cout << "Sample() is Called" << endl;
}
// copy constructor
Sample::Sample(Sample &a)
{
    n = a.n + 1000;
}
void Sample::setN(int x)
{
    n = x;
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
    Sample z;
    Sample copy(z);
    cout << "z.n: " << z.getN() << endl;
    cout << "copy.n: " << copy.getN() << endl;
}
