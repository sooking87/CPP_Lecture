#include <iostream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void getStr(string &str, int k)
{
    // string은 char의 array이므로 리턴하게되면 복사가 벌어지고 스트링이 짧으면 상관 없지만 그게 길다면 그냥 리턴으로 처리하면 value의 복사가 필요하므로 복사에 요구되는 시간이 길어진다.. 그래서 call by ref로 처리하ㅡㄴ게 조금 더 빠르다.
    str = "";
    // 숫자를 string으로 만들고 두개를 뒤집어서 같은지를 비교
    for (int i = k; i > 0; i /= 10)
    {
        char temp = (k % 10) + '0';
        str = temp + str;
    }
}
void getRevStr(string &revstr, int k)
{
    revstr = "";
    // 숫자를 string으로 만들고 두개를 뒤집어서 같은지를 비교
    for (int i = k; i > 0; i /= 10)
    {
        char temp = (k % 10) + '0';
        revstr += temp;
    }
}
bool isPali(int k)
{
    string str, revstr;

    getStr(str, k);       // k를 str로 ㅂ꿀거임
    getRevStr(revstr, k); // k를 뒤집어서 revstr로 만들꺼임

    cout << str << endl;
    cout << revstr << endl;

    if (str == revstr)
        return true;
    else
        return false;
}
int solution(int n, int m)
{
    int answer = 0;

    for (int i = n; i <= m; i++)
    {
        if (isPali(i))
            answer++;
    }
    return answer;
}
int main()
{
    solution(1, 100);
}