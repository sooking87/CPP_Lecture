#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void getScore(int &first, int &second, vector<vector<string>> &specs, vector<vector<char>> &match, int i)
{
    cout << "getScore" << endl;
    vector<string> first_vec;
    vector<string> second_vec;
    string first_str = to_string(match[i][0]);
    string second_str = to_string(match[i][1]);
    cout << "first_Str" << first_str << endl;

    if ()

    cout << "대결할 사람 스펙 보기: " << endl;
    for (auto i : first_vec)
    {
        cout << i << " ";
    }
    cout << endl;
    for (auto i : second_vec)
    {
        cout << i << " ";
    }
    cout << endl;
}
vector<string> solution(vector<vector<string>> specs)
{
    vector<string> result;
    vector<vector<char>> match;
    vector<char> winner;
    vector<char> v;
    for (int i = 'A'; i < 'A' + specs.size(); i++)
    {
        v.push_back(i);
    }
    // 확인
    for (auto i : v)
    {
        cout << i << endl;
    }
    // 일단 명수중에서 2명을 골라서 각각 경기 진행 가능
    const int r = 2;

    vector<bool> temp(v.size(), true);
    for (int i = 0; i < v.size() - r; i++)
        temp[i] = false;
    do
    {
        vector<char> arr;
        for (int i = 0; i < v.size(); ++i)
        {
            if (temp[i])
            // cout << v[i] << " ";
            {
                arr.push_back(v[i]);
            }
        }
        match.push_back(arr);
    } while (next_permutation(temp.begin(), temp.end()));

    // first와 second에 대해서 해당 점수 구하기
    for (int i = 0; i < match.size(); i++)
    {
        int first = 0;
        int second = 0;
        getScore(first, second, specs, match, match[i][0], i);
        cout << match[i][0] << "vs" << match[i][1] << endl;
        cout << first << " " << second << endl;
        if (first > second)
        {
            winner.push_back(match[i][0]);
        }
        else
        {
            winner.push_back(match[i][1]);
        }
        // 확인
        cout << "winner vector 확인" << endl;
        for (auto i : winner)
        {
            cout << i << endl;
        }
    }
    // 순서 정하기
    do
    {
        int stand = 0;
        // for (int i = 0; i < v.size(); i++)
        // {
        //     cout << v[i] << " ";
        // }
        // cout << '\n';
        // a-b-c일 때 a-b, a-c, b-c
        // for (int j = 1; j < specs.size(); j++)
        // {
        //     v
        // }

    } while (next_permutation(v.begin(), v.end()));
    return result;
}
int main()
{
    solution({{"A", "10", "3"}, {"B", "20", "4"}, {"C", "15", "5"}});
}