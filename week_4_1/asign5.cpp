#include <string>
#include <vector>
#include <iostream>

using namespace std;

int getStartNum(int num, int total)
{
    // startNum이 음수도 가능하다 따라서 -1000부터 1000까지의 범위 중에서 num 개 만큼 더해가면서 getTotal이 total과 같은 경우 시작 숫자를 리턴한다.
    for (int startNum = -1000; startNum <= 1000; startNum++)
    {
        int getTotal = 0;
        for (int i = startNum; i < startNum + num; i++)
        {
            cout << "i: " << i << endl;
            getTotal += i;
            cout << "getTotal: " << getTotal << endl;
        }
        if (getTotal == total)
        {
            return startNum;
        }
    }
}
vector<int> solution(int num, int total)
{
    vector<int> answer;
    int startNum = getStartNum(num, total);
    cout << "StartNum: " << startNum << endl;

    for (int i = startNum; i < startNum + num; i++)
    {
        answer.push_back(i);
    }

    for (auto i : answer)
    {
        cout << i << " ";
    }
    return answer;
}

int main()
{
    solution(5, 15);
}