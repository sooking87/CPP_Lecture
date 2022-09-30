#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> dots)
{
    int answer = 0;
    int start_x = dots[0][0]; // min x
    int start_y = dots[0][1]; // min y
    int end_x = dots[0][0];   // max x
    int end_y = dots[0][1];   // max y
    for (int i = 1; i < dots.size(); i++)
    {
        if (start_x > dots[i][0])
        {
            start_x = dots[i][0];
        }
        if (start_y > dots[i][1])
        {
            start_y = dots[i][1];
        }
        if (end_x < dots[i][0])
        {
            end_x = dots[i][0];
        }
        if (end_y < dots[i][1])
        {
            end_y = dots[i][1];
        }
    }

    int width = end_x - start_x;
    int height = end_y - start_y;
    answer = width * height;

    return answer;
}

int main()
{
    solution({{1, 1}, {2, 1}, {2, 2}, {1, 2}});
}