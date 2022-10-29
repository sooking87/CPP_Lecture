#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getMax(vector<int> cnt)
{
    int returnVal = -1;
    sort(cnt.begin(), cnt.end());
    int tlqkf = cnt.size() - 2;

    if (cnt[cnt.size() - 2] != cnt[cnt.size() - 1])
        returnVal = cnt[cnt.size() - 1];

    return returnVal;
}
int solution(vector<int> array)
{
    int answer = -1;
    vector<int> cnt;
    int temp = 1;
    sort(array.begin(), array.end());

    for (int i = 0; i < array.size() - 1; i++)
    {
        if (array[i] == array[i + 1])
        {
            temp++;
            if (i == array.size() - 2)
            {
                cnt.push_back(temp);
            }
        }
        else
        {
            cnt.push_back(temp);
            temp = 1;
        }
    }
    cout << "cnt" << endl;

    // 마지막 숫자 처리
    // if (array[array.size() - 2] == array[array.size() - 1])
    // {
    //     cnt.push_back(temp);
    // }
    // else
    //     cnt.push_back(1);

    sort(cnt.begin(), cnt.end() + 1);
    // int tlqkf = cnt.size();
    // cout << tlqkf << endl;
    if (cnt[cnt.size() - 2] != cnt[cnt.size() - 1])
    {
        answer = cnt[cnt.size() - 1];
    }

    return answer;
}
int main()
{
    solution({1, 2, 3, 4, 3, 3});
}