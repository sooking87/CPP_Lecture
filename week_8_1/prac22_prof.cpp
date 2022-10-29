#include <iostream>
#include <string>
#include <vector>

using namespace std;

// denum은 ref로 전달할 것이다. = 두개 이상의 ㄱ밧을 리턴할 때는 ref로 처리하는게 더 간단하게 될 수 있다.
// 리턴 ㄱ밧이 굳이 한개라면 굳이 ref로 처리할 이유가 없다.
void getSum(int &denum, int &num, int denum1, int num1, int denum2, int num2)
{
    num = num1 * num2;
    denum = denum1 * num2 + denum2 * num1;
}

void postDiv(int &denum, int &num)
{
    int div = 0;
    int min = denum > num ? num : denum;

    // for (int i = min; i > 0; i--)
    // {
    //     if (denum % i == 0 && num % i == 0)
    //         div = i;
    // }
    // denum /= i;
    // num /= i;
    for (int i = 2; denum > 1 && num > 1 && num >= i;)
    {
        // 같은 숫자로 여러번 나누어 줄지도 모르기 때문에 또다시 동일한 i로 한 번 더 나눠 볼 수 있도록 확인하는 것이다.
        if (denum % i == 0 && num % i == 0)
        {
            denum = denum / i;
            num = num / i;
        }
        else
            i++;
    }
}
vector<int> solution(int denum1, int num1, int denum2, int num2)
{
    vector<int> answer;

    int denum, num;

    getSum(denum, num, denum1, num1, denum2, num2);
    postDiv(denum, num); // 기약 분수 만들기

    answer.push_back(denum);
    answer.push_back(num);
    return answer;
}
int main()
{
    solution(6, 4, 4, 4);
}
/*
기약분수 신경 안쓰고 그냥 일단 num1 * num2를 진행을 해 그런다음에 기약분수를 만든다 .
여기서 넘겨야되는 ㄱ밧, 받아야되는 ㄱ밧이 2개이기 때문에 ref를 활용해서 인자로 전달해주었다.
넘겨야될 값이 2개니까 call by ref로 처리ㅐㅆ다. 2개 이상의 ㄱ밧에 대한 ㄱeturn을 처리할 때 유용하게 잘 쓰인다. 그런 다음 공약수를 발견하면 그걸로 나누어 주는 수를 나누어 주고 싶은거야. 2부터 출발해서 두개 의 숫자보다 작은 숫자가 공약수로서 의미가 있다. 그래서 for문이 도는 조건이 i >= denum, num 이라는 조건이 붙은 것이다. 여기에 추가적으로 붙은 조건은 공약수를 발견하면 간은 공약수를 가지고 자꾸 나눌꺼야. 그래서 나누고 나누고 나누다가 둘 주 ㅇ 하나가 1이 되면 멈출 것이다. 그래ㅓㅅ denum > 1, num > 1을 만족시켜야 된다는 것이ㅏㄷ.
*/