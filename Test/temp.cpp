#include <string>
#include <vector>
#include <iostream>

using namespace std;

class P11
{
protected:
    int width;
    int height;
    vector<vector<int>> table;
    int getArea(int top, int left);
    bool isWhatIWant(int top, int left, int bottom, int right);
    virtual bool isCorrectSize(int top, int left, int bottom, int right);

public:
    P11(vector<vector<int>> table);
    int solution();
};
class P112 : public P11
{
    virtual bool isCorrectSize(int top, int left, int bottom, int right);

public:
    P112(vector<vector<int>> table);
};
/* P11 정의 */
P11::P11(vector<vector<int>> table)
{
    this->table = table;
    this->width = table[0].size();
    this->height = table.size();
}
int P11::getArea(int top, int left)
{
    int area = 0;
    for (int i = top; i < height; i++)
    {
        for (int j = left; j < width; j++)
        {
            if (isWhatIWant(top, left, i, j))
            {
                area = (i - top + 1) * (j - left + 1);
            }
        }
    }
    return area;
}
bool P11::isWhatIWant(int top, int left, int bottom, int right)
{
    if (!isCorrectSize(top, left, bottom, right))
    {
        return false;
    }
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
    {
        return false;
    }
    return true;
}
int P11::solution()
{
    int maxArea = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int area = getArea(i, j);
            if (area > maxArea)
            {
                maxArea = area;
            }
        }
    }
    cout << maxArea << endl;
    return maxArea;
}
/* P112 정의 */
bool P112::isCorrectSize(int top, int left, int bottom, int right)
{
    return true;
}
P112::P112(vector<vector<int>> table) : P11(table)
{
    ;
}
int main()
{
    P11 myp11({{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {0, 0, 1, 0}});
    myp11.solution();

    P112 myp112({{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {0, 0, 1, 0}});
    myp112.solution();
}