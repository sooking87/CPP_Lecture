#include <iostream>

using namespace std;

class Negative
{
};
class Sample
{
private:
    int m;

public:
    int n;
    Sample()
    {
        m = 0;
        cout << "Sample() Called" << endl;
    }
    Sample(int x)
    {
        m = x;
        cout << "Sample() Called" << endl;
    }
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

int main()
{
    Sample x, y, z(100);
    x.n = 1;
    y.n = 10;

    // default가 private임. 따라서 메인에서 m은 접근할 수 없어 라는 에러가 발생하낟. 그거는 클래스 내부에서만 볼 수 있음.
    // x.m = 2;
    // y.m = 20;
    // 따라서 m은 건드릴 수 없어.

    cout << "x.n: " << x.n << endl;
    cout << "y.n: " << y.n << endl;
    // 이거를 보고 싶은거는 저 n은 각각의 변ㅅ ㅇㄴ스턴스 맏 따로 잡히는 메모링 ㅣ다. x의 n과 y의 n은 다른 n이다. 이거를 보고 은 것이다.
    /*
    private은 어디에 써?
    setM이라는 함수는 public에 두었으므로 밖에서 접근 가능 SETM이라는 것은 m의 값을 초기화한다. m은 밖에 프라이빗 m을 가리키는 것이다. 이렇ㄱ 하면 뭐가 가능해지냐면 x.m은 에러가 떴었지만 x.setM(2)이런식으로 m값을 설정할 수 이싿.
    */
    x.setM(2);
    y.setM(20);
    cout << "x.m: " << x.getM() << endl;
    cout << "y.m: " << y.getM() << endl;
    cout << "z.m: " << z.getM() << endl;
    /*
    nㅇㄴ 모두 오픈, 대신 퍼블릭의 함수를 사용해서 접근이 가능하도록 하였다. 결과론 적인 동작은 똑같다.단지 public인 n은 외부에서 직접호출이 가능한데, 그렇지 않으면 우회적으로 접근이가능하다. 두가지가 다 가능은 하지만 권장되는 것은 멤버 함수를 사용해서 간접적으로 변수의 값을 초기화 해라. 멤버 함ㅅ를 만든다면 한번더 감시하는 역할을 하게 된다. 엉뚱한것으로 바꾸면 안되니까.

    함수를 이용해서 값을 만들게 된다면 함수에서 값에 대한 조건을 넣고, 거기에 맞는 값으로만 바꿀 수 있도록 만들 수 있다.
    void setM(int x)
    {
        if (x < 0)
            throw Negative();
        m = x;
    }
    예시

    따라서 권장이 되는 방식은 우회적으ㅗ 값을 설정하는 것이다. 변수는 다 private으로 외부에서 사용할 일이 있다면 별도의 멤버 함수를 만들고 access해라. 데이터의 안정성을 위해서 . 물론 귀찮겠지만. 해야됨. 내가 만든 클래스를 나 혼자 쓰는게 아님.

    멤버 함수들에는 스페셜, 이름이 정해져있는 애들이 있다.
    그중에 대표적인게 constructor이다 이거는 항상 클래스의 이름과 동일하다.
    class Sample
    {
    private:
        int m;

    public:
        Sample() {
            m = 0;
            n = 0;
        }
        int n;
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
    t생성자가 특별한 이유는 해당 오브젝트가 만들어질때 그게 디폴트로 불림. 그 함수를 호출하는 걸 프로그램이 명시적으로 호출하는게 아니라 그 오브젝트를 최초의 정의가 될 때 그때 자동으로 호출이 된다. 예를 들어서 샘플이라는 함수가 있으면 그 함수를 호출한 거는 아님. 근데 sample이라는 함수를 명시적으로 호출을 하지는 않음 근데 그걸 컴파일해서 실행해보면 sample의 생성자가 호출이 된다면 자동으로 생성자 함수를 호출한다. 즉, 인스턴스가 생성이 될 떼, 자동으로 호출되는 스페셜한 멤버 함수이다. 그래서 기본적으로 생성자는 public임.

    내가 제일 처음에 저 클래스만들대, 내가 저 m값을 입력한 값으로ㅗ 자동으로 생성하고 싶다.
    */
}