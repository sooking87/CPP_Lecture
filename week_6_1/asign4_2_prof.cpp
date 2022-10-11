#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> solution(int n)
{
    vector<int> answer;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            answer.push_back(i);
            // n을 i로 나눌 수 있을 때까지 나눈다. 졸라 핵심
            // 이걸 넣어주지 않으면 모든 약수가 들어간다. 소인수가 들어가는게 아니라. 나누어 떨어지지 않으 때까지 같은 수로 나눈다. 그렇게 소인수 분해를 한ㄷ.. 그거를 그대로 따라한 것이다.
            while (n % i == 0)
            {
                n = n / i;
            }
        }
    }
    return answer;
}
int main()
{
}
