#include <iostream>
using namespace std;

class CRectangle
{
    int width, height;

public:
    void set_values(int, int);
    int area(void)
    {
        return width * height;
    }
};

void CRectangle::set_values(int a, int b)
{
    width = a;
    height = b;
}
int main()
{
    CRectangle a, *b, *c;              // 실제로 첫 번째 줄이 실행되었을 때, 1개의 인스턴스만 메모리에 잡힘. -> 로컬 변수로 되어있느 ㄴa만 메모리에 오브젝트로 ㅏㅂ혀있음. b, c는 포인터 변수가 정의된 것 뿐이다. 단순이 4 바이트짜리 포인터 변수일 뿐이다.
    CRectangle *d = new CRectangle[2]; // 인스턴스가 몇개가 만들어졌을가 -> 3개 아닐까? 정답은 3개 -> 왜냐면 이미 a는 잡혀있고, b와 c는 아직까지 포인터 d가 포인터 인데, 여기에 2개 new를 해주어서 2개의 오브젝트가 추가로 더 잡힘.
    // 좀더 디테일하게 보면 하나느 스택에 있고 두개는 힙에 있다.
    b = new CRectangle; // b까지 힙으로 메모리가 총 4개가 잡힘. 3개 중에서 array로 잡은 메모리 공간은 연속된 메모리 공간 b는 연속된 메모리 공간은 아님.
    c = &a;             // 여전히 4개일듯. -> 메모리 공간 4개 차지. 스택에 있는 거 여전히 1개(a), 힙에 3개(new array, b = new), c는 그냥 스택의 주소를 가리키는 포인터일 뿐이다.
    // c에서 setvalue를 하려면 스택, 힙 여부를떠나서 포인터 변수이므로 얘는 화살표를 쓰ㅡㄴ 것이 맞다.
    a.set_values(1, 2);
    b->set_values(3, 4);
    d->set_values(5, 6);   // = d[0].set_Values(같은 메모리를 뜻함. )
    d[1].set_values(7, 8); // d[1] 이면 점,,,왜? 첨자를써서 array의 방식으로 접근하면 .을 사용한다. 이게 Crect array이기 때문에.

    cout << "a area: " << a.area() << endl;
    cout << "*b area: " << b->area() << endl;
    cout << "*c area: " << c->area() << endl;
    cout << "d[0] area: " << d[0].area() << endl; // d[0]. = d->
    cout << "d[1] area: " << d[1].area() << endl;
    delete[] d; //[]안하면 첫 번째 요소만 날려. 메모리 릭이 발생할 가능성이 높아짐.
    delete b;
    // c가 없는 이유는 c는 어차피 스택을 가리키고 있었으므로 스택은 delete 해줄 이유가 없어 delete는 힙에 있는 메모리를 없앨때 사용된다.
    return 0;
}