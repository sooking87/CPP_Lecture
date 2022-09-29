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
        result += binary * i;
        num /= 2;
    }
    return result;
}
int twoConvertTen(int num)
{
    int result = 0, mul = 1;
    while (num > 0)
    {
        if (num % 2)
        {
            result += mul;
        }
        mul *= 2;
        num /= 10;
    }

    return result;
}
// int toInteger(string strNum)
// {
//     int result = 0;
//     long long mul = pow(10, (strNum.size() - 1));
//     cout << "mul: " << mul << endl;
//     for (int i = 0; i < strNum.size(); mul /= 10, i++)
//     {
//         int temp = 0;
//         if (strNum[i] == '1')
//         {
//             temp = 1;
//         }
//         else
//         {
//             temp = 0;
//         }
//         result += temp * mul;
//     }
//     return result;
// }
string addBin(int num1, int num2)
{
    int ten_num1 = twoConvertTen(num1);
    int ten_num2 = twoConvertTen(num2);
    // ok

    int result = ten_num1 + ten_num2;
    long long answer = tenConvertTwo(result);
    string return_ans = to_string(answer);

    return return_ans;
}
string solution(string bin1, string bin2)
{
    string answer = "";

    if (bin1 == "")
    {
        bin1 = "0";
    }
    if (bin2 == "")
    {
        bin2 = "0";
    }
    int num_bin1 = stoi(bin1);
    int num_bin2 = stoi(bin2);

    answer = addBin(num_bin1, num_bin2);
    return answer;
}

int main()
{
    solution("1011111111", "1100000011");
}