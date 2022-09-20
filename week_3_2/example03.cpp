#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 중복한 워드는 한 번만 출력시키고 싶다.
// point: 단어 벡터를 정렬시킨 후 앞뒤로 같은지 다른지를 판단한다.

int main()
{
    vector<string> words;
    for (string s; cin >> s && s != "quit";)
    {
        words.push_back(s);
    }

    sort(words.begin(), words.end());

    // 겹치지 않는 단어들을 넣어놓을 벡터
    vector<string> w2;
    if (words.size() > 0)
    {
        w2.push_back(words[0]);
        for (int i = 1; i < words.size(); i++)
        {
            if (words[i - 1] != words[i])
                w2.push_back(words[i]);
        }
    }

    cout << "found " << words.size() - w2.size() << " duplicates" << endl;
    for (string s : w2)
    {
        cout << s << endl;
    }
}
