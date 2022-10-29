#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(int n)
{
    int answer = 0;
    for (int i = 1; i <= 1000; i++)
    {
        if (i * i == n)
            answer = 1;
    }
    if (answer == 0)
        answer = 2;

    return answer;
}
int main()
{
    solution(144);
}