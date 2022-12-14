#include <iostream>
using namespace std;

class Negative
{
};
class Sample
{
private:
    int m;
    int n;

public:
    Sample();
    Sample(int x);
    Sample(Sample &a);
    ~Sample();

    void setM(int x)
    {
        if (x < 0)
            throw Negative();
        m = x;
    }
    int getM()
    {
        return m;
    }
};

Sample::Sample()
{
    m = 0;
    cout << "Sample() is Called" << endl;
}
Sample::Sample(int x)
{
    m = x; // 4. 이렇게 초기화하는게 제일 클리어 하다. 그런데 쓸데없는 문법적 허용이 또 있다.
    /*
    Sample::Sample(int x) : m{x} {
        cout << endl;
    }
    이렇게 나열하는 것도 허용이 된다. 교수님 왈 굳이? 뭐하러 복잡한 문법을 쓰느냐,, 교수님은 이거를 권장하지 않는다.

    Sample::Sample(int m) {
        this->m = m;
        cout << endl;
    }
    만약에 파라미터가 m으로 m = m이 되는 경우. 스콥이 ㄷ르면 m = m이 되버리면 가까운 m이 무조건 m으로 되기 때문에 int m = int m이라고 되버려서 우리가 의도한 결과는 되지 않는다. 이 때 this를 사용하게 된다. 따라서 this->m을 붙히게 된다. 나를 가리키는 포인터ㅓㅓㅓㅓㅓㅓ 저게 쩜이라면 로컬일 대 점을 찍고
    로컬을 부를때는 점, 포인터 변수를 부를땐 화살표이다. this가 나 자신을 가리키는 셀프 포인터 라서 화살표를 사용해야 되낟. this는 포인터이기 때문에 반드시 화살표를 사용해야된다. 자바의 경우는 클래스 객체는 무조건 힙으로 원시적 타입은 무조건 스택으로 가게 된다. 왜냐면 스택으로 보낼 수 있는 권한이 업시 때문에 new를 안하고 보낼 수 있는 방법이 없기 때문에. 유독 자바에서는 힙 스페이스가 중요하다. 그렇기 때문에 힙의 용량이 다른 언어에 비해 굉장히 많이 필요하다. 스택은 . 힙은 화살표를 사용한다. 그래서 자바에서는 this.을 사용했는데 c++의 경우에서는

    ??? this는 자동으로 현재 사진의 객체를 가리키는 주소인가?
    this는 자기 자신의 객체를 가리키도록 자동으로 처리된다.

    */
    cout << "Sample(int x) is Called" << endl;
}
// copy constructor
Sample::Sample(Sample &a)
{
    // 지금 이거는 클래스 내부라서 프라이빗을 볼 수 있다. 그래서 프라이빗임에도 불구하고 a.m을 하는 것은 문제가 안된다.
    m = a.m + 1000;
}
// 소멸자
Sample::~Sample()
{
    cout << m << "~Sample() is Called" << endl;
}

