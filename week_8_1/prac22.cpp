#include <iostream>
#include <string>
#include <vector>

using namespace std;

int getMul(int num1, int num2)
{
    int returnVal = 1;
    int min = num1 > num2 ? num2 : num1;
    int max = num1 > num2 ? num1 : num2;

    for (int i = 2; i <= max; i++)
    {
        if (num1 % i == 0 && num2 % i == 0)
        {
            returnVal *= i;
            num1 /= i;
            num2 /= i;
        }
    }

    returnVal *= num1;
    returnVal *= num2;

    return returnVal;
}
// 최대 공약수 구하기
int getDiv(int num1, int num2)
{
    int min = num1 > num2 ? num2 : num1;
    int returnVal = 0;
    for (int i = min; i > 0; i--)
    {
        if (num1 % i == 0 && num2 % i == 0)
        {
            returnVal = i;
            break;
        }
    }

    return returnVal;
}
vector<int> solution(int denum1, int num1, int denum2, int num2)
{
    vector<int> answer;
    int resultNum = 0;
    int resultDenum = 0;

    // 최소 공배수 구하기 -> 굳이 필요는 없음. 왜냐면 나중에 어차피 또 기약분수를 만들기 위해서 처리를 해주어야되기 때문
    resultNum = getMul(num1, num2);
    resultDenum = (denum1 * (resultNum / num1) + denum2 * (resultNum / num2));

    // 최대 공약수
    int div = getDiv(resultDenum, resultNum);
    resultDenum /= div;
    resultNum /= div;

    answer.push_back(resultDenum);
    answer.push_back(resultNum);

    for (auto i : answer)
        cout << i << endl;
    return answer;
}
int main()
{
    solution(6, 4, 4, 4);
}