#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(vector<int> array, int n)
{
    int answer = 0;

    vector<int> absVec;
    for (int i = 0; i < array.size(); i++)
    {
        absVec.push_back(abs(array[i] - n));
    }

    int minDff = absVec[0];
    int minIndex = 0;

    for (int i = 1; i < absVec.size(); i++)
    {
        if (minDff >= absVec[i])
        {
            if (minDff > absVec[i])
            {
                minIndex = i;
            }
            else
            {
                if (array[minIndex] > array[i])
                {
                    minIndex = i;
                }
            }
            minDff = absVec[i];
        }
    }

    answer = array[minIndex];
    cout << answer << endl;
    return answer;
}
int main()
{
    solution({3, 10, 17}, 13);
}