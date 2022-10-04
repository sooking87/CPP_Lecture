#include <iostream>
#include <string>
#include <vector>

using namespace std;

int getDiff(vector<vector<int>> dots, int dim)
{
    int max = dots[0][dim];
    int min = dots[0][dim]; // 초기화는 절대 될 수 없는 값으로 해라. 또는 0번째 값

    for (int i = 1; i < dots.size(); i++)
    {
        if (max < dots[i][dim])
        {
            max = dots[i][dim];
        }
        if (min > dots[i][dim])
        {
            min = dots[i][dim];
        }
    }

    return max - min;
}
int solution(vector<vector<int>> dots)
{
    int answer = 0;
    // 네 점의 순서는 딱히 언급이 없음
    int width, height;
    // getDiff 2번째 있는 차원의 가장 작은값과 가장 큰 값의 차이를 리턴할 함수야.
    width = getDiff(dots, 0);
    height = getDiff(dots, 1);

    answer = width * height;
    return answer;
}