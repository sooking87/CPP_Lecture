#include <string>
#include <vector>
#include <iostream>

using namespace std;

int getThree(int n)
{
    int ans = 0;
    int k = 1;
    for (int i = n; i > 0; i /= 3, k *= 10)
    {
        int temp = i % 3;
        ans += temp * k;
    }
    return ans;
}
int getTen(int n)
{
    int ans = 0;
    int k = 1;
    for (int i = n; i > 0; i /= 10, k *= 3)
    {
        ans += (i % 10) * k;
    }
    cout << "getTen" << ans << endl;
    return ans;
}
int getReverse(int n)
{
    int ans = 0;
    string temp = to_string(n);
    string ans_str = "";
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        ans_str += temp[i];
    }
    ans = stoi(ans_str);
    cout << "getReverse: " << ans << endl;
    return ans;
}
int solution(int n)
{
    int answer = 0;
    int three = getThree(n);
    int rev = getReverse(three);
    answer = getTen(rev);
    cout << answer << endl;
    return answer;
}
int main()
{
    solution(45);
}