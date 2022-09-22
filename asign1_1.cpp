#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array)
{
    int answer = 0;

    for (auto ele : array)
    {
        cout << ele << endl;
        for (int i = ele; i > 0; i /= 10)
        {
            if (i % 10 == 7)
            {
                answer++;
            }
        }
    }
    return answer;
}

int main()
{
    vector<int> array = {7, 17, 77};
    solution(array);
}