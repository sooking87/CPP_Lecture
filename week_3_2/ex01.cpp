#include <iostream>
#include <string>
using namespace std;
int solution(int n)
{

    int answer = 0;
    for (int i = n; i > 0; i = i / 10)
    {
        answer += i % 10;
    }

    cout << answer << endl;
    return answer;
}

int main()
{
    solution(123);

    return 0;
}