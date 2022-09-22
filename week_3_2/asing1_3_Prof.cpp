#include <vector>
#include <string>

using namespace std;

bool isSame(string A, string B, int shift)
{
    for (int i = 0; i < A.length(); i++)
    {
        // 인덱스가 넘치는 것을 해결해주기 위해서 (i + shift) % A.length()로 해주면 된다.
        if (A[i] != B[(i + shift) % B.length()])
        {
            return false;
        }
    }
    return true;
}

int solution(string A, string B)
{
    for (int answer = 0; A.length() == B.length() && answer < A.length(); answer++) // A와 B의 길이가 같음을 전제로 함.
    {
        // isSame을 answer 번 밀었을 떼, A와 B를 비교한다.
        // 5분뒤의 나를 믿고 일다 ㄴisSame의 동작 결과까지 생각을 하고 solution 함수를 구현하다. -> 이렇게 구현을 했다면 isSame을 구현해주면 된다.
        if (isSame(A, B, answer))
            return answer;
    }
    return -1;
}
// 이번 강의에서 제일 보여주고 싶은것은 devide & conquer -> 그 함수/isSame가 정상적으로 돌아갈 것이라는 가정하에, 함수/isSame를 만들어서 문제를 해결한다.
// devide & conquer를 해놓았기 때문에 디버깅도 빨리진다.
int main()
{
    int ans = solution("hello", "ohell");
}