#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int getAnswer(double sqrt_n)
{
    double temp = sqrt_n - int(sqrt_n);
    if (temp > 0)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}
int solution(int n)
{
    int answer = 0;
    double sqrt_n = sqrt(n);

    answer = getAnswer(sqrt_n);
    cout << answer << endl;
    return answer;
}

int main()
{
    solution(976);
}