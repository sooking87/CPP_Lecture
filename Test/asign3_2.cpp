#include <iostream>
#include <string>
#include <vector>

using namespace std;

int getInteger(string strNum)
{
    int sum = 0;
    int k = 1;
    for (int i = strNum.size() - 1; i >= 0; i--, k *= 10)
    {
        sum += (strNum[i] - '0') * k;
    }

    return sum;
}
int solution(string my_string)
{
    int answer = 0;
    string temp = "";

    for (int i = 0; i < my_string.size(); i++)
    {
        if (my_string[i] >= '0' && my_string[i] <= '9')
        {
            temp += my_string[i];
        }
        else
        {
            answer += getInteger(temp);
            temp = "";
        }
    }
    if (temp != "")
    {
        answer += getInteger(temp);
    }

    cout << answer << endl;
    return answer;
}
int main()
{
    solution("aAb1B2cC34oOp");
}