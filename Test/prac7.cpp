#include <iostream>
#include <string>
#include <vector>

using namespace std;

char change(char c)
{
    if (c >= 'a')
        c -= 'a' - 'A';
    else
        c += 'a' - 'A';

    return c;
}
string solution(string my_string)
{
    string answer = "";

    for (int i = 0; i < my_string.size(); i++)
    {
        answer += change(my_string[i]);
    }

    cout << answer << endl;
    return answer;
}
int main()
{
    solution("cccCCC");
}