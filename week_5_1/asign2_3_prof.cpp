#include <iostream>
#include <string>
using namespace std;

int getDigit(string bin, int i)
{
    // i번째란 뒤에서부터 i 번째라는 의미
    // ?? 근데 만약에 bin1이랑 bin2길이가 다르면 없는 인덱스도 있을 텐데 그거에 대한 i는 어떻게 뽑는다는 거지? 짧은 거를 기준으로 len을 잡고 그외의 나머지는 makeAnswer를 통해서 그냥 붙혀나갸야되는거 아닌가?
    // 해결책 : if 문
    if (bin.length() > i)
    {
        return bin[bin.length() - i - 1] - '0';
        // '0'을 빼야 진짜로 integer 가 리턴된다. 그렇지 아니면 0또는 1의 문자의 아스키코드가 리턴된다.
    }
    else
    {
        return 0;
    }
}
string makeAnswer(string ans, int i)
{
    if (i == 1)
    {
        return "1" + ans;
    }
    else
    {
        return "0" + ans;
    }
}
string solution(string bin1, string bin2)
{
    string answer = "";
    int a, b, c, s; // a = getDigit(bin1, i);, b = getDigit(bin2, i);
    // i번째 값을 리턴해주는 디짓
    // c는 자리올림
    c = 0;
    int len = bin1.length();
    if (len < bin2.length())
    {
        len = bin2.length();
    }

    for (int i = 0; i < len; i++)
    {

        a = getDigit(bin1, i);
        b = getDigit(bin2, i);
        s = (a + b + c) % 2; // 뒷자리
        c = (a + b + c) / 2; // carry-out
        answer = makeAnswer(answer, s);
        // s를 asnwer에 계속 추가해서 아무튼 새로운 답을 늘려나갈것이다.
    }

    if (c == 1)
    {
        answer = makeAnswer(answer, c);
    }
    cout << answer << endl;
    return answer;
}

int main()
{
    solution("11", "1000");
}

// 이 코드가 확실이 디바이드 먼쿼가 왜 중요한지 나오는 과정이다.
// 아 진짜 써야되는데,,,,, 다 타이핑 하게 되면 내가 무슨일을 하는지 햇갈려진다.
/*
한꺼번에 한 함수에서 구현하게 된다면 실수할 확률이 높아진다.
0. 나 스스로를 따라해라. 내가 하는 행동을 컴퓨터가 하도록 구현하는 것이다.
ex. 2진수 덧셈 하려면 무조건 뒤부터, 긴 숫자를 위에 적고 덧셈을 할것이다. 그럼 그렇게 프로그래밍을 해라.
1. 패턴 반복
2. 블랙박스 만드록 채우기..... ******************* 죨라 중요,,,,
*/
