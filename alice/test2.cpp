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

    cout << "����� ��� ���� ����: " << endl;
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
    // Ȯ��
    for (auto i : v)
    {
        cout << i << endl;
    }
    // �ϴ� ����߿��� 2���� ��� ���� ��� ���� ����
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

    // first�� second�� ���ؼ� �ش� ���� ���ϱ�
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
        // Ȯ��
        cout << "winner vector Ȯ��" << endl;
        for (auto i : winner)
        {
            cout << i << endl;
        }
    }
    // ���� ���ϱ�
    do
    {
        int stand = 0;
        // for (int i = 0; i < v.size(); i++)
        // {
        //     cout << v[i] << " ";
        // }
        // cout << '\n';
        // a-b-c�� �� a-b, a-c, b-c
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