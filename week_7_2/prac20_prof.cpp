#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array)
{
    int answer = 0;
    int count[1000];

    int mode;
    int modeCount = -1;
    bool duplicate = false;

    // 0으로 초기화
    for (int i = 0; i < 1000; i++)
        count[i] = 0;
    // array에 있는 숫자를 인덱스로 간주하여 그 숫자가 나올때마다 ++을 하는 형식
    for (int i = 0; i < array.size(); i++)
        count[array[i]]++;

    for (int i = 0; i < 1000; i++)
    {
        if (count[i] > modeCount)
        {
            mode = i;
            modeCount = count[i];
            duplicate = false; // 동점자인지 아닌지
        }
        else if (count[i] == modeCount)
        {
            duplicate = true;
        }
    }
    if (!duplicate)
        answer = mode;
    else
        answer = -1;

    return answer;
}