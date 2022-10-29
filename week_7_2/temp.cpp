// 교수님 풀이
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
    int start = (total / num);
    int sub = num / 2;
    if (num % 2 == 0)
    {
        sub--;
    }
    int standard = start - sub;

    for (int i = 0; i < num; i++, standard++)
    {
        answer.push_back(standard);
    }

    for (auto i : answer)
        cout << i << endl;
    return answer;
}
int main()
{
    solution(5, 5);
}