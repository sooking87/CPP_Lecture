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
    // virtual int getArea(int top, int left); // P11의 솔루션이 불리는 순간 getArea는 virtual 함수니까 있는 그대로 P11의 ㅎgetArea를 링킹하는ㄱ 아니라 런타임에서 getArea가 호출되는 ㅎ=오브젝트를 보고 P112 오브젝트이므로 얘가 virtual 함수니까 아 P112의 getARea를 호출해주어야지. 하는 것이다.
    int getArea(int top, int left);
    // virtual bool isWhatIWant(int top, int left, int bottom, int right); // div&conq에서 나오는 블랙박스는 privat로 한다.
    bool isWhatIWant(int top, int left, int bottom, int right);
    virtual bool isCorrectSize(int top, int left, int bottom, int right); // 정사각형인지 직사각형인지 체크

public:
    P11(vector<vector<int>> table);
    int solution();
};
/* // 가장 넓은 직사각형 바꾸기 미션! */
/* P112 */
class P112 : public P11
{
    // 방ㅂㅂ 1 getArea에서 issquare을 수정해야되므로 걍 통채로 getArea를 오버라이드 해서 isRect이라는 함수를 새로 ㅂ만든다.
    // int getArea(int top, int left);
    // virtual bool isWhatIWant(int top, int left, int bottom, int right);
    virtual bool isCorrectSize(int top, int left, int bottom, int right);

public:
    P112(vector<vector<int>> table);
    // int solution();
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
            int area = getArea(i, j); // 이럴때의 getArea는 private으로 두는게 맞다. s내붖ㄱ으로 사용하고 싶은거지 외부적으로 사용하는 것은 아니다.
            // P112를 만들었을 때, 여기서 getARea는 P11께 불려진다. 항상. 그래서 답이 다르게 나왔던 것이다. 이걸 수정하기 위해서 오버라이드 필요
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
    for (int j = left; j < width; j++)
    {
        for (int i = top; i < height; i++)
        {
            if (isWhatIWant(top, left, i, j))
            // top left bottom right
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
    if (!isCorrectSize(top, left, bottom, right)) // 가로 세로 길이가 다르면
        return false;
    for (int i = top; i <= bottom; i++)
    {
        for (int j = left; j <= right; j++)
        {
            if (table[i][j] != 1) // 그 영역이 모두 1이 아니면 무조건 false 반환
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
/*
int P112::solution()
{
    int maxarea = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int area = getArea(i, j); // P`11과 같은 코드지만 P112를 부르기 위해서 오버라이드를 한것이다 동일한 코드가 둰 등장하는ㄱ 것은 비 효율이다. getArea를 virtual로
            if (area > maxarea)
            {
                maxarea = area;
            }
        }
    }
    cout << maxarea << endl;
    return maxarea;
}
*/
/*
int P112::getArea(int top, int left)
{
    int maxarea = 0;
    for (int j = left; j < width; j++)
    {
        for (int i = top; i < height; i++)
        {
            if (isRect(top, left, i, j))
            // top left bottom right
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
*/
/*
bool P112::isWhatIWant(int top, int left, int bottom, int right)
{
    for (int i = top; i <= bottom; i++)
    {
        for (int j = left; j <= right; j++)
        {
            if (table[i][j] != 1) // 그 영역이 모두 1이 아니면 무조건 false 반환
            {
                return false;
            }
        }
    }
    return true;
}
*/
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

/*
먼 미래를 봐야된다. 교수님 스타트업 썰,,,ㅋ 아이돌들이 나중에 잘 될 수도 있으니 싸인을 받아놓고 싶다.

함수나 변수 이름조차 좀더 중립적으로 가져간다. 클래스 디자인할시에 앞으로의 상속을 염두해두어서 상속에 친화적인 코드로 만든다. 즉, 예를 들어서 isWahtIWnat에 굳이 if 문 안에 함수를 넣어서 확인하는 것. 사실 저거는 직사각형까지 고려한 코드가 된다. 상속시에유리한 코딩을 미리밀 하는게 좋다.

수정을 할 수록 코드가 compact해지고 예뻐진다. 심미안이 생긴다. 마음으로 아름다움을 느끼는 눈... 코드에 대한 심미안이 생긴다.
*/