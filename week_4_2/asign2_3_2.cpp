#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

long long tenConvertTwo(int num)
{
    long long result = 0;
    for (long long i = 1; num > 0; i *= 10)
    {
        int binary = num % 2;
        cout << "binary: " << binary << ", i: " << i << endl;
        result += binary * i;
        cout << "result: " << result << endl;
        num /= 2;
    }
    return result;
}

int main()
{
    long long result = tenConvertTwo(1538);
    cout << result << endl;
}