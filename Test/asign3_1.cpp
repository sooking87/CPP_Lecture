#include <iostream>
#include <vector>
#include <string>

using namespace std;

// dim축에 대해서 최대, 최소를 구하는 함수.
int getDiff(vector<vector<int>> dots, int dim)
{
    int max = dots[0][dim];
    int min = dots[0][dim]; // 초기화는 절대 될 수 없는 값으로 해라. 또는 0번째 값

    for (int i = 1; i < dots.size(); i++)
    {
        if (max < dots[i][dim])
            max = dots[i][dim];
        if (min > dots[i][dim])
            min = dots[i][dim];
    }

    return max - min;
}
int solution(vector<vector<int>> dots)
{
    int answer = 0;
    int width = getDiff(dots, 0);
    int height = getDiff(dots, 1);

    answer = width * height;
    return answer;
}
int main()
{
    solution({{1, 1},
              {2, 1},
              {2, 2},
              {1, 2}});
}