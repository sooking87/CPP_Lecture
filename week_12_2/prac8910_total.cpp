#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 1. 우리가 오브젝트를 만들 필요는 없느데 글로벌 함수로 두고 싶지는 않다. 클래스로 쌓여 있는게 좋을 듯 -> 이렇게 되려먼 static 을 이용해서 글로벌 함수를 만든다.
class Utility
{
public:
    static bool isDiv(int a, int b);
    // 2. 기본적으로 모든 변수는 private으로 묶어라. 상속을 염두해둔다면 protected까지. 근데 필요에 따라서 함수는 주로 public으로 오픈이 되어 있다. 근데 모든 함수가 publid인거는 아니다. div &conq에서는 블랙박스를 만들어서 다시 함수를 호출하는 식으로 했어쓴데, 제일 바깥에 있는 함수는 public그 안에 있는 블랙박스는 private, protected로 이해하면 된다. 외부에서는 제일 밖에 있는 함수만 보면 된다. 그 안에서 어떻게 나뉘어져 있는지는 밖에서 알 필요가 없다.
    static bool isPrime(int a);
};
class P : public Utility
{
protected:
    int n;

public:
    P(int n);
    virtual int solution() = 0; // p10 클래스 만들고 난 다음 어떤 가상함수를 만들꺼라고 하는 것이다.
};

class P8 : public P
{
public:
    P8(int n);
    virtual int solution();
};
class P10 : public P8
{
public:
    P10(int n);
    virtual int solution(); //
};
class P9 : public P
{
protected:
    int m;

public:
    P9(int n, int m);
    virtual int solution();
};
class P92 : public P9 // ????????? 소멸자의 경우도 virtual 필요한거 아닌가 => ㅈ금 현재 클래스에 동적으로 할당받은 것이 없기 때문에 기본 소멸자라도 상관이 없다. 하지만 클래스 내의 동적으로 생성된 변수가 잇다면 그거를 지우기 위해서 virtual 소멸자가 필요하다.
{
    // 얘는 최소 공배수만 리턴할 것 이다.
public:
    P92(int n, int m);
    virtual int solution();
};
bool Utility::isDiv(int a, int b)
{
    return (a % b == 0);
}
bool Utility::isPrime(int a)
{
    int i;
    for (i = 2; i < a; i++)
    {
        if (isDiv(a, i))
        {
            break;
        }
    }
    if (i == a)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// 유틸 상속받지 않은ㄱ ㅕㅇ우
// class P8
// {
//     int n;

// public:
//     P8(int n);
//     int solution();
// };
// util 상속받는 법
P::P(int n)
{
    this->n = n;
}
P8::P8(int n) : P(n)
{
    ;
}
int P8::solution()
{
    // cout << "P8 solution" << endl;
    int count = 0;
    for (int i = 2; i <= n; i++)
    {
        // if (Utility::isPrime(i)) // 다른 클래스의 함수를 사용하는 경우
        if (isPrime(i)) // 상속받은 크래스를 사용한믄 경우
        {
            count++;
        }
    }
    return count;
}
P10::P10(int n) : P8(n)
{
    ;
}
// 오버라이드를 하게 된다면 p8의 솔루션은 가상 함수가 아니므로 포인터를 만들어서 p8을 가리키는 포인터가 p10을 new해서 받을 수 ㅣㅇㅆ는데 그렇게 된다면 p8게 호출이 되기 때문에 그런 관계를 고려해서 함수를 만들게 된다며 ㄴ p8의 solution 함수를 가상함수로 만든다.
int P10::solution()
{
    // cout << "P10 solution" << endl;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (isDiv(n, i)) // util > p8 > p10 : p10은 유틸이랑 피팔이 가지고 있는 것을 다 가지고 있다. 여기서 isDiv랑 n 모두 사용할 수 있다.
        {
            sum += i;
        }
    }
    return sum;
}
P9::P9(int n, int m) : P(n)
{
    this->m = m;
}
int P9::solution()
{
    // cout << "P9 solution" << endl;
    int gcd = 1;
    for (int i = 2; i <= n; i++)
    {
        if (isDiv(n, i) && isDiv(m, i))
        {
            gcd = i;
        }
    }
    return gcd;
}
P92::P92(int n, int m) : P9(n, m)
{
}
int P92::solution()
{
    // cout << "P92 solution" << endl;
    int gcd = P9::solution(); // 오버 라이드 하는 중에 부모꺼를 그대로 사용하고 시으면 왼쪽처럼 사용하면 된다.
    return n * m / gcd;
}
int main()
{
    P *first, *second;
    // static이라서 인스턴스 만들지 않고 바로 사용할 수 있다.
    cout << "12, 4: " << Utility::isDiv(12, 4) << endl;
    cout << "13, 4: " << Utility::isDiv(13, 4) << endl;
    cout << "12: " << Utility::isPrime(12) << endl;
    P8 p81(10);

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