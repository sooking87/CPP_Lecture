#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> move(vector<int> cur, string key, vector<int> board)
{
    // 지금 현재 위치를 입력받아ㅡ key값에 대해서 왼쪽인지, 오른쪽인지, 위, 아래인지를 받고, board를 전달받는다.
    if (key == "up")
    {
        if (cur[1] + 1 < (board[1] / 2))
        {
            cur[1]++;
        }
    }
    else if (key == "down")
    {
        if (cur[1] - 1 > -(board[1] / 2))
        {
            cur[1]--;
        }
    }
    else if (key == "left")
    {
        if (cur[0] - 1 > -(board[0] / 2))
        {
            cur[0]--;
        }
    }
    else
    {
        if (cur[0] + 1 < (board[0] / 2))
        {
            cur[0]++;
        }
    }

    return cur;
}
vector<int> solution(vector<string> keyinput, vector<int> board)
{
    vector<int> answer;
    // 모든 keyinput에 대해서 이동하겠다. 단. 일단 처음 출발은 (0, 0)이고 여기를 시작으로 keyinput에 대해서 move하겠다. 전체 사이즈를 조심해야된다. 전체 사이즈를 주의하면서 이동시킨다.
    answer.push_back(0);
    answer.push_back(0);
    for (int i = 0; i < keyinput.size(); i++)
    {
        answer = move(answer, keyinput[i], board);
    }
    return answer;
}
int main()
{
    solution({"right", "right", "right", "right", "right", "right", "right"}, {10, 10});
}