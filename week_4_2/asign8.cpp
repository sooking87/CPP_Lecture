#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int order)
{
    int answer = 0;

    for (int i = order; i > 0; i /= 10)
    {
        int num = i % 10;
        if (num % 3 == 0 && num != 0)
        {
            answer++;
        }
    }
    cout << answer << endl;
    return answer;
}
int main()
{
    solution(10);
}