#include <iostream>
#include <string>
#include <vector>

using namespace std;

// string -> int로 바꿔줌
int my_stoi(string num)
{
    int k = 1;
    int n = 0;
    for (int i = num.length() - 1; i >= 0; i--, k *= 10)
    {
        n = (num[i] - '0') * k;
    }

    return n;
}
// int -> string으로 바꿔줌
string my_itos(int n)
{
    string num = "";
    for (int i = n; i > 0; i /= 10)
    {
        char temp = (i % 10) + '0';
        num += temp;
    }

    return num;
}
vector<string> tokenize(string letter)
{
    vector<string> tokens;
    int i, j;
    for (i = 0; i < letter.length(); i = j + 1)
    {
        for (j = i; j < letter.length(); j++)
        {
            if (letter[j] == ' ')
            {
                tokens.push_back(letter.substr(i, j - i));
                break;
            }
        }
    }
    return tokens;
}
string solution(string polynomial)
{
    string answer = "";
    int cof = 0;
    int constant = 0;

    vector<string> tokens = tokenize(polynomial);
    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] == "+")
        {
        }
        // x에 대한 항인지를 물어보는 조건문 tokens[i]는 string인데 그 마지막 글자가 x인지 아닌지를 확인하고 싶다.
        else if (tokens[i][tokens[i].length() - 1] == 'x')
        {
            if (tokens[i].length() == 1)
            {
                cof++;
            }
            else
            {
                cof += my_stoi(tokens[i].substr(0, tokens[i].length() - 1));
            }
        }
        else
        {
            constant += my_stoi(tokens[i]);
        }
    }
    if (cof == 0)
        answer = my_itos(constant);
    else
    {
        if (cof == 1)
            answer = "x + " + my_itos(constant);
        else
            answer = my_itos(cof) + "x";
        if (constant > 0)
        {
            answer += " + " + my_itos(constant);
        }
    }
    cout << answer << endl;
    return answer;
}
int main()
{
    solution("3x + 7 + x");
}