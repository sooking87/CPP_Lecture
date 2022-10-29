#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total)
{
    vector<int> answer;
    int standard = total / num;
    int start = standard - (num / 2);
    if (num % 2 == 0)
        start++;

    for (int i = start; i < start + num; i++)
    {
        answer.push_back(i);
    }
    return answer;
}
int main()
{
    solution(3, 12);
}