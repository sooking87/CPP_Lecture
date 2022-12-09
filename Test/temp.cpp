#include <string>
#include <vector>
#include <iostream>

using namespace std;

class MarketList
{
protected:
    vector<string> want;
    vector<int> number;

public:
    MarketList(vector<string> want, vector<int> number);
    bool operator==(vector<string> discountList);
};
MarketList::MarketList(vector<string> want, vector<int> number)
{
    this->want = want;
    this->number = number;
}
bool MarketList::operator==(vector<string> discountList)
{
    vector<int> copy(number);
    int i;
    for (i = 0; i < discountList.size(); i++)
    {
        for (int j = 0; j < want.size(); j++)
        {
            if (want[j] == discountList[i])
            {
                copy[j]--;
            }
        }
    }
    for (int i = 0; i < copy.size(); i++)
    {
        if (copy[i] != 0)
        {
            return false;
        }
    }
    return true;
}
int solution(vector<string> want, vector<int> number, vector<string> discount)
{
    int answer = 0;
    // want의 number와 discount len10에 맞는지 확인.
    MarketList list(want, number);
    int i;
    for (i = 0; i < discount.size() - 9; i++)
    {
        vector<string> temp(discount.begin() + i, discount.begin() + 10 + i);
        if (list == temp)
        {
            answer++;
        }
    }
    cout << answer << endl;
    return answer;
}
int main()
{
    solution({"banana", "apple", "rice", "pork", "pot"}, {3, 2, 2, 2, 1}, {"chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana"});
}