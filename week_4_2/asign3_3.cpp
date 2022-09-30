#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board)
{
    vector<int> answer;
    int x = 0;
    int y = 0;
    int max_x = board[0] / 2;
    int min_x = -max_x;
    int max_y = board[1] / 2;
    int min_y = -max_y;
    for (int i = 0; i < keyinput.size(); i++)
    {
        if (x == max_x || x == min_x)
        {
            continue;
        }
        if (y == max_y || y == min_y)
        {
            continue;
        }
        if (keyinput[i] == "left")
        {
            x--;
        }
        if (keyinput[i] == "right")
        {
            x++;
        }
        if (keyinput[i] == "up")
        {
            y++;
        }
        if (keyinput[i] == "down")
        {
            y--;
        }
    }
    answer.push_back(x);
    answer.push_back(y);

    for (auto i : answer)
    {
        cout << i << endl;
    }
    return answer;
}
int main()
{
    solution({"right", "right", "right", "right", "right", "right", "right"}, {10, 10});
}