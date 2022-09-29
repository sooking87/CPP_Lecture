#include <iostream>
#include <string>
#include <vector>

using namespace std;

char change(char c)
{
    if (c > 'Z') // lower case
    {
        c -= 'a' - 'A';
    }
    else // upper case
    {
        c += 'a' - 'A';
    }

    return c;
}
string solution(string my_string)
{
    string answer = "";
    for (int i = 0; i < my_string.length(); i++)
    {
        answer += change(my_string[i]);
        // i번째 캐릭터를 인풋해준다. 그 캐릭터라는 값을 cahnge가 대문자, 소문자로 바꾸어준다. 리턴을 바뀌어진 캐릭터로 리턴
    }
    return answer;
}