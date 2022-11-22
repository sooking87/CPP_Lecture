#include <string>
#include <vector>

using namespace std;

class getNum
{
private:
    int n;
    int m;

public:
    getNum(int n, int m);
    int getMax(); // 최대 공약수 구하기
    int getMin(); // 최소 공배수 구하기
};
getNum::getNum(int n, int m)
{
    this->n = n;
    this->m = m;
}
int getNum::getMax()
{
    int max = 0;
    int small = n > m ? m : n;
    for (int i = small; i > 0; i--)
    {
        if (m % i == 0 && n % i == 0)
        {
            max = i;
        }
    }
    return max;
}
int getNum::getMin()
{
    int min = 0;
    int big = n > m ? m : n;
    for (int i = big;; i++)
    {
        if (i % m == 0 && i % n == 0)
        {
            min = i;
            break;
        }
    }
    return min;
}
vector<int> solution(int n, int m)
{
    vector<int> answer;
    getNum gn(n, m);
    answer.push_back(gn.getMax());
    answer.push_back(gn.getMin());
    return answer;
}