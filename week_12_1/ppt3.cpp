#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

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
};
class ThreePoint : public Point
{
private:
    float z;

public:
    ThreePoint();
    ThreePoint(float x, float y, float z);
    float length(); // override
    float operator*(ThreePoint &b);
    friend ostream &operator<<(ostream &os, const ThreePoint &p);
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
/*ThreePoint*/
ThreePoint::ThreePoint()
{
    z = 0;
}
ThreePoint::ThreePoint(float x, float y, float z) : Point(x, y)
{
    this->z = z;
}
float ThreePoint::length()
{
    return sqrt(Point::length() * Point::length() + z * z); // Point::length() * Point::length()제곱을 이용해서 루트를 없앰. - 부모 클래스의 함수를 호출 할 수 있다. 이거는 재귀적 호출이 아니다 . Point냐 ThreePoint냐 이 차이이다. 
}
float ThreePoint::operator*(ThreePoint &b)
{
    return x * b.x + y * b.y + z * b.z;
}
ostream &operator<<(ostream &os, const ThreePoint &p)
{
    os << "(" << p.x << ", " << p.y << ", " << p.z << ")";

    return os;
}
int main()
{
    Point p1(3, 4);
    Point p2(4, 5);
    cout << p2.length() << endl;
    cout << p1 << endl;

    ThreePoint ta(2, 5, 1);
    ThreePoint tb(3, -4, 5);
    cout << tb << endl;
    cout << ta.length() << endl;
    cout << ta << endl;
}

