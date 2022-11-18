#include <iostream>

using namespace std;

class CDummy
{
public:
    static int n;
    // static int n = 0; 클래스 에 대해서 멤버 변수에 대해서 초기화를 하지 앟는다 왜 ? 각각의 객체 마다 다른 값을 가질 수 있는데 저렇게 초기화 해버리면 안되잖아.
    int m;
    CDummy() { n++; }
    ~CDummy() { n--; }
    static int getN() { return n; } // [last] 이게 무슨 의미가 있을까?
    int getM() { return m; }        // [last]
};
int CDummy::n = 0; // n은 0으로 start 초기화를 1회만 하는 게 일반적이다. 이게 static일 대 하는 말.
int main()
{
    // getM();
    CDummy::getN();
    // [last] 아직 cDummy에 대한 오브젝트가 단 하나도 정의되기 전 상태에다 아직 오브젝트가 없어 근데 getM과 getN을 호출할 수 있을까? getM은 호출할 수 ㅇ벗어 . 멤버 함수니까. 반드시 오브젝트에 대해서만 호출이 가능핟. 근데, getN은 static이므로 오브젝트에 속한게 아니다. ㅋㄹ래스에게 속한 것이다 따라서 오브젝트가 없어도 호출이 가능하다. static 멤버 함수의 첫번째 중요한 차이
    // [last] 두 번째 차이
    /*
    static int getN() { return n + m; } -> 이렇게 된다면 m이 문제가 된다. 이렇게 된다면 n에 대해서 궁금증이 없어 둘다 static이니까 근데 m은 오브젝트에 종속되어 있어 딸사ㅓ 저기서 m은 어느 오브젝트의 m인지를 알아야 써먹지 따라서 이 코드는 에러이다. 누구의 m인지를 특정할 방법이 없기 때문이다.

    그런데 똑같은 라인을 getM()으로 적으면 어차피 getM은 스태틱이 아니라서 this꺼의 m임을 알기 때문에 int getM() {return n + m;} 문제가 없다.
    */
    CDummy a;               // 스택에 잡힘
    CDummy b[5];            // 스택에 잡힘 대신 연속된 메모리 공간
    CDummy *c = new CDummy; // 힙.
    // 7개가 잡힘
    cout << a.n << endl;
    // static이므로 a.n = CDummy::n같은 값을 가진다. 오히려 CDummy::n가 static이라는 것을암묵적으로 알려서 혼돈을 줄일 수 잇다.
    delete c;
    cout << CDummy::n << endl;
    cout << sizeof(a) << endl; // 1? 이라고 나옴 왜? int m을 추가하고 돌리면 4가 나옴. 왜? 스태틱은 ㄱ가각의 변수에 속한 변수가 아니기 때문에 일반적으로 sizeof 에 포함시키지 않아. 근데 sizeof 할 때, 변수가 아무것도 없으면 static에 의해서 1로 나오게 되고 변수가 최소 1개라고 있다면 데이터 형 사이즈 만큼 나오게 된다.
    return 0;
}