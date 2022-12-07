#include <string>
#include <vector>
#include <iostream>

using namespace std;

class P13
{
protected:
    vector<vector<int>> arr1;
    vector<vector<int>> arr2;

public:
    P13(vector<vector<int>> arr1, vector<vector<int>> arr2);
    vector<vector<int>> solve();
};

P13::P13(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    this->arr1 = arr1;
    this->arr2 = arr2;
}
vector<vector<int>> P13::solve()
{
    vector<vector<int>> return_vec;
    for (int row = 0; row < arr1.size(); row++)
    {
        int temp = 0;
        vector<int> vec;
        for (int k = 0; k < arr2[0].size(); k++)
        {
            for (int i = 0; i < arr1[row].size(); i++)
            {

                int temp2 = arr1[row][i] * arr2[i][k];
                temp += temp2;
            }
            vec.push_back(temp);
            temp = 0;
        }
        return_vec.push_back(vec);
    }
    for (int i = 0; i < return_vec.size(); i++)
    {
        for (int j = 0; j < return_vec[i].size(); j++)
        {
            cout << return_vec[i][j] << " ";
        }
        cout << endl;
    }
    return return_vec;
}
vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    vector<vector<int>> answer;
    P13 p(arr1, arr2);
    answer = p.solve();
    return answer;
}
int main()
{
    solution({{1, 2, 3}, {4, 5, 6}}, {{1, 2}, {3, 4}, {5, 6}});
}