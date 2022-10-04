#include <iostream>
#include <string>
#include <vector>

using namespace std;

int getFactorial(int num, int i)
{
    return num * i;
}
int solution(int n)
{
    int answer = 0;
    int i = 1;
    int fact = 1;

    while (true)
    {
        if (fact > n)
        {
            break;
        }
        i++;
        fact = getFactorial(fact, i);
    }

    answer = i - 1;
    return answer;
}
int main()
{
    solution(3628800);
}