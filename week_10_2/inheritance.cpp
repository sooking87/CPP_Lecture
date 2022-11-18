#include <iostream>
using namespace std;

class CPolygon
{
protected:
    int width, height;

public:
    void set_values(int a, int b)
    {
        width = a;
        height = b;
    }
};
// public으로 받으면 그냥 부모 클래스의 private, public이거를 그대로 상속 받도록 하겠다. cRect은 width, height라는 멤버 변수를 그대로 가지고 있다. 상속을 ㅂ다았기 때문에 그리고 setValues라는 함수도 자기에게 명시를 안했지만 가지고 있는 것이다. 추가적으로 area라는 함수를 추가한 것이다. 그래서 widht * height라는내용으로 정의하였다.
class CRectangle : public CPolygon
{
public:
    int area()
    {
        return (width * height);
    }
};
// 왜 rect와 별도로 추가? 삼ㄱ각형과 직사가곃ㅇ의 넓이를 구하는 공식이 달라서. 만약에 width, height가 private라면 area()를 widht*height라고 적을수가 없다. priate면 access를 못하니까 protected면 가능하다. 자식 클래스는 access를 할 수 있으니까
class CTriangle : public CPolygon
{
public:
    int area()
    {
        return (width * height / 2);
    }
};

int main()
{
    CRectangle rect;
    CTriangle trgl;
    // set_values는 cPoly로부터 상속을 받아서 사용을 할 수 있다.
    // 공통 멤버 함수,변수는 한번만 사용. 부모가 정의해놓은 정의를 그대로 reuse를 한다. area()만 다를 것 같아서 각각 추가한 것이다. 이게 어떤 장점이 있냐, 다른 도형이 있을 수 있다. 그렇게 확장할 때 좋다는 것이다. 5각형, Poly에서 상속 받아, 정사각형 -> 직사각형에서 상속받아 즉, 동일한 일에서 따로 쓰지 않아도 된다는 장점이 있다.
    rect.set_values(4, 5);
    trgl.set_values(4, 5);
    cout << rect.area() << endl;
    cout << trgl.area() << endl;
    return 0;
}