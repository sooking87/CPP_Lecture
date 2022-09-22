#include <iostream>
#include <string>
#include <vector>

using namespace std;

int sum(int i, int num)
{
    int total = 0;
    for (int j = 0; j < num; j++)
    {
        total += i + j;
    }
    return total;
}
vector<int> solution(int num, int total)
{
    vector<int> answer;
    for (int i = -1000; i <= 1000; i++)
    {
        if (sum(i, num) == total)
        {
            for (int j = 0; j < num; j++)
            {
                answer.push_back(j + i);
            }
            return answer;
        }
    }
}