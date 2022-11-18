#include <string>
#include <vector>

using namespace std;

class PhoneNumber
{
private:
    string number;

public:
    PhoneNumber(string num);
    string masking(int k) const; // k 만큼 마스크한다. -> 멤버 함수를 const로 설정해봄.
    friend ostream &operator<<(ostream &os, const PhoneNumber &p);
};
PhoneNumber::PhoneNumber(string num)
{
    this->number = num;
}
string PhoneNumber::masking(int k) const
{
    string masked = "";
    for (int i = 0; i < number.length(); i++)
    {
        if (i < k)
            masked += "*";
        else
            masked += number[i];
    }
    return masked;
}
ostream &operator<<(ostream &os, const PhoneNumber &p)
{
    string masked = p.masking(7);
    os << masked;
    return os;
}
int main()
{
    PhoneNumber pn("01022233333");
    cout << pn << masked;
}