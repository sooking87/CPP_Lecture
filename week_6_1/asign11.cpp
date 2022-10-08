#include <iostream>
#include <string>
#include <vector>

using namespace std;

int getAnswer(int balls, int share)
{
    double temp = 0;
    int result = 1;
    for (int i = 0; i < share; i++)
    {
        temp = (balls - i) / (share - i);
        result *= temp;
    }

    return result;
}
int getFactorial(int num)
{
    int result = 1;
    for (int i = 1; i <= num; i++)
    {
        result *= i;
    }

    return result;
}
int solution(int balls, int share)
{
    int answer = 0;
    // int fact1 = getFactorial(balls);
    // int fact2 = getFactorial(share);
    // int fact3 = getFactorial(balls - share);

    // answer = fact1 / (fact2 * fact3);
    answer = getAnswer(balls, share);
    std::cout << answer;
    return answer;
}
int main()
{
    solution(5, 3);
}