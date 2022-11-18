#include <iostream>
#include <string>

using namespace std;

class Number
{
private:
    string n;
    int k;
    void myItos(int n); // itos

public:
    Number(int n);
    void changeToK(int k); // k진법으로 바꾸는 함수
    int getDec();          // 문자로 있는 것을 10진법 숫자로 바꾸어서 리턴
    string getN();         // 멤버 변수 n(string)을 리턴
    void setN(string n);   // 멤버 변수 n(string)을 설정
};

class Converter
{
public:
    static string reverse(string str); // static으로 둠. 그 이유는 나중에 설명 예정.
};
string Converter::reverse(string str)
{
    string ret = "";
    cout << "reverse: " << str << endl;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        ret += str[i];
        cout << "reverse: " << ret << endl;
    }
    return ret;
}

// constructor
Number::Number(int n)
{
    myItos(n);
    this->k = 10; // 처음 입력받은 수는 10진수
}
// 10진수 n이 들어왔을 때, int에서 string으로 바꾸어줌
void Number::myItos(int n)
{
    this->n = "";
    for (int m = n; m > 0; m /= 10)
    {
        this->n = (char)('0' + (m % 10)) + this->n;
    }
    cout << "my_itos: " << this->n << endl;
}
void Number::setN(string n)
{
    this->n = n;
}
// string n(k진수) -> int(10진수)로 바꾸어주는 함수
int Number::getDec()
{
    int i = 1;
    int num = 0;
    for (int m = n.length() - 1; m >= 0; m--)
    {
        num += (n[m] - '0') * i;
        i *= k;
    }
    return num;
}
// string n -> getDec을 통해서 int dec(n의 값을 dec에 저장)로 변환 -> int에서 k진수로 변환된 값을 string n에 저장
void Number::changeToK(int k)
{
    int dec = getDec();
    this->k = k;
    int i = 1;
    this->n = "";
    for (int m = dec; m > 0; m /= k)
    {
        this->n = (char)('0' + (m % k)) + this->n;
    }
}
// string인 n을 리턴해주는 함수
string Number::getN()
{
    return n;
}
int solution(int n)
{
    int answer = 0;

    // 최종 풀이
    Number mynum(n);
    mynum.changeToK(3);
    mynum.setN(Converter::reverse(mynum.getN()));
    cout << mynum.getN() << endl;
    answer = mynum.getDec();
    cout << mynum.getN() << endl;
    cout << mynum.getDec() << endl;
    return answer;
}
int main()
{
    // Number mynum(24);
    // cout << mynum.getN() << endl;
    // cout << Converter::reverse(mynum.getN()) << endl; // 특정ㅎ나 목적을 하고 싶은데, 클래스 안에 static 함수로 쭉 나열 class로 묶옂=는 잇는게 굳이 object를 만들 필요없이 각각의 함수를 사용할 수 있다.
    // Number mynum(100);
    // mynum.changeNum(2);
    // cout << mynum.getN() << endl;

    // 최종 풀이
    Number mynum(45);
    mynum.changeToK(3);
    mynum.setN(Converter::reverse(mynum.getN()));
    cout << mynum.getN() << endl;
    mynum.getDec();
    cout << mynum.getN() << endl;
    cout << mynum.getDec() << endl;
}