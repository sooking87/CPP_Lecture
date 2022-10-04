#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers)
{
    int answer = numbers[0] * numbers[1];
    int temp = 0;

    for (int i = 0; i < numbers.size() - 1; i++)
    {
        for (int j = i + 1; j < numbers.size(); j++)
        {
            temp = numbers[i] * numbers[j];
            if (temp > answer)
            {
                answer = temp;
            }
        }
    }
    return answer;
}