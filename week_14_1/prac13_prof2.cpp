#include <string>
#include <vector>
#include <iostream>

using namespace std;

class TDArray
{
private:
    vector<vector<int>> values;
    int getInnerProduct(const TDArray &ar, int i, int j); // ref가 더 효율적이다.

public:
    TDArray(vector<vector<int>> values);
    TDArray operator*(const TDArray &ar);
    friend ostream &operator<<(ostream &os, const TDArray &ar);
};

TDArray::TDArray(vector<vector<int>> values)
{
    this->values = values;
}
int TDArray::getInnerProduct(const TDArray &ar, int i, int j)
{
    int sum = 0;
    for (int k = 0; k < values[0].size(); k++)
    {
        sum += values[i][k] * ar.values[k][j]; /// 비효율적이다 왜? call by value로 넘ㄱ어가기 때문에 매번 복사하면 비효율적 -> 다음 코드
    }
    return sum;
}
TDArray TDArray::operator*(const TDArray &ar) // ar: 오른쪽 행렬
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
ostream &operator<<(ostream &os, const TDArray &ar)
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
    cout << (TDArray(arr1) * TDArray(arr2)) << endl; // 에러가 떠 왜냐면 바로 변수를 넣었기 때문에 변수 명이 없어서 일시적인 변수가 되버리기 때문이다. -> 얘를 해결하기 위해서는 아래와 같이 할 수 ㅣㅆ지만 const를 써가지고 임시 변수도 &가 가능하도록 하는 것이다.
    // TDArray array1(arr1), array2(arr2);
    // TDArray result = (array1 * array2);
    // cout << result << endl;
    return answer;
}
int main()
{
    solution({{1, 2, 3}, {4, 5, 6}}, {{1, 2}, {3, 4}, {5, 6}});
}