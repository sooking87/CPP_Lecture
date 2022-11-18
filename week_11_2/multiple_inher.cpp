
/* 다음 페이지 Multiple Inheritance */
/*
스타킹...다중 상속 여러개 물러받으면 좋지 않을까? 두개의 기능이 다 탐나. 클래스들을 다 상속받아. 그러면은 강력한 클래스를 만들 수 있지 않을까?
*/
#include <iostream>
#include <string>
using namespace std;

// class 에 집중해서 보자

class Polygon
{
protected:
    int m, n;

public:
    Polygon(int m, int n);
    // virtual void draw() = 0; // 1. draw 함수는 구현을 안할거라는 말을 해주는 것이다.  구현하지 앟을 거를 왜 적어죠? 나중에 설명해줄것 여기서 draw라는 것은 선언을 굳이 부모 클래스에 넣어둔 의미가 뭘까 draw라는 것은 Polygon에서는 정의를 하지 않는 다고 했다. 그냥 선언만 넣지 정의는 없을거라는 것을 미리 선언. 근데 이걸 왜 굳이 만들어? draw를 넣는 장점은 두가지 큰 장점이 있는데 첫 번재 장점은 -> 사례 (1)
    // void draw(); // 1 연장 222 이렇게 구현할 수도 있다. 하지만 아까와의 차이는 명시적으로 자식 클래스에게 구현에 대한 의무를 줌.
    virtual void draw(); // 2번째 장점: 자식의 객체를 만들어진다ㅁ는 것은 부모 객체 위에 덧붙혀져서 만들어진다. 자식을 바라볼때 부모라고 생각하고 봐라봐도 아ㅜ 문제 없다. 이걸 이용해서
    virtual ~Polygon();
};
void Polygon::draw()
{
    cout << "default" << endl;
}
class Rect : public Polygon
{
public:
    Rect(int m, int n);
    void draw(); // 오버 라이드
    ~Rect();
};
class Triangle : public Polygon
{
public:
    Triangle(int m, int n);
    void draw(); // 오버 라이드
    ~Triangle();
};
Polygon::Polygon(int m, int n)
{
    this->m = m;
    this->n = n;
}
Polygon::~Polygon()
{
    cout << "Polygon::~Polygon()" << endl;
}
Rect::Rect(int m, int n) : Polygon(m, n)
{
}
Rect::~Rect()
{
    cout << "Rect::~Rect()" << endl;
}
void Rect::draw()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
Triangle::Triangle(int m, int n) : Polygon(m, n)
{
}
Triangle::~Triangle()
{
    cout << "Triangle::~Triangle()" << endl;
}
void Triangle::draw()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
class MyMulti : public string, public Rect
{
public:
    MyMulti(int m, int n, const char *str);
};
MyMulti::MyMulti(int m, int n, const char *str) : Rect(m, n), string(str)
{
}
int main(void)
{
    int a;
    int b;
    int type;
    cin >> type >> a >> b;

    // 장점 2를 ㅂ알아보기 위한 콛, 작성
    Polygon *pol;
    if (type == 3)
    {
        pol = new Triangle(a, b);
    }
    else if (type == 4)
    {
        pol = new Rect(a, b);
    }
    pol->draw();
    delete pol;

    MyMulti test(5, 3, "abc");
    cout << test << endl; // -> abc 출력: 두개를 다 상속받았으니까 test만으로도 string을 상속받았기 때문에 이렇게 해서 abc가 출력됨
    // 다중 상속의 단점: 내가 상속을 받으려고 하는 변수의 이름이 똑같애. confusing이 발생. 모호성 발생. 어느쪽의 것을 물려받을지에 대한 모호성이 발생. 이러한 모호성에 대한 문제점을 내포하고 있다. 그래서 사용할 때 조심해야 된다. 열어는 주었어........ 근데 책임은 너가 져. 동일한 이름을 가지는 멤버 함수나 변수에 대해서 묹를 발생할 수 이싿. 그렇게 발생하지 않도록 주의해야된다. 자바는 인터페이스의 존재가 있다. 선언만 있고 정의가 없어. 멤버 변수도 없어. 이거는 적자마자 정의이기 때문에. 따라서 인터페이스는 멤버 함수에 대한 선언만 존재하게 된다. 인터페이스는 멀티플로 인터페이스를 상속받아도 의무적인 구현에 효과. 인터페이스는 멀티프롤 상속받아도 문제가 되지 않아 (인터페이스는 정의 자체가 없기 때문에 모호성 자체가 없음.)

    // 상속의 장점 1. 부모 클래스의 이름으로 자식 클래스를 다 데리고 다ㅣㄹ 수 있다. 상속 관계로 클래스르 설계하면 하나의 타입으로 모든 객체를 가리킬 수 있는 장점이 있다. 이게 상속 설계의 장점이다. C++은 상속 설계를 컴파일러는 전혀 관여하지 않는다. 상속 설계는 오로지 프로그래머의 몫이다. 상속 설계는 오로지 프로그래머의 역량이다. 몇 수를 내다보는 설계를 해야된다. 자바는 상속 설계에 관여를 하는 것. 메인도 클래스에 집어넣었는데, 메인을 부를려면 객체가 있어야되는데 객체를 만들려면 메인이 ㅇㅆ어야 되지 않을까 이 딜레마를 해결하기 위해서 static으로 집어넣는다. 객체가 없어도 호출할 ㅜ 있다. 자바의 모든 클래스는 태초의 부모 클래스가 있다.오브젝트 클래스강 ㅣㅆ는데 얘는 모든 클래스의 디폴트 베이스 클래스이다. 왜? object라는 이름으로 끌고 다닐려고.
    test.draw();
}
// 3. 이렇게 만 한다면 답정도는 나온다.