/*

*/
int main()
{
    Sample x;
    Sample *w; // new를 이용해서 동적할당을 받는다. -> 동적할당을 받으면 로컬 베리어블로 힙에 들어가게 된다.
    w = new Sample();
    /*
    로컬 변수의 ㄱㅇ우는 스택에 쌓이고, 동적 할당의 경우는 힙에 할당이 된다. 힙에서 사라지는 경우는 명시적으로 delete를 해야 사라진다.

    */
    w = new Sample();
    {
        delete w; // 1. 우리가 만약에 w를 delete w; 라고 했다면 w는 생겼다가 바로 사라진 것이다.그래서 문법적으로 자바는 생성자가 없다 왜? 소멸자가 없으니까 c++의 경우는 delete가 없으니까 생성자가 있는것이다. 자바의 경우는 delete를 프로그래머가 못하고 가비지 컬랙터가 알아서 정하기 때문에 따로 명령어가 없다. 
        
        // c++은 힙에 있는 메모리ㄴ를 언제 반남할지를 delete를 통해서 프로그래머가 정할 수 있다. 자바의 경우 프로그래머가 할당 받은메모리를 언제 반납할지 정하지 않는다.
        /*
        메모리는 잡혀있는데 어디있는지 모르는 게 memory leak이다. 그래서 프로그래머가 딜리트를 까먹으면 그 메모리는 잡혀는 있는데 억세스는 안되는 메모리 릭이 발생하게 된다. 그래서 메모리는 사용하지는 않지만 프로그래머가 지우지 않는다면 메모리 릭이 발생하게 된다. 그 권한을 뺏고 그냥 내가(자바가)알아서 딜리트할께 -> 언제 딜리트해주는데? 애니메이션 중에서 코코랑 자바랑 연관이 있다. ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ 영혼은 언제 사라져? 자신을 기억하는 사람이 아무도 없을 때 영혼도 사라지게 된다. 자바가 바로 그 철학을 따르게 된다. 자바는 언제 딜리트돼? 자기를 기억해 주는 변수가 사라지면. 더이상 자기를 억세스 할 수 있는 방법이 사라지면 즉, 자기가 메모리 릭이 되는 순간 이런 상황에서는 딜리트해준다. 근데 씨쁠같은경우는 너는 그냥 그게 ㄷ니 운명이야 그리고 메모리를 차지하게 둔다. 근ㄷ 자바의 문제는 뭐야? 개비지 콜랙터도 바빠서 잊혀지자마자 바로 지우는게 아니야. 그때그때 스케쥴잡아서 날려. 언제 날라갈지는 몰라. ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ미친 ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ

        힙에 들어간 메모리는 delete 되는 순간에 사라진다. 따라서 애를 돌려보면 가장 먼저 찍히는 건desctructor가 생뚱맞게 있는데, 그 시점에 소멸자가 불렷기 때문이다. Sample *w는 보면 그냥 포인터 변수이기 때문에 샘플의 생성자와는 상관이 없다. 실제로 샘플이라고 하는 객체가 아니다.

        만약에 저 샘플이 멤버 변수가 3개가 있어. 샘플 하나에 12바이트를 잡아먹게 되어있다. 샘플이라는 객체당 12바이트를 잡아먹는다. 근데 포인터 변수의 경우는 얘는 어디까지나 4바이트면 된다.

        포인터읙 경우는 어디까지나 주소만 저장하기 위한 변수이ㅏ. 포인터 변수는 실제 샘플 객체가 아니라 오로지 주소를 저장하기 위한 단순한 변수일뿐이다. 그래서 포인터 변수는 컨스트럭터가 불리지는 않는다. 그래서 지금 나타난 코드는 Sample x에서 호출, new Sample에서 호출 그 다음 딜리트 호출, 그 다음 Sample y에서 생성자 호출이 된다. 결국 스택에 들어가는 것과 힙에 들어가는 게 사라지는게 다른데, 스택의 경우는 중괄호가 끝날때, 힙의 경우는 딜리트될때 사라진다. 그러힉 때문에스택은 기걔적으로 생겼다 지워졌다 한다.

        동적할당의 경우는언제 new가 될지, 언제 delete가 될지 이거는 프로그래머 맘이다. 프로그래머의 결정에 의해서 생겼다 사라지기 때문에 마구잡이로 메모리가 샇인다. 그러다가 중간에 갑자기 없ㅇ지고 쌇이고 큐처럼, 스택처럼 사라지는게 아니라 규칙이 없어 그래서 이름이 힙이다. heap이 더미라는 뜻이기 때문에 그냥 쌓여있다가 중간에 엇어지고 이런거를 의미하는 것이다. 그래ㅓㅅ C++의 경우는 class의 객체를 스택에 둘지 힙에 둘지를 선택할 수 있다.

        x는 스택에 w는 힙에 둔것이다. 오호! x는 그냥 지역 변수이기때문에 중괄호가 닫아지는 순간 사라지는 애다. w의 경우는 힙에 둔다. w는 원래는 포인터 변수잖아. 로컬한 포인터 변수이다. w는 중괄호가 닫힐 때 사라진다. 근데 w는 사라지는데, w를 가리키고 있었던 주소는 안사라진다. 포인터 변수 자체는 로컬이지ㅁ나 걔가 가리키고 있는 메모리는 힙에 있는 것이다. 그래서 만약에 딜리트w를 생략하고 끝났다. 그럼 이 상황이 메모리 릭이다. 힙에 메모리가 잡히고, w가 이를 기억하고 있는 상황이다. 그거를 기억해주는 애가 w인거다. 그래서 delete w를 안하게 되면 이승에서 영혼을 기억하는 친구는 사라지고, 메모리는 잡혀있고 이런상황이 메모리 릭이다. 메모리릭을 막으려면 이 사람이 다른 사람에 게 기억하도록 만들어주어야 된다. 누군가는 계속 기억을 하도록 전달을 해줘야 한다. 전달이 끝기면 메모리 릭, 안끝기면 메모리 릭이 아니다. 편의상 w는 안 사라진다고 얘기를 하지만 엄밀하게 얘기를 하면 w가 가리키는 주소는 사라있고 w의 스택 공간은 사라지는 것이 맞다. new를 한거를 ㅇeltet하는 것은 반드시 프로그래머가 해야되다.

        delete가 호출되는 순간 불리는 게 디스트럭터가가 존재한다. 자기가 해야할 뒤처리를 소멸자가 해준ㄷ. 뒤처리로서는 자신의 멤버 변수 중에서 포인터가 있을 ㅜㅅ 있다. 포인터가 어디 힙에 있는 메모리를 가리키고 있을 수 있다. 그러다가 내가 그냥 죽어버리면 메모리 릭이 발새하게 된다. 이걸 막기 위해서 내가 죽기 전에 너도 죽으렴 가리키고 있는 힙의 메모리를 딜리트 하고 죽어야 된다. 내가 유일하게 기억하고 있던 변수였는데 내가 사라지게 되면 메모리 릭이 발생하기 때문에 딜리트 하고 소멸자하낟. 파일도 오픈했음ㄴ 반드시 cloase해야된다. 작업의 편의를 위해서 열어놓고 사라지면 문제가 발생 소멸자에서 close를 하고 죽는다.
        이러한 뒷 마무리를 해놓아야 된다. ㄸ라서 소멸자가 하는 일은 이러한 자신이 딜리트해야되는 메모리를 딜리트, 클로스 이런 마지막 뒤처리들을 해주고 그 메모리가 안전하게 사라질 수 있도록 한다. 소멸작 의외로 매우 중욯다. 이 모든 처리에 대한 책임이 소멸자에 있기 때문이다.
        */
        Sample y;
        x.setM(2);
        y.setM(20);
        Sample y2(y); // 파라미터가 y를 전달 어? int가 안넘어갔늗 어떻ㄱ 컴파일 되는거야?
        /*
        이게 뭐냐 생성자 중에서 특별한 생성자인 카피 생성자이다. 자동으로 만들어준거,, 나 자신을 매개 변수로 받게 되면
        카피 생성자는 모든 멤버 변수를 자동으로 복사해준ㄷ. 그래서 y2에 대해서 파라미터를 y로 주고 y2의 값을 바로 출력해보면 y에 넣었단 ㄱ밧과 같은 값이 나오는 것이다. 모든 멤버 변수를 그대로 카피해서 복사해주었기 때문이다. 가끔 내가 원하는게 그대로 보가를 원하지 않을 수 있ㄷ 그럼 내가 얼마든지 스스로 카피 생성자를 만들 수 있다.
        */
        Sample y3;
        y3 = y;

        {
            Sample z(100);

            cout << "x.m: " << x.getM() << endl;
            cout << "y.m: " << y.getM() << endl;
            cout << "z.m: " << z.getM() << endl;
            cout << "y2.m: " << y2.getM() << endl; // 카피 생성자를 사용자가 만들게 되면 1020이 나오게 된다. 파라미터가 나 자신 = 그래서 스페셜
            cout << "y3.m: " << y3.getM() << endl; // 이렇게 하면 y랑 똑같ㅇㄴ 값이 찍힌다.
            /*
            2. 이퀄을 해주면 기본적으로 모든 유저 디파인 클래스에 대해서 이퀄에 대한 오퍼레이터 오버로딩에 대해서 자동으로 만든다. 하는일은 멤버 변수를 자동으로 복사. 카피 새성자는 최초에 정의될때 한번만 사용이 가능. 생성자는 무조건 메모리에 정의될 때 한번만 딱!!! 불린다.
            그 뒤로 클래스를 복사하기 위해선ㄴ assgin이 필요. 얘도 자동으로 만들어준다. 즉 이 말은 사용자가 스스로 정의할 수 이싿. 내가 asign에 대한 정의를 바꾸고 싶어. 그렇게 된다면 내가 재정의 할 수 있다. 이거를 오퍼레이더 오버로딩이라고 부른다. 오퍼레이더 오버로딩은 나중에 설명해줄 것.
            */
        }
    }
    /*
    1. z가 제일 먼저 사라지고 그다음 y 그다음 x가 사라진다.
    */
}