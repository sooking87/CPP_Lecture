#include <iostream>
#include "test.h"

using namespace std;

Sample::Sample()
{
    n = 0;
    cout << "Sample() is Called" << endl;
}
Sample::Sample(int x)
{
    n = x;
    cout << "Sample() is Called" << endl;
}
void Sample::setN(int x)
{
    n = x;
}
int Sample::setN()
{
    return n;
}
