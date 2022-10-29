#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isSame(string A, string B, int shift)
{
    bool returnVal = true;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] != B[(i + shift) % B.size()])
            returnVal = false;
    }

    return returnVal;
}
int solution(string A, string B)
{
    int answer = -1;

    for (int i = 0; A.size() == B.size() && i < A.size(); i++)
    {
        bool rotate = isSame(A, B, i);
        if (rotate)
            answer = i;
    }

    // cout << answer << endl;
    return answer;
}
int main()
{
    solution("apple", "elppa");
}