#include <string>
#include <vector>

using namespace std;

class getAnswer
{
private:
    int n;

public:
    getAnswer(int n);
    int getDivisor();
};
getAnswer::getAnswer(int n)
{
    this->n = n;
}
int getAnswer::getDivisor()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt += i;
        }
    }
    return cnt;
}
int solution(int n)
{
    int answer = 0;
    getAnswer ga(n);
    answer = ga.getDivisor();
    return answer;
}