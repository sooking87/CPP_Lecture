#include <iostream>

using namespace std;

class Negative
{
};
class Sample
{
private:
    int n;
    int m;

public:
    Sample();
    Sample(int x, int y);
    ~Sample();
    void setN(int x);
    int getN() const;
    void setM(int y);
    int getM() const;
    Sample operator+(const Sample &a); // 1. 두개의 파라미터를 필요로할 것 같은데 실제로는 하나의 파라미터가 있다 . 왜 ? 디폴트로 나 자신이 기본이고 추가로 나와 더해질 하나만 더 필요 그래서 파라미터를 하나만 요구한다.
    /*
    2. 그 다음 리턴되는 리턴값은? 더하기는 연속적인 덧셈을 지언해준다. 1+ 2+ 3+ 4+ 5 이런거를 지원 1 + 1의 리턴은 int라는 것이ㅏ. 따라ㅓㅅ sampel + Sample은 Sample이기를 바란다. 그래서 리턴 벨류를 Sample로 해서 연속적인 덧셈을 하도록 할 수 있도록 한다.
    */
    friend Sample operator-(const Sample &a, const Sample &b); // 4. friend 는 프라이빗한 멤버는 클래스 내부에서만 가능. 근데 프랜드는 스페셜한 클래스가 되어서 우리가 남이가 친구끼리는 서로 프라이빗을 오픈해준다.
    // 5. 왜 파라미터가 2ㅐ? 앞에 프랜드가 붙었는데 ㅇ뒤에 정의할 펑션은 멤버 함수가 아니라 외부에 있는 함수라는 것이다. +에ㅐ서는 디폴트인 this가 있었느넫, 얘는 메멤버가 아니닊 디폴트가 ㅇㅂ서어 그래서 반드시 파라미터를 2개를 요구하게 된다. 그래서 friend이기 때문에 파라미터가 2개로 늘어남.
};
Sample::Sample()
{
    n = 0;
    cout << "Sample() is Called" << endl;
}
Sample::Sample(int n, int m)
{
    this->n = n;
    this->m = m;
    cout << "Sample() is Called" << endl;
}
void Sample::setN(int x)
{
    n = x;
}
int Sample::getN() const
{
    return n;
}
void Sample::setM(int y)
{
    m = y;
}
int Sample::getM() const
{
    return m;
}
Sample::~Sample()
{
    cout << n << " ~Sample() is Called" << endl;
}
Sample Sample::operator+(const Sample &a)
{
    Sample x;
    x.m = this->m + a.m;
    x.n = this->n + a.n;
    return x;
}
// 6. 얘는 프랜드가 아니기 때문에 콜론콜르ㅗㄴ을 안넣어
// 파라미터에 const 가 없으면 에러가 나는데 왜 그렇냐면 const로 받지 않으면 받을 수 없어 에러 매세지가 call by value로 받던지 const를 넣어주던지 이 에러가 났었다. ㅍ ㅣ연산자의 값이 변경되는 것을 허용하지 않ㄱㅆ다. 둘중에 하나를 선택햇=라 value로 넘기던지 cost로 붙혀서 ref로 받던지 여튼 일받ㄴ적으로 선호되는 것은 const를 붙혀서 받는 것이다. 복사할 필요ㄱ없으니까 성능이 좋아짐.
Sample operator-(const Sample &a, const Sample &b)
{
    Sample x;
    x.m = a.m - b.m;
    x.n = a.n - b.n;
    return x;
    // 공통점을 프라이빗은 멤버 변수들은 접근할 있다.
}
int main()
{
    Sample x;
    x.setN(5);
    x.setM(2);
    Sample y(10, 20);
    Sample y2(y);
    Sample y3;
    // y3 = x + y2 + y; // 3. 연속해서 덧셈이 되는 이유. sample로 리턴했기 대문에
    y3 = y2 + y - x; // 7. 멤버 함수는 default 로 this가 있어서 파라미터 하나, 프랜드는 defualt가 없어서 파라ㅣㅁ터를 2개를 받아야 된다. 이렇게 오퍼래이터 오버로딩을 받음으로써 코딩에 있어서 우리가 일반적으로 알 고 있던 프로그래밍의 표현법을 일반적으로 사용할 수 있다. 구현이 안되는 것은 아니지만 +, -로 사용하는 것이 직관적이다. 이게 일종의 다형성 지원 방식이다. 우리가 프로그래머들에게 보카 ㅇ암기를 시키지 말자. 어차피 함수들은 비슷한 기능을 하는 것들이 많이 있다. 이런것들은 동일한 이름을 가진 함수에 대해ㅓㅅ 오버 로딩을 통해서 사용할 수 있도록 해라 = 다형성 철학 -> 지원 방법: 오버로딩

    cout << "x.getM(): " << x.getM() << endl;
    cout << "y.getM(): " << y.getM() << endl;
    cout << "y2.getM(): " << y2.getM() << endl;
    cout << "y3.getM(): " << y3.getM() << endl;
}
