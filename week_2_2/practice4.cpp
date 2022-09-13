#include <iostream>
#include <string>
using namespace std;

// 5개의 숫자를 문자로 타이핑 -> 결과에 대해서 실제 숫자를 찍어줘라

int main()
{
    string strNum;
    int ans = -1;
    cin >> strNum;

    // 입력받은 문자를 소문자로 만들기
    for (int i = 0; i < strNum.size(); i++)
    {
        strNum[i] = tolower(strNum[i]);
    }

    // 문자열 비교
    // 다형성 사용됨 == 를 하면 value가 같은지를 비교를 하겠지 그래서 c++에서는 operator overloading에 의해서 값이 같은지를 비교를 해준다.
    if (strNum == "zero")
    {
        ans = 0;
    }
    else if (strNum == "one")
    {
        ans = 1;
    }
    else if (strNum == "two")
    {
        ans = 2;
    }
    else if (strNum == "three")
    {
        ans = 3;
    }
    else if (strNum == "four")
    {
        ans = 4;
    }
    else
    {
        ans = -1;
    }

    // 출력값
    if (ans == -1)
    {
        cout << "Not a valueI know." << endl;
    }
    else
    {
        cout << ans << endl;
    }

    // switch문은 안될까? => 에러가 뜸 : switch 문은 원시형만 가능, int, char 만 가능 그렇기 때문에 user defined에 해당되는 string은 switch에 파라미터로 해당할 수 없다.
    // 아! switch에는 string을 파라미터로 넣을 수가 없구나
    return 0;
}