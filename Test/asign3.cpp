#include <string>
#include <vector>
#include <iostream>

using namespace std;

// getDigit 몰랐음.
int getDigit(string bin, int i)
{
    int digit = 0;
    if (bin.size() > i)
        return bin[bin.size() - i - 1] - '0';
    else
        return 0;
}
string solution(string bin1, string bin2)
{
    string answer = "";
    int a = 0;
    int b = 0;
    int carry = 0;
    int temp = 0;

    int len = bin1.size();
    if (len < bin2.size())
        len = bin2.size();

    for (int i = 0; i < len; i++)
    {
        a = getDigit(bin1, i);
        b = getDigit(bin2, i);
        temp = (a + b + carry) % 2;
        carry = (a + b + carry) / 2;
        answer = to_string(temp) + answer;
    }

    // 이거 빼먹음
    if (carry == 1)
        answer = to_string(carry) + answer;

    // cout << answer << endl;
    return answer;
}
int main()
{
    solution("10", "11");
}