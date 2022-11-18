#include <iostream>

using namespace std;

// class 에 집중해서 보자
class Polygon
{
    // 1. 얜ㄴ 그냥 기본적인 기능을 만들도록 하겠다. 상속을 염두해둔 클래스이므로 상속을 위해서 protected로 설정
protected:
    int m, n;

public:
    Polygon(int m, int n);
    void draw(); // *로 사각형 그리는 함수
};
Polygon::Polygon(int m, int n)
{
    this->m = m;
    this->n = n;
}
// 2. 만약에 draw로 바로 정의
void Polygon::draw()
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

int main(void)
{
    int a;
    int b;
    cin >> a >> b;

    Polygon pol(a, b);
    pol.draw();
    return 0;
}
// 3. 이렇게 만 한다면 답정도는 나온다. 이거를 찍는 것 자체는 하나도 어렵지 않아. 근데 이거는 일단 클래스화를 해서 m과 n의 값을 저장하고 이거를 멤버 변수를 초기화 시키고 멤버 함수를 이ㅛㅇ해서 그리도록 만들었다.
//이렇게 하면 장점이 뭐냐 이렇게 하면 똑같은 일을 main에 너허도 결과는 똑같긴 한데 장점이 뭐야. 이 문제 하나를 풀기 위해서는 오히려 main에 이중 포문을 넣는게 유리하다. 근데 이 방법이 가진 단점은 확장성이 없다. 내가 여기서 뭘 확장하고 싶냑면 지금은 사각형으로만 그리고 있는데 이 그림을 다른 방식으로 그림을 그리고 ㅅ피어. 삼각형을 그리고 싶어. 아니면 사각형을 가로 세로를 뒤집어서 그리고 싶어. 원을 그리ㅗㄱ 싶어. 그럴 때에는 draw() 함수에 대한 정의가 다 달라져야된다. 그 방법을 체계화 시켜서 클래스를 설계하면 확장성이 더 좋아진다. 그래서 그걸 위해서 polygon에서 draw를 -> prof2로 넘어가자