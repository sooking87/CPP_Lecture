#include <iostream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isPalind(int num)
{
    string strNum = to_string(num);
    int len = strNum.size();

    if (len % 2 != 0)
        len--;

    for (int i = 0; i < (len / 2); i++)
    {
        if (strNum[i] != strNum[strNum.size() - i - 1])
            return false;
    }
    return true;
}
int solution(int n, int m)
{
    int answer = 0;

    for (int i = n; i <= m; i++)
    {
        if (isPalind(i))
            answer++;
    }
    cout << answer << endl;
    return answer;
}
int main()
{
    solution(1, 100);
}