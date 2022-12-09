#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MyString
{
private:
    char *pstr;
    void initPstr();

public:
    MyString();
    void setString(char *t);
    int length();
    friend ostream &operator<<(ostream &os, MyString fs);
};

class FiveString : public MyString
{
public:
    bool solve();
};

MyString::MyString()
{
    pstr = NULL;
    initPstr();
}
void MyString::initPstr()
{
    pstr = new char[10];
}
void MyString::setString(char *t)
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
int MyString::length()
{
    int i;
    for (i = 0;; i++)
    {
        if (pstr[i] == '\0')
        {
            break;
        }
    }
    return i;
}
bool FiveString::solve()
{
    for (int i = 0;; i++)
    {
        if (pstr[i])
    }
}
ostream &operator<<(ostream &os, MyString fs)
{
    os << fs.pstr;

    return os;
}

int main()
{
    FiveString my;
    my.setString("1234");
    cout << my.length() << ":" << my << ":" << my.solve() << endl;
    return 0;
}