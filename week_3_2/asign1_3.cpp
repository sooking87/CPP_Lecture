#include <iostream>
#include <string>

using namespace std;

int solution(string A, string B)
{
    int answer = 0;
    bool isSame = false;
    string temp = A;
    for (int cnt = 1; cnt <= A.size(); cnt++)
    {
        if (temp == B)
        {
            isSame = true;
            break;
        }
        temp.clear();
        for (int i = 1; i < A.size(); i++)
        {
            temp.push_back(A[i - 1]);
        }
        temp = A[A.size() - 1] + temp;

        answer++;
        A = temp;
    }
    if (!isSame)
    {
        answer = -1;
    }
    cout << answer << endl;
    return answer;
}
int main()
{
    solution("apple", "apple");
}