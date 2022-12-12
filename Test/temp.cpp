#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Util
{
public:
    static bool isDiv(int num1, int num2);
    static bool isPrime(int num);
};
class P
{
protected:
    int n;

public:
    P(int n);
    virtual int solution() = 0;
};
class P8 : public P
{
public:
    P8(int n);
    virtual int solution();
};
class P91 : public P
{
protected:
    int m;

public:
    P91(int n);
    virtual int solution();
};
class P92 : public P
{
protected:
    int m;

public:
    P92(int n);
    virtual int solution();
};
class P10 : public P
{
public:
    P10(int n);
    virtual int solution();
};
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
    int returnAns = 0;
    for (int i = 2; i <= n; i++)
    {
        if (Util::isPrime(i))
        {
            returnAns++;
        }
    }
    return returnAns;
}
/* P9 정의 */
P91::P91(int n, int m) : P(n)
{
    this->m = m;
}
P92::P92(int n, int m) : P(n)
{
    this->m = m;
}
int P91::solution()
{
    // 최대 공약수 구하기
    int gcd = 0;
    int min = n > m ? m : n;
    int max = n > m ? n : m;

    for (int i = min; i > 0; i--)
    {
        if (Util::isDiv(min, i) && Util::isDiv(max, i))
        {
            gcd = i;
            break;
        }
    }
    return gcd;
}
/* P10 정의 */
P10::P10(int n) : P(n)
{
    ;
}
int P10::solution()
{
    int returnNum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            returnNum += i;
            while (n % i != 0)
            {
                n = n / i;
            }
        }
    }
    return returnNum;
}
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
        if (num % i == 0)
        {
            break;
        }
    }
    if (i == num)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    P *first, *second;
    first = new P8(12);
    second = new P8(5);
    cout << "P8, 12: " << first->solution() << endl;
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