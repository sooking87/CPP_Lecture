#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string s, int n)
{
    string s = "";

    for (int i = 0; i < s.size(); i++)
    {
        char temp = (s[i] + n);
        if (temp > 'z' || (temp > 'Z'))
        {
            temp -= 26;
        }
        s += temp;
    }
    cout << s;
    return s;
}
int main()
{
    solution("ABZ", 1);
}