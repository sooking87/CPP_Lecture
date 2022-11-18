#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> kyul)
{
    int answer = 0;
    vector<int> kyul_up = kyul;
    vector<int> kyul_down = kyul;
    int answer_up = 0;
    int answer_down = 0;
    for (int i = 1; i < kyul.size(); i++)
    {
        if (kyul_up[i - 1] > kyul_up[i])
        {
            answer_up++;
            kyul_up[i] = kyul_up[i - 1];
        }
        if (kyul_down[i - 1] < kyul_down[i])
        {
            answer_down++;
            kyul_down[i - 1] = kyul_down[i];
        }

        cout << "answer_up: " << answer_up << endl;
        cout << "answer_down: " << answer_down << endl;
    }

    answer = answer_up < answer_down ? answer_up : answer_down;

    cout << "kyul_up" << endl;
    for (auto i : kyul_up)
    {
        cout << i << " ";
    }
    cout << endl
         << "kyul_down" << endl;
    for (auto i : kyul_down)
    {
        cout << i << " ";
    }
    cout << answer << endl;
    return answer;
}
int main()
{
    solution({98, 99, 100});
}