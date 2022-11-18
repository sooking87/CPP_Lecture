#include "test.h"
#include <iostream>

using namespace std;

int main()
{
    Sample x, y;
    Sample z(10);
    x.setN(1);
    y.setN(2);
    cout << "x.n: " << x.setN() << endl;
    cout << "y.n: " << y.setN() << endl;
}