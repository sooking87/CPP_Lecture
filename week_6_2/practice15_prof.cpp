#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class notfound
{
};
char translate(string sub)
{
    vector<string> dic = {".-",
                          "-...",
                          "-.-.",
                          "-..",
                          ".",
                          "..-.",
                          "--.",
                          "....",
                          "..",
                          ".---",
                          "-.-",
                          ".-..",
                          "--",
                          "-.",
                          "---",
                          ".--.",
                          "--.-",
                          ".-.",
                          "...",
                          "-",
                          "..-",
                          "...-",
                          ".--",
                          "-..-",
                          "-.--",
                          "--.."};
    for (int i = 0; i < dic.size(); i++)
    {
        if (sub == dic[i])
            return 'a' + i;
    }
    // for 문제에서 한번도 안걸린경우. -> a~z에 해당하지 않는 문자가 input이 된 경우 notfound error를 throw 함.
    throw notfound();
}

string solution(string letter)
{
    string answer = "";
    // 다른 방법  : ' '를 기준으로 잘라서 그 크기만큼 반복문을 돌려서 진행하면된다.
    // for (int i = 0; i < letter.size(); i++)
    // {
    //     try
    //     {
    //         answer += translate(to_string(letter[i]));
    //     }
    //     catch (notfound e)
    //     {
    //         cout << "notfound " << endl;
    //     }
    // }

    int j, i; // scope문제로 인해서 이렇게 바꾸었다. j가 포문 안에 있다면 무의미한 j가 이씩 때ㅜㅁㄴ이다.
    for (i = 0; i < letter.length() - 1; i = j + 1)
    {
        for (j = i; j < letter.length(); j++)
        {
            if (letter[j] == ' ')
            {
                answer += translate(letter.substr(i, j - i)); // j - i가 맞는지
                break;
            }
        }
    }

    if (j == letter.length())
        answer += translate(letter.substr(i, j - i + 1)); // j - i + 1이 맞는지 이게 한틱 차이가 중요하다.

    cout << answer << endl;
    return answer;
}
int main()
{
    solution(".... . .-.. .-.. ---");
}