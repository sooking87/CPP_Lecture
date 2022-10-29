#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array)
{
    int answer = 0;
    int mode;
    int modeCount = -1;
    bool duplicate = false;

    // 맨 첫 번째 숫자(i)가 몇 번 등장했는지를 센다.
    for (int i = 0; i < array.size(); i++)
    {
        int count = 0;
        for (int j = i; j < array.size(); j++)
        {
            if (array[i] == array[j])
                count++;
        }

        if (count > modeCount)
        {
            mode = array[i];
            modeCount = count;
            duplicate = false;
        }
        else if (count == modeCount)
            duplicate = true;
    }

    if (!duplicate)
        answer = mode;
    else
        answer = -1;

    return answer;
}