#include <string>
#include <vector>

using namespace std;

class Util
{
public:
    static bool isDiv(int num1, int num2);
};
class Hsard
{
private:
    int x;
    int getSum();

public:
    Hsard(int x);
    bool solve();
};
bool Util::isDiv(int num1, int num2)
{
    if (num1 % num2 == 0)
        return true;
    else
        return false;
}
Hsard::Hsard(int x)
{
    this->x = x;
}
int Hsard::getSum()
{
    int sum = 0;
    int copy_x = x;
    for (int i = copy_x; i > 0; i /= 10)
    {
        sum += (i % 10);
    }
    return sum;
}
bool Hsard::solve()
{
    int sum = getSum();
    if (Util::isDiv(x, sum))
    {
        return true;
    }
    return false;
}
bool solution(int x)
{
    bool answer = true;
    Hsard h(int x);
    answer = h.solve();
    return answer;
}