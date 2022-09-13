#include <iostream>
using namespace std;

// 숫자 세개를 입력받아서 값 비교하기
int main()
{
    int val1, val2, val3;
    int large, middle, small;

    cout << "enter three integers: ";
    cin >> val1 >> val2 >> val3;

    if (val1 > val2 && val1 > val3)
    {
        large = val1;
        if (val2 > val3)
        {
            middle = val2;
            small = val3;
        }
        else
        {
            middle = val3;
            small = val2;
        }
    }
    else if (val2 > val1 && val2 > val3)
    {
        large = val2;
        if (val1 > val3)
        {
            middle = val1;
            small = val3;
        }
        else
        {
            middle = val3;
            small = val1;
        }
    }
    else
    {
        large = val3;
        if (val1 > val2)
        {
            middle = val1;
            small = val2;
        }
        else
        {
            middle = val2;
            small = val1;
        }
    }

    cout << small << ", " << middle << ", " << large << endl;
}