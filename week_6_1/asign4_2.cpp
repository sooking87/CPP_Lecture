#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getSetVec(vector<int> factors)
{
    factors.erase(unique(factors.begin(), factors.end()), factors.end());
    return factors;
}
vector<int> solution(int n)
{
    vector<int> answer;
    vector<int> factors;
    int i = 2;
    while (n != 1)
    {
        if (n % i == 0)
        {
            n /= i;
            factors.push_back(i);
            i = 1;
        }
        i++;
    }

    sort(factors.begin(), factors.end());
    answer = getSetVec(factors);
    for (auto v : answer)
    {
        cout << v << " ";
    }
    return answer;
}
int main()
{
    solution(36);
}