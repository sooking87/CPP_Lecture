#include <iostream>
#include <string>
#include <vector>

using namespace std;

string getAnswer(int x, int const_num)
{
    string answer = "";
    string str_x = "";
    string str_const = to_string(const_num);
    // x 계수가 1인 경우 처리
    if (x != 1)
    {
        str_x = to_string(x);
    }

    // 0인 경우는 답에 포함시켜서 리턴시킴 안됨
    if (x > 0 && const_num > 0)
    {
        answer += str_x;
        answer += "x + ";
        answer += str_const;
    }
    else if (x > 0 && const_num == 0)
    {
        answer += str_x;
        answer += "x";
    }
    else if (x == 0 && const_num > 0)
    {
        answer += str_const;
    }

    return answer;
}
string solution(string polynomial)
{
    string answer = "";
    int x_num = 0;
    int const_num = 0;
    string temp = "";

    for (int i = 0; i < polynomial.size(); i++)
    {
        if (polynomial[i] >= '0' && polynomial[i] <= '9')
        {
            temp += polynomial[i];
        }
        else if (polynomial[i] == 'x')
        {
            if (temp == "")
            {
                x_num += 1;
            }
            else
            {
                x_num += stoi(temp);
            }
            cout << "x_num: " << x_num << endl;
            temp = "";
        }
        else if (polynomial[i] == ' ' && temp != "")
        {
            const_num += stoi(temp);
            temp = "";
            cout << "const_num: " << const_num << endl;
        }
    }
    if (temp != "")
    {
        const_num += stoi(temp);
        cout << "const_num: " << const_num << endl;
    }

    answer = getAnswer(x_num, const_num);
    cout << "answer: " << answer << endl;

    return answer;
}
int main()
{
    solution("x");
}