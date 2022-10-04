#include <iostream>
using namespace std;

class myerror
{
};

int getDiv(int i, int j)
{
    return i / j;
}

int main()
{
    int ans = getDiv(1, 0);
    cout << ans << endl;

    return 0;
}
/*
c스러운 코딩

int div(int i, int j)
{
    if (j == 0)
    {
        return -1;
    }
    else
        return i / j;

}
뭔가 약속된 코드값을 리턴해서 특정값은 에러라고 인식할 수 있도록 하는 것이 c스러운 방식이다. 이 문제상황을 인지하지 못하면 저게 정상적인 정답인 줄 안다.
코드를 보면 j가 0일때 코드만 보게 되면 에러 처리임을 알 수가 없다. 의미를 숙지하고 있으면 예외처리임을 알 수 있다. 아무튼 문법적으로 정상적인 플로우랑 비정상적인 플로우의 의미 분석이 필요

C++의 경우는 의미적으로 완전 분리

int div(int i, int j)
{
    if (j == 0)
    {
        throw myerror();
    }
    else
        return i / j;
}

throw를 하게 된다면 무조건 에러가 발생했음을 나타낸다. 프로그램이 죽으면 에러가 벌어졌어요!!!! 하고 죽게 된다. myerror가 throwing되고 죽었어요!! 라고  죽어버림. 문제 발생에 대한 책임이 없이 죽게 되버림. 책임을 져야되는데 어떻게 지냐면 try & catch를 이용

int main()
{
    int i, j;
    cin>> i >> j;
    try
    {
        int ans = div(i, j);
        cout << ans;
    }
    catch(myerror e)
    {
        cout << "myerror";
    }
}
이렇게 main 코드를 바꾸게 된다면 myerror라고 나오게 되고 정상종료가 되었다. 정상 종료 -> 여기서 정상 종료가 된 이유는 예외 상황에 대해서 문제가 발생했음을 인지하고 그 상황을 정해진 무언가의 적절한 처리를 하고 정상 상황으로 돌아갔기 때문이다. catch는 비정상적인 상황일때만 발생하는 코드이다. myerror는 누군가 throw를 한거를 catch해서 발생한 문법이다. thrwo는 문제상황 발새으 catch는 throw를 문제 상황 처리를 위한 플로우이다.
*/