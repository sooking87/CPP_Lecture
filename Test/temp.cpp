#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isDupli(vector<string> words, int index)
{
    bool isDup = false;

    for (int i = 0; i < index; i++)
    {
        cout << "words[i]: " << words[i] << endl;
        if (words[i] == words[index])
            isDup = true;
    }

    return isDup;
}
vector<int> solution(int n, vector<string> words)
{
    vector<int> answer;
    int pplNum = -1;
    int loop = 0;
    int flag = 0;

    // 고려 사항: 겹치는ㄴ 단어 안됨, 끝말 잇기가 되는지 확인
    for (int i = 0; i < words.size(); i++)
    {
        cout << i << endl;
        if (i % n == 0)
            loop++;
        pplNum = ((i + 1) % n);
        if (pplNum == 0)
            pplNum = n;

        if (!isDupli(words, i))
        {
            if (words[i][words[i].size() - 1] != words[i + 1][0])
            {
                if ((i + 1) % n == 0)
                    loop++;
                pplNum = ((i + 2) % n);
                if (pplNum == 0)
                    pplNum = n;

                flag = 1;
                break;
            }
        }
        else
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {

        answer.push_back(pplNum);
        answer.push_back(loop);
    }
    else
    {
        answer.push_back(0);
        answer.push_back(0);
    }

    for (auto i : answer)
        cout << i << " ";

    return answer;
}
int main()
{
    solution(3, {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"}); // 2 2
}