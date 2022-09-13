#include <iostream>
using namespace std;

// 덧셈 뺄셈 곱셈 나눗셈에 대해서 + 100 3.14 라고 입력을 받았을 때 결과값을 출력하자

int main()
{
    char oprt;
    double num1, num2;
    double result = 0;

    cin >> oprt >> num1 >> num2;

    double large, small;
    large = (num1 > num2) ? num1 : num2;
    small = (num1 > num2) ? num2 : num1;

    // char나 int 는 switch 문을 사용할 수 있다.
    switch (oprt)
    {
    case '+':
        result = large + small;
        break;
    case '-':
        result = large - small;
        break;
    case '*':
        result = large * small;
        break;
    case '/':
        result = large / small;
        break;
    default:
        result = 0;
        break;
    }

    cout << "The answer is " << result << endl;
}
