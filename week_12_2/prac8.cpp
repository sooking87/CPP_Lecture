#include <string>
#include <vector>
#include <cmath>

using namespace std;

class prac
{
private:
    int n;

public:
    prac(int n);
    int solve();
};
prac::prac(int n)
{
    this->n = n;
}
int prac::solve()
{
    int cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        int flag = 0;
        if (i == 2 || i == 3)
        {
            cnt++;
        }
        else
        {
            for (int j = 2; j < sqrt(i); j++)
            {
                if (i % j == 0)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                cnt++;
            }
        }
    }
}

int solution(int n)
{
    int answer = 0;
    prac p(n);
    answer = p.solve();
    return answer;
}