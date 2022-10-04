#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0;
    int temp = 1;
    for (int i = 1; i < n; i++)
    {
        temp *= i;
        if (temp <= n)
        {
            answer = i;
        }
        else
            break;
    }
    return answer;
}
int main()
{
    solution(3628800);
}