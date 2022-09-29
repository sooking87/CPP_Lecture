#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string my_string)
{
    string answer = "";
    for (int i = 0; i < my_string.size(); i++)
    {
        if (my_string[i] >= 65 && my_string[i] <= 90)
        {
            answer.push_back(my_string[i] + 32);
        }
        else if (my_string[i] >= 97 && my_string[i] <= 122)
        {
            answer.push_back(my_string[i] - 32);
        }
    }
    return answer;
}

int main()
{
    solution("cccCC");
}