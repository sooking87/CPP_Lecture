#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> words;

    for (string s; cin >> s && s != "quit";)
        words.push_back(s);

    sort(words.begin(), words.end());

    // 겹치지 않은 단어들만 모아놓음
    vector<string> words2;
    if (words.size() > 0)
    {
        words2.push_back(words[0]);
        for (int i = 1; i < words.size(); i++)
        {
            if (words[i - 1] != words[i])
                words2.push_back(words[i]);
        }
    }

    int len1 = words.size();
    int len2 = words2.size();

    cout << "found " << words.size() - words2.size() << " duplicates" << endl;
    
    for (string s : words2)
    {
        cout << s << endl;
    }
}