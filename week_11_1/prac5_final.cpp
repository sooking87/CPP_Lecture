

#include <iostream>
#include <string>

using namespace std;

class FiveString : public string
{
public:
    bool solve();
    FiveString(const char *a);
    int length();
};
FiveString::FiveString(const char *a) : string(a)
{
    ;
}
int FiveString::length()
{
    return string::length() * 2;
}
bool FiveString::solve()
{
    int len = string::length(); // 3. 원래 string 클래스에 legnth가 있어
    if (len == 4 || len == 6)
    {

        for (int i = 0; i < 10 && (*this)[i] != '\0'; i++)
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
    FiveString my("123456");
    cout << my.length() << ":" << my << ":" << my.solve() << endl;
    return 0;
}
bool solution(string s)
{
    FiveString my(s.c_str()); // const char만 받는데, 들어가는 것은 string 이므로 c_str을 사용해서 strinㅎ의 값을 const의 char의 포인터로 받아서 리턴해준다.
    return my.solve();
}