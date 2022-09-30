#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int makeInteger(string strNum)
{
    int num = 0;
    for (int i = 0; i < strNum.size(); i++)
    {
        int temp = strNum[i] - '0';
        int multiplier = 1;
        // 자리수 맞추기
        for (int j = 0; j < strNum.size() - i - 1; j++)
        {
            multiplier *= 10;
            cout << "mul: " << multiplier << endl;
        }

        num += temp * multiplier;
        cout << "num: " << num << endl;
    }
    // num = stoi(strNum);

    return num;
}
int solution(string my_string)
{
    int answer = 0;
    string connect = "";

    for (int i = 0; i < my_string.size() - 1; i++)
    {
        if (my_string[i] < 58 && ((my_string[i + 1] > 58) || my_string[i + 1] == my_string[my_string.size() - 1])) // 현재는 숫자, 다음은 문자인 경우 또는 문자열 마지막인 경우
        {
            connect += my_string[i];
            // 문자열의 마지막이라면
            if (my_string[i + 1] == my_string[my_string.size() - 1] && my_string[i + 1] < 58)
            {
                connect += my_string[i + 1];
            }

            cout << "connect: " << connect << endl;
            answer += makeInteger(connect);
            connect = "";
            cout << answer << endl;
        }
        else if (my_string[i] < 58 && my_string[i + 1] < 58)
        {
            connect += my_string[i];
        }
    }
    return answer;
}

int main()
{
    solution("asdfasdfasdfasdfasdfasdfasdfasdfas1000as1234df");
}