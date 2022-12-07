#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Grid
{
private:
    vector<vector<int>> grid;
    string s;

public:
    Grid(string s);
    int solve();
    // friend ostream &operator<<(ostream &os, vector<vector<int>> vec);
};

Grid::Grid(string s)
{
    this->s = s;
    for (int i = 0; i < 11; i++)
    {
        vector<int> vec;
        for (int j = 0; j < 11; j++)
        {
            vec.push_back(0);
        }
        grid.push_back(vec);
    }
}
int Grid::solve()
{
    int x = 5;
    int y = 5; // (0, 0)
    for (int i = 0; i < s.size(); i++)
    {
        int flag = 0;
        cout << i << endl;
        if (s[i] == 'U' && y <= 4)
        {
            y++;
            flag = 1;
        }
        else if (s[i] == 'D' && y >= -4)
        {
            y--;
            flag = 1;
        }
        else if (s[i] == 'L' && x >= -4)
        {
            x--;
            flag = 1;
        }
        else if (s[i] == 'R' && x <= 4)
        {
            x++;
            flag = 1;
        }

        if (flag == 1)
            grid[x][y] = 1;
    }

    cout << grid.size() << " " << grid[0].size() << endl;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int solution(string dirs)
{
    int answer = 0;
    Grid g(dirs);
    g.solve();
    return answer;
}
int main()
{
    solution("LULLLLLLU"); //"LULLLLLLU" "ULURRDLLU"
}