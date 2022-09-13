#include <iostream>
#include <string>
using namespace std;

// 짝수 홀수 판단
// 출력 형식 : The value 4 is an even number

int main()
{
    int num;
    string cat;
    cin >> num;

    if (num % 2 == 0)
    {
        cat = "even";
    }
    else
    {
        cat = "odd";
    }

    cout << "The value " << num << " is an " << cat << " number." << endl;

    return 0;
}