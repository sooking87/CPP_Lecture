#include <iostream>
#include <string>

using namespace std;

class MyString
{
private:
    void initPstr();

protected:
    char *pstr;

public:
    MyString();
    ~MyString();
    int length();
    void setString(const char *t);
    friend ostream &operator<<(ostream &a, const MyString &b); // 2. 오퍼레이터 오버로딩을 하고 싶어 내가 mystring이라는 내가 만든 클래스에서도 <<를 통해서 내보내고 싶다. 오퍼레이터 오버로딩을 안해놓으면 cout의 <<로 갈 수가 없다. 따라서 내가 직접 <<에 대한 함수를 만들어야 된다. 나 자신을 일단 this로 해석할 수 있으니까 this는 생략하고, cout만 줌 근데 일반적으로 리턴이 cout으로 되는게 일반적인 형식이다.
};

// 3. 문제를 풀기 위한 클래스를 만들고 싶다.
// MyString을 상속받았으니까 걔가 가지고 있는 legnth를 얼마든지 사용할 수 있다. 그게 public이니까

class FiveString : public MyString
{
public:
    bool solve();
};
bool FiveString::solve()
{
    int len = length();
    if (len == 4 || len == 6)
    {
        // 이 부분에서 pstr[i]를 통해서 숫자인지 아닌지를 판단하고 싶으므로 내가 접근할 수 있으려면 protected 권한을 가지고 있어야 된다.4
        for (int i = 0; i < 10 && pstr[i] != '\0'; i++)
        {
            if (pstr[i] < '0' || pstr[i] > '9')
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
    return true;
}

MyString::MyString()
{
    pstr = NULL;
    // 최초의 pstr에 대한 초기화를 해주고 싶다.
    initPstr();
}
MyString::~MyString()
{
    if (pstr != NULL)
        delete[] pstr;
}
void MyString::initPstr()
{
    pstr = new char[10]; // 길이가 8이하인 문자열이므로 안전하게 10 정도로 char를 가져옴
}
int MyString::length()
{
    int i;
    for (i = 0; i < 10; i++)
    {
        if (pstr[i] == '\0')
            break;
    }
    return i;
}
// t를 입력받은 것을 pstr로 복사
void MyString::setString(const char *t)
{
    for (int i = 0; i < 10; i++)
    {
        pstr[i] = t[i];
        if (t[i] == '\0')
        {
            break;
        }
    }
}
ostream &operator<<(ostream &a, const MyString &b)
{
    a << b.pstr;
    return a;
}

int main()
{
    FiveString my;
    my.setString("1234");
    // cout << my.length() << ":" << my.getPstr() << endl;
    cout << my.length() << ":" << my << ":" << my.solve() << endl; // 0: false
    /*
    1. (z코드 다 치고)아주 대충 mystring이라고 하는 클래스를 구현해보았다. 정말 대충 구현해 놓은 건데, 원래 string 클래스처럼 구현해야되면 신경써야되는게 많은데, 일단은 그거는 빼고 가장 간단하게 구현해놓음.
    my =-> setString -> my에 복사 -> cout -> 길이 구할 수 있고,
    우리가 원하는거는 cout << my.length() << ":" << my << endl; 이렇게 출력이 되었으면 좋겠다. 복잡한 함수를 호출하는게 아니라 myㄹ를 직접 cout에 넣어서 오퍼레이터 오버로딩을 건드릴려고 하는 것이다.
    */
    return 0;
}