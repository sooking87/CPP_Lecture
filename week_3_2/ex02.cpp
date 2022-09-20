#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

// sort 안하고 문제 해결하기
bool solution2(vector<int> arr)
{
    bool ans = true;
    vector<int> count;
    // 0으로 초기화
    for (int i = 0; i < arr.size(); i++)
    {
        count.push_back(0);
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 0 && arr[i] <= count.size())
        {
            count[arr[i] - 1]++;
        }
    }

    // if (accumulate(count.begin(), count.end(), 0) == count.size())
    // {
    //     ans = true;
    // }
    // else
    // {
    //     ans = false;
    // }
    for (int i = 0; i < count.size(); i++)
    {
        if (count[i] != 1)
        {
            ans = false;
            break;
        }
    }

    return ans;
}
bool solution(vector<int> arr)
{
    bool answer = true;
    // 정렬
    sort(arr.begin(), arr.end());

    for (int i = 1; i <= arr.size(); i++)
    {
        if (arr[i - 1] != i)
        {
            answer = false;
            break;
        }
    }
    cout << answer << endl;
    return answer;
}

int main()
{
    solution2({4, 1, 3, 2});
}