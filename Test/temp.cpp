#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/* 최고점 받은 사람들 중에서 k등인 사람 */
class Test
{
protected:
    int k;
    vector<int> score;
    vector<int> getList(vector<int> &score, int n);
    virtual int kBeforeIdx(vector<int> vec);
    virtual int kAfterIdx(vector<int> vec);
    int size();

public:
    Test(int k, vector<int> score);
    vector<int> solution();
    friend ostream &operator<<(ostream &os, vector<int> s);
};
/* 최하점 받은 사람들 중에서 k등인 사람 */
class Test2 : public Test
{
protected:
    virtual int kBeforeIdx(vector<int> vec);
    virtual int kAfterIdx(vector<int> vec);

public:
    Test2(int k, vector<int> score);
};
/* Test 정의 */
Test::Test(int k, vector<int> area)
{
    this->k = k;
    this->score = area;
}
vector<int> Test::getList(vector<int> &score, int n)
{
    vector<int> temp(score.begin(), score.begin() + n + 1);
    sort(temp.begin(), temp.end());
    return temp;
}
int Test::kBeforeIdx(vector<int> vec)
{
    return 0;
}
int Test::kAfterIdx(vector<int> vec)
{
    return vec.size() - k;
}
int Test::size()
{
    int len = score.size();

    return len;
}
vector<int> Test::solution()
{
    vector<int> answer;
    for (int i = 0; i < score.size(); i++)
    {
        vector<int> nList = getList(score, i); // i 번째까지 중 명예의 전당 리스트 뽑기
        if (i < k)
        {
            answer.push_back(nList[kBeforeIdx(nList)]);
        }
        else
        {
            answer.push_back(nList[kAfterIdx(nList)]);
        }
    }
    return answer;
}
ostream &operator<<(ostream &os, vector<int> s)
{
    os << "List of Score: ";
    for (int i = 0; i < s.size(); i++)
    {
        os << s[i] << ", ";
    }
    os << endl;
}
/* Test2 정의 */
Test2::Test2(int k, vector<int> score) : Test(k, score)
{
    ;
}
int Test2::kBeforeIdx(vector<int> vec)
{
    return vec.size() - 1;
}
int Test2::kAfterIdx(vector<int> vec)
{
    return k - 1;
}
int main()
{
    Test t(3, {10, 100, 20, 150, 1, 100, 200});
    Test2 t2(3, {10, 100, 20, 150, 1, 100, 200});
    vector<int> answer = t.solution();
    vector<int> answer2 = t2.solution();
    cout << answer;
    cout << answer2;
}