#include <string>
#include <vector>
#include <iostream>

using namespace std;

int countDigit(int order, int num)
{
    int cnt = 0;
    for (int i = order; i > 0; i /= 10)
    {
        if (i % 10 == num)
        {
            cnt++;
        }
    }

    return cnt;
}
int solution(int order)
{
    int answer = 0;

    // countDigit은 order 안에 3, 6, 9가 각각 몇번 들어있는지를 확인하는 함수이다.
    answer += countDigit(order, 3);
    answer += countDigit(order, 6);
    answer += countDigit(order, 9);
    cout << answer << endl;
    return answer;
}

int main()
{
    solution(2943);
}