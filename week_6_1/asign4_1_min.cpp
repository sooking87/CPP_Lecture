#include <string>
#include <vector>
#include <iostream>

// 동류항끼리 계산하여라
// 단, 변수는 x만 존재, 연산은 +만 존재

using namespace std;

// 수 이어주기
int connect_numbers(int num, int now)
{
    num = num * 10 + now;
    return num;
}

string solution(string polynomial)
{
    string answer = "";

    int temp = 0;     // 이미 숫자가 있는가
    int now_temp = 0; // 현재 걸린 숫자

    int x_cal = 0; // x 계수
    int x_flag = 0;
    int cal = 0; // 상수항 계수
    int num_flag = 0;

    for (char s : polynomial)
    {

        if (s >= '0' && s <= '9')
        { // 일단 수 합체
            now_temp = s - '0';
            temp = connect_numbers(temp, now_temp);
            // now_temp = 0;
        }
        else if (s == 'x')
        {
            x_flag = 1;

            if (temp == 0)
            {
                temp++;
            }
        }
        else if (s == '+')
        { // 총 정산
            if (x_flag == 0)
            { // 상수항 추가
                cal += temp;
                temp = 0;
            }
            else if (x_flag == 1)
            { // x 계수 추가
                x_cal += temp;
                x_flag = 0;
                temp = 0;
            }
        }
        now_temp = 0;
    }

    // temp에 수가 남아있는 경우
    if (x_flag == 1)
    {
        x_cal += temp;
    }
    else if (x_flag == 0)
    {
        cal += temp;
    }

    // 출력 값 answer에 저장
    // 주의할 점
    // 1. 0인 경우 출력 하지 말것
    // 2. x의 계수가 1인 경우 x출력(1x -> X)
    // 조건을 여러가지로 나누어 answer에 저장
    if (x_cal == 0 && cal != 0)
    {
        answer = to_string(cal);
    }
    else if (x_cal != 0 && cal == 0)
    {
        if (x_cal == 1)
        {
            answer = "x";
        }
        else
        {
            answer = to_string(x_cal) + "x";
        }
    }
    else if (x_cal == 0 && cal == 0)
    {
        answer = "0";
    }
    else
    {
        if (x_cal == 1)
        { // 따로 처리
            answer = "x";
        }
        else
        {
            answer = to_string(x_cal) + "x";
        }

        answer = answer + " + " + to_string(cal);
    }

    return answer;
}