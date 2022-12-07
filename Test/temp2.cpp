#include <string>
#include <vector>
#include <iostream>

using namespace std;

class P5 : public string
{
public:
    P5(const char *a);
    bool solve();
    int length();
};

P5::P5(const char *a) : string(a)
{
    ;
}

int P5::length()
{
    // 부모 멤버 함수를 사용하고 싶을 때.
    return string::length() * 3;
}

bool P5::solve()
{
    int len = string::length();
    cout << len << endl;
    if (len == 4 || len == 6)
    {
        for (int i = 0; i < len; i++)
        {
            if ((*this)[i] < '0' || (*this)[i] > '9')
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

int main()
{
    string s = "1234";
    P5 my(s.c_str());
    my.solve();
    cout << my.length() << ":" << my << ":" << my.solve() << endl;
}
