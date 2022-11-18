#include <iostream>
#include <cmath>
using namespace std;

/*
데이터형만 다르지, 본연의 ㄷㅇ작에서는 별 차이가 없다. 복붙해서 코딩할 수 있다. 아니면 상속을 받아서 float에 대해서 동작하도록 오벌아ㅣ드 그런데 완벽하게 원하는 동작이 동일하고 타입만 다른 경우가 필요하다. 이러ㄴ한 자료구조 형을 효율적으로 지ㅝㄴ하기 위해서 템플릿 이라는 개념을 지원하였다.
똑같은 타입 두개를 페이러르 가진 2차원 구조를 만들고 싶을 때, 그 타입을 일종의 대며사로 비워둔다. 그게 어떤 형인지를 명시하지 않아. 아무거나 하나 기호를 정해서 대명사 처럼 사용이 된다. T타입이야 라고 불리게 된다.
T에 대해서 미리 사전 정보 공개 T는 템플릿으로 쓰일꺼야 그거는 어떤 클래스라고 생각을 해주면 될 것 같아. T의 정체에 대해서 미리 컴파일러에게 알려주고, (template <class T>) 클래스는 T라는 대명사를 끌고 다녀야돼 (mypair<T>)
*/

class Point
{
protected:
    float x, y;

public:
    Point();
    Point(float x, float y);
    float length(); // 원점과의 거리
    float operator*(Point &b);
    friend ostream &operator<<(ostream &os, const Point &com);
    bool operator>(Point &b);
};
/*Point*/
Point::Point()
{
    this->x = 0;
    this->y = 0;
}
Point::Point(float x, float y)
{
    this->x = x;
    this->y = y;
}
float Point::length()
{
    return sqrt(x * x + y * y);
}
float Point::operator*(Point &b)
{
    float ans;
    float num1 = this->x * b.x;
    float num2 = this->y * b.y;

    ans = num1 + num2;
    return ans;
}
ostream &operator<<(ostream &os, const Point &p)
{
    os << "(" << p.x << ", " << p.y << ")";

    return os;
}
bool Point::operator>(Point &b)
{
    if (this->x > b.x && this->y > b.y)
        return true;
    return false;
}
template <class T> // 대명ㅅ T에 어떤 타입도 원칙적으로 올 수 잇따. user defined 클래스 타입도 얼마든지 올 수 있다. 우너칙 적으로 ! 실제론ㄴ 원칙적으로 옳바를 수 있다는 것은 아님 내가 대명사로 해놓은 부분을 실제로 쓸 대, T라는 타입에 대해서 +를 하고 싶다면 T라는 자리엔ㄴ 원칙적으로는 어떤 타입이든 올 수 있지만 옳바른 동작을 하기 위해서는 함수의 구현에서 지원하는 애들만 타입을 적어야된다. 이거는 보통 메뉴얼에 대한다.ㅏ 벡터는 요구하는게 없다. 얘는 할당밖에 안해서 이거는 default로 컴파일러가 만들어줌. 그래서 ㅁ든 타입에서 벡터를 사용할 수 잇다. 그러나 보통은 항상 반드시 사용할 수 있는 것은 아니다.
class mypair
{
    T a, b;

public:
    mypair(T first, T second)
    {
        a = first;
        b = second;
    }
    T getmax();
};

template <class T>
T mypair<T>::getmax()
{
    T retval;
    retval = a > b ? a : b;
    return retval;
}

int main()
{
    mypair<int> myobject(200, 75);
    mypair<float> myobject2(75.2, 100.04); //저장되는 타입이 다르다.  = 포인트 클래스ㅔ 대해서는 안딘ㄷ?
    cout << myobject.getmax() << endl;
    cout << myobject2.getmax() << endl;
    mypair<Point> myobject3(Point(1, 2), Point(2, 3)); // 생성자 형성은 문제가 없어. 근데 이 코드를 따라가며 getmax라는 함수에 대해서 ㅁa > b가 정의되어 있지 않는다.  Poinㅅ에 대해서 대ㅗ소 비교 불가 지금은 이 마이 페어에 대해서 사용할 수 없지만 오퍼레이터 오버로딩을 하면 사용할 수 있다.
    cout << myobject3.getmax() << endl;
    return 0;
}