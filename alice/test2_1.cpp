#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

vector<string> solution(vector<vector<string>> specs)
{
    vector<string> result;
    vector<string> winner;
    for (int i = 0; i < specs.size(); i++)
    {
        int f = 0;
        int s = 0;
        if (i != specs.size() - 1)
        {
            f = stoi(specs[i][1]) + stoi(specs[i][2]) * stoi(specs[i + 1][1]);
            s = stoi(specs[i + 1][1]) + stoi(specs[i + 1][2]) * stoi(specs[i][1]);
        }
        else
        {
            f = stoi(specs[i][1]) + stoi(specs[i][2]) * stoi(specs[0][1]);
            s = stoi(specs[0][1]) + stoi(specs[0][2]) * stoi(specs[i][1]);
        }

        if (f - s > 0)
        {
            winner.push_back(specs[i][0]);
        }
        else
        {
            if (i == specs.size() - 1)
            {
                winner.push_back(specs[0][0]);
            }
            else
            {
                winner.push_back(specs[i + 1][0]);
            }
        }
    }
    for (auto i : winner)
    {
        cout << i << endl;
    }
    vector<int> cnt = {0};
    for (int i = 0; i < specs.size(); i++)
    {
        if
    }
    return result;
}
int main()
{
    solution({{"A", "10", "3"}, {"B", "20", "4"}, {"C", "15", "5"}});
}