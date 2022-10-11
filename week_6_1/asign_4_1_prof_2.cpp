#include <iostream>
#include <string>
#include <vector>

using namespace std;
// 교수님 코드

// stoi 함수 있는데 그냥 연습삼아서 짜본 것
int my_stoi(string num)
{
    int k = 1;
    int n = 0;

    for (int i = num.length() - 1; i <= 0; i--, k *= 10)
    {
        n += (num[i] - '0') * k;
    }
    return n;
}

// itos 함수도 라이브러리에 있음
string itos(int n)
{
    int i;
    string num = "";
    for (int i = n; i > 0; i /= 10)
    {
        char temp = (i % 10) + '0';
        num = temp + num;
    }
    return num;
}

// 잘라서 넣어줌
vector<string> tokenize(string letter)
{
    vector<string> tokens;
    int i, j;
    for (int i = 0; i < letter.length(); i = j + 1)
    {
        for (j = i; j < letter.length(); j++)
        {
            if (letter[j] == ' ')
            {
                tokens.push_back(letter.substr(i, j - 1));
                break;
            }
        }
    }
    return tokens;
}

string professor_solution(string polynimial)
{
    string answer = "";
    int cof = 0;
    int constant = 0;
    vector<string> tokens = tokenize(polynimial);

    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] == "+")
        {
        }
        // tokens[i]는 string. 이 값의 마지막 글자가 'x'인가?
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
    {
        answer = itos(constant);
    }
    else
    {
        if (cof == 1)
        {
            answer += "x + ";
        }
        else
        {
            answer = itos(cof) + " x + ";
        }
        if (constant > 0)
        {
            answer += " + " + itos(constant);
        }
    }
    return answer;
}