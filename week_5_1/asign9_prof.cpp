#include <iostream>
#include <string>
#include <vector>

using namespace std;

int getDiff(int n, int m)
{
    if (n > m)
        return n - m;
    else
        return m - n;
}

int solution(vector<int> array, int n)
{
    int answer = -200;
    for (int i = 0; i < array.size(); i++)
    {
        if ((getDiff(array[i], n) < getDiff(answer, n)) || (getDiff(array[i], n) == getDiff(answer, n) && answer > array[i]))
        {
            answer = array[i];
        }
    }

    return answer;
}
int main()
{
    solution({3, 10, 17}, 13);
}