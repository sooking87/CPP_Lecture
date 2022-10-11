#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string letter)
{
    string answer = "";
    string temp = "";
    vector<string> morse = {
        ".-",
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

    for (int i = 0; i < letter.size(); i++)
    {
        if (letter[i] != ' ')
        {
            temp += letter[i];
        }
        else
        {
            auto it = find(morse.begin(), morse.end(), temp);
            char alpha = (it - morse.begin()) + 'a';
            answer += alpha;
            temp = "";
        }
    }
    auto it = find(morse.begin(), morse.end(), temp);
    char alpha = (it - morse.begin()) + 'a';
    answer += alpha;

    cout << answer << endl;

    return answer;
}
int main()
{
    solution(".... . .-.. .-.. ---");
}