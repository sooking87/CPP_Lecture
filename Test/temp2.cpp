#include <iostream>
#include <vector>
using namespace std;

/* P11 */
class P11
{
protected:
    vector<vector<int>> table;
    int width;
    int height;
    int getArea(int top, int left);
    bool isWhatIWant(int top, int left, int bottom, int right);
    virtual bool isCorrectSize(int top, int left, int bottom, int right);

public:
    P11(vector<vector<int>> table);
    int solution();
};
/* // 가장 넓은 직사각형 바꾸기 미션! */
/* P112 */
class P112 : public P11
{
    virtual bool isCorrectSize(int top, int left, int bottom, int right);

public:
    P112(vector<vector<int>> table);
};

/* P11 구현 */
P11::P11(vector<vector<int>> table)
{
    this->table = table;
    this->width = table[0].size();
    this->height = table.size();
}
int P11::solution()
{
    int maxarea = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int area = getArea(i, j);
            if (area > maxarea)
            {
                maxarea = area;
            }
        }
    }
    cout << maxarea << endl;
    return maxarea;
}
int P11::getArea(int top, int left)
{
    int maxarea = 0;
    cout << "getArea maxArea: " << maxarea << endl;
    for (int j = left; j < width; j++)
    {
        for (int i = top; i < height; i++)
        {
            if (isWhatIWant(top, left, i, j))
            {
                int area = (i - top + 1) * (j - left + 1);
                if (area > maxarea)
                {
                    maxarea = area;
                }
            }
        }
    }
    return maxarea;
}
bool P11::isWhatIWant(int top, int left, int bottom, int right)
{
    if (!isCorrectSize(top, left, bottom, right))
        return false;
    for (int i = top; i <= bottom; i++)
    {
        for (int j = left; j <= right; j++)
        {
            if (table[i][j] != 1)
            {
                return false;
            }
        }
    }
    return true;
}
bool P11::isCorrectSize(int top, int left, int bottom, int right)
{
    if ((bottom - top) != (right - left))
        return false;
    return true;
}

/* P112 구현 */
P112::P112(vector<vector<int>> table) : P11(table)
{
    ;
}
bool P112::isCorrectSize(int top, int left, int bottom, int right)
{
    return true;
}
int main()
{
    P11 myp11({{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {0, 0, 1, 0}});
    myp11.solution();

    P112 myp112({{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {0, 0, 1, 0}});
    myp112.solution();
}