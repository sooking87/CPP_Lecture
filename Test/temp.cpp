#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Util
{
public:
    static bool isDiv(int num1, int num2);
    static bool isPrime(int num);
};
/* P 선언 */
class P
{
protected:
    int n;

public:
    P(int n);
    virtual int solution() = 0;
};
/* P8 선언 */
class P8 : public P
{
public:
    P8(int n);
    virtual int solution();
};
/* P9 선언 */
class P9 : public P
{
private:
    int m;

public:
    P9(int n, int m);
    virtual int solution();
};
/* P92 선언 */
class P92 : public P9
{
private:
    int m;

public:
    P92(int n, int m);
    virtual int solution();
};
/* P10 선언 */
class P10 : public P
{
public:
    P10(int n);
    virtual int solution();
};
/* Util 정의 */
bool Util::isDiv(int num1, int num2)
{
    if (num1 % num2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Util::isPrime(int num)
{
    int i;
    for (i = 2; i < num; i++)
    {
        if (Util::isDiv(num, i))
            break;
    }
    if (i == num)
        return true;
    else
        return false;
}
/* P 정의 */
P::P(int n)
{
    this->n = n;
}
/* P8 정의 */
P8::P8(int n) : P(n)
{
    ;
}
int P8::solution()
{
    int cnt = 0;
    for (int i = 2; i <= n; i++)
    {
        if (Util::isPrime(i))
        {
            cnt++;
        }
    }
    return cnt;
}
/* P9 정의 */
P9::P9(int n, int m) : P(n)
{
    this->m = m;
}
int P9::solution()
{
    // 최대 공약수 구하기
    int max = n > m ? n : m;
    int min = n > m ? m : n;
    for (int i = max;; i++)
    {
        if (Util::isDiv(i, max) && Util::isDiv(i, min))
        {
            return i;
        }
    }
}
/* P92 정의 */
P92::P92(int n, int m) : P9(n, m)
{
    ;
}
int P92::solution()
{
    // 최소 공배수 구하기
    int max = n > m ? n : m;
    int min = n > m ? m : n;

    for (int i = min; i > 0; i--)
    {
        if (Util::isDiv(max, i) && Util::isDiv(min, i))
        {
            return i;
        }
    }
}
/* P10 정의 */
P10::P10(int n) : P(n)
{
    ;
}
int P10::solution()
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (Util::isDiv(n, i))
        {
            sum += i;
        }
    }
    return sum;
}
int main()
{
    P *first, *second;
    first = new P8(10);
    second = new P8(5);
    cout << "P8, 10: " << first->solution() << endl;
    cout << "P8, 5: " << second->solution() << endl;
    delete first;
    delete second;

    first = new P10(12);
    second = new P10(5);
    cout << "p10, 12: " << first->solution() << endl;
    cout << "p10, 5: " << second->solution() << endl;
    delete first;
    delete second;

    first = new P9(12, 8);
    second = new P9(12, 6);
    cout << "p9, 12, 8: " << first->solution() << endl;
    cout << "p9, 12, 6: " << second->solution() << endl;
    delete first;
    delete second;

    first = new P92(12, 8);
    second = new P92(12, 6);
    cout << "p92, 12, 8: " << first->solution() << endl;
    cout << "p92, 12, 6: " << second->solution() << endl;
    delete first;
    delete second;
}