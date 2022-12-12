#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class OutOfRange
{
};
class Path
{
private:
    int x1, y1, x2, y2;

public:
    Path(int xx1, int yy1, int xx2, int yy2);
    friend bool operator==(Path &p1, Path &p2);
};
class PathQue
{
private:
    vector<Path> route;
    bool isIn(Path &p);

public:
    void push(Path &p);
    int count();
};
class MyGame
{
private:
    int x, y;
    void move(char c);
    PathQue myque;

public:
    MyGame();
    void move(string &commands);
    friend ostream &operator<<(ostream &os, MyGame &game);
};
/* Path 정의 */
Path::Path(int xx1, int yy1, int xx2, int yy2)
{
    x1 = xx1;
    y1 = yy1;
    x2 = xx2;
    y2 = yy2;
}
bool operator==(Path &p1, Path &p2)
{
    if ((p1.x1 == p2.x1) && (p1.y1 == p2.y1) && (p1.x2 == p2.y2) && (p1.y2 == p2.y2))
        return true;
    if ((p1.x1 == p2.x2) && (p1.y1 == p2.y2) && (p1.x2 == p2.y1) && (p1.y2 == p2.y1))
        return true;

    return false;
}
/* PathQue 정의 */
void PathQue::push(Path &p)
{

    if (!isIn(p))
    {
        route.push_back(p);
    }
}
bool PathQue::isIn(Path &p)
{
    for (int i = 0; i < route.size(); i++)
    {
        if (route[i] == p)
            return true;
    }
    return false;
}
int PathQue::count()
{
    return route.size();
}
/* MyGame 정의 */
MyGame::MyGame()
{
    this->x = 0;
    this->y = 0;
}
void MyGame::move(char c)
{
    switch (c)
    {
    case 'U':
        if (y == 5)
            throw OutOfRange();
        y++;
        break;
    case 'D':
        if (y == -5)
            throw OutOfRange();
        y--;
        break;
    case 'R':
        if (x == 5)
            throw OutOfRange();
        x++;
        break;
    case 'L':
        if (x == -5)
            throw OutOfRange();
        x--;
        break;
    default:
        throw OutOfRange();
    }
}
void MyGame::move(string &commands)
{
    for (int i = 0; i < commands.size(); i++)
    {
        try
        {
            int prevX = x;
            int prevY = y;
            move(commands[i]);
            Path p(prevX, prevY, x, y);
            myque.push(p);
        }
        catch (const OutOfRange &e)
        {
        }
    }
}
ostream &operator<<(ostream &os, MyGame &game)
{
    os << "(" << game.x << ", " << game.y << ") -> " << game.myque.count() << endl;

    return os;
}
int main()
{
    MyGame game;
    string commands = "ULURRDLLU"; //"LULLLLLLU" "ULURRDLLU"
    game.move(commands);
    cout << game;

    Path path1(1, 2, 3, 4);
    Path path2(3, 4, 1, 2);
    Path path3(1, 2, 5, 6);
    // cout << (path1 == path2) << endl; // operator overloading 함수 정의 확인
    PathQue myque;
    myque.push(path1);
    myque.push(path2);
    myque.push(path3);
    cout << myque.count() << endl;
}