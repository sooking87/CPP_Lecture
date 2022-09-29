#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int n)
{
    int answer = 0;
    vector<int> abs_diff;

    for (int i = 0; i < array.size(); i++)
    {
        int diff = abs(array[i] - n);
        abs_diff.push_back(diff);
    }

    int min_diff = abs_diff[0];
    int min_index = 0;
    for (int i = 1; i < array.size(); i++)
    {
        if ((min_diff >= abs_diff[i]))
        {
            if (min_diff == abs_diff[i])
            {
                min_index = (array[min_index] < array[i]) ? min_index : i;
            }
            else
            {
                min_index = i;
            }
            min_diff = abs_diff[i];
        }
    }

    answer = array[min_index];
    cout << min_index << endl;
    return answer;
}
int main()
{
    solution({3, 10, 17}, 13);
}