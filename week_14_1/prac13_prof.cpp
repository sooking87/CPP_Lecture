#include <string>
#include <vector>
#include <iostream>

using namespace std;

class TDArray
{
private:
    vector<vector<int>> values;
    int getInnerProduct(TDArray ar, int i, int j);

public:
    TDArray(vector<vector<int>> values);
    TDArray operator*(TDArray ar);
    friend ostream &operator<<(ostream &os, TDArray ar);
};

TDArray::TDArray(vector<vector<int>> values)
{
    this->values = values;
}
int TDArray::getInnerProduct(TDArray ar, int i, int j)
{
    int sum = 0;
    for (int k = 0; k < values[0].size(); k++)
    {
        sum += values[i][k] * ar.values[k][j]; /// 비효율적이다 왜? call by value로 넘ㄱ어가기 때문에 매번 복사하면 비효율적 -> 다음 코드
    }
    return sum;
}
TDArray TDArray::operator*(TDArray ar) // ar: 오른쪽 행렬
{
    vector<vector<int>> v;
    // 행은 내꺼, 열은 오른쪽의 열
    for (int i = 0; i < values.size(); i++) // 최종 행으 첫 번재 행렬의 행
    {
        vector<int> row;
        for (int j = 0; j < ar.values[0].size(); j++) // 최종 열은 두 번째 행렬의 열
        {
            row.push_back(getInnerProduct(ar, i, j)); // 나는 this니까 내값은 안넣고
        }
        v.push_back(row);
    }
    return TDArray(v);
}
ostream &operator<<(ostream &os, TDArray ar)
{
    for (int i = 0; i < ar.values.size(); i++)
    {
        for (int j = 0; j < ar.values[0].size(); j++)
        {
            os << ar.values[i][j] << " ";
        }
        os << endl;
    }
    return os;
}
vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    vector<vector<int>> answer;
    cout << (TDArray(arr1) * TDArray(arr2)) << endl;
    return answer;
}
int main()
{
    solution({{1, 2, 3}, {4, 5, 6}}, {{1, 2}, {3, 4}, {5, 6}});
}