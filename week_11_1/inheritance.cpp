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
    friend ostream &operator<<(ostream &a, const MyString &b);
};

class FiveString : public MyString
{
public:
    bool solve();
    FiveString();
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
FiveString::FiveString()
{
    cout << "FiveString::FiveString()" << endl;
}
MyString::MyString()
{
    cout << "MyString::MyString() " << endl;
    pstr = NULL;

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
    FiveString my; // 1. 뭐가 찍힐까? -> 생성자에 보면 각각에 대한 생성자 이름을 찍히게 했다.
    /*
    실제로 찍히게 되면 string 먼저 그 다음 fivestring이 찍힌다. 그 이유는 메인에 보면 fivestring my밖에 없는데 디폴트로 fivestirng을 부르게 되어있느데 얘가 만들어지기 전에 부모 클래스부터 만든다. 부모 클래스를 자동으로 만든다. 내가 명시적으로 선택하지 않았아ㅡ몰 부모 클래스의 디폴트 생성자가 자동으로 호출이 된다. 그래서 MyString()이 불리게 된다. 순서는 내가 만들어지기 전에 부모의 객체를 먼저 만든다.
    MyString::MyString()
    FiveString::FiveString()
    */
    // cout << my.length() << ":" << my << ":" << my.solve() << endl;
    my.~FiveString();
    // 부모 클래스를 만들었다가 소멸되는 과정이 항상 반복된다. 나랑 똑같이 만들어졌다가 내가 사라질때 같이 사라진다. 가장 위에 있는 조상부터 차곡차곡 만들어지고 없어질때도 차곡차곡 없어진다. 따라서 부모의 생성자는 모두 불리게 된다.
    return 0;
}