#include <string>
#include <vector>
#include <iostream>

using namespace std;

/* 비트 2개까지 허용 */
class FX
{
protected:
    long long n;
    int diff(long long n, long long i);
    virtual int limit(); // ㅍvirtual로 붙히지 않으면 FX에서 부르나 FX2에서 부르나 동일하게 solution을 부르게 된다면 결국 FX의 limit을 부르게 된다. 근데 그때그때 다르게 부르고 싶다. 그때 쓰는 키워드가 virtual이다.

public:
    FX(long long n);
    long long solution();
};
/* 비트 3개까지 허용 */
class FX2 : public FX
{
protected:
    virtual int limit();

public:
    FX2(long long n);
    // sol 1: solution 오버 라이드(완벽하게 같은 것) -> FX의 solution을 그대로 복사해서 붙혀넣기. -> 찝찝함 왜? FX와 FX2의 solution 함수가 편의상 복붙한거니까. 이래도 원하는 결과가 잘 나오지만 이렇게 하는 것은 별로 C++ 스럽지 않다. c++은 코드의 중복을 최소화 한다.
};

/* FX 정의 */
FX::FX(long long n)
{
    this->n = n;
}
// 교수님은 생성자, solution을 넣어놓고, 일단 전반적인 틀을 만듬 전반적인 틀이란 diff 의 개수가 2보다 크면 계속 i를 증가하면서 반복문을 돈다는 틀을 말한다.
long long FX::solution()
{
    long long i;
    for (i = n + 1; diff(n, i) > limit(); i++)
    {
    }
    return i;
}
int FX::diff(long long n, long long i)
{
    int count = 0;
    int len = sizeof(n) * 8; // sizeof를 통해서 바이트를 구하고 비트 수 구하기
    long long mask = 1;      // mask
    for (int k = 0; k < len; k++)
    {
        /*
        n&mask: 1의 자리가 뽑힌다.    i&mask
        */
        if ((n & mask) != (i & mask)) // 다른 비트를 카운트함
        {
            count++;
        }
        mask = mask << 1;
    }
    return count;
}
int FX::limit()
{
    return 2;
}

/* FX2 정의 */
FX2::FX2(long long n) : FX(n)
{
}
int FX2::limit()
{
    return 3;
}
int main()
{
    long long n = 7;
    FX myfx(n);   // 11 예상
    FX2 myfx2(n); // 9 예상
    cout << n << " : " << myfx.solution() << endl;
    cout << n << " : " << myfx2.solution() << endl;
}

/*

웬만하면 protected로 웬만하면 상수 사용잘 하지 말고
virtual 정의 잘 해놓고/
*/