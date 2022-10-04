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
        for (int j = 0; j < numbers.size(); j++)
        {
            if (i != j)
            {
                temp = numbers[i] * numbers[j];
                if (temp > answer)
                {
                    answer = temp;
                }
            }
        }
    }
    return answer;
}
int main()
{
    solution({1, 2, 3, 4, 5});
}