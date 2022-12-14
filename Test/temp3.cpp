#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

using namespace std;

class notMovable
{
};
class Puzzle
{
private:
    int cell[9];
    int x, y;
    void shuffle();
    int convert(int x, int y);

public:
    Puzzle();
    void move(char c);
    bool isDone();
    friend ostream &operator<<(ostream &os, Puzzle &pz);
};

Puzzle::Puzzle()
{
    for (int i = 0; i < 8; i++)
    {
        cell[i] = i + 1;
    }
    cell[8] = 0;
    x = 2;
    y = 2;
    shuffle();
}
void Puzzle::shuffle()
{
    srand(time(NULL));
    int rn;
    for (int i = 0; i < 4; i++)
    {
        rn = rand() % 4; // => 왜 4로 나눈 나머지지? : 이 랜덤 숫자를 통해서 4 방향중 하나를 정하기 때문이다.
        try
        {
            switch (rn)
            {
            case 0:
                move('u');
                break;
            case 1:
                move('d');
                break;
            case 2:
                move('r');
                break;
            case 3:
                move('l');
                break;
            }
        }
        catch (const notMovable &e)
        {
        }
    }
}
int Puzzle::convert(int x, int y)
{
    return y * 3 + x;
}
void Puzzle::move(char c)
{
    int to, from; // 0을 기준으로 0이 이동해야되는데 to, 이동 전 위치가 from
    switch (c)
    {
    case 'u':
        if (y == 0)
            throw notMovable();
        to = convert(x, y - 1); // 0을 위
        from = convert(x, y);
        cell[from] = cell[to]; // 0은 from 에서 to로 이동.
        cell[to] = 0;
        y--;
        break;
    case 'd':
        if (y == 2)
            throw notMovable();
        to = convert(x, y + 1);
        from = convert(x, y);
        cell[from] = cell[to];
        cell[to] = 0;
        y++;
        break;
    case 'r':
        if (x == 2)
            throw notMovable();
        to = convert(x + 1, y);
        from = convert(x, y);
        cell[from] = cell[to];
        cell[to] = 0;
        x++;
        break;
    case 'l':
        if (x == 0)
            throw notMovable();
        to = convert(x - 1, y);
        from = convert(x, y);
        cell[from] = cell[to];
        cell[to] = 0;
        x--;
        break;
    default:
        throw notMovable();
    }
}
bool Puzzle::isDone()
{
    for (int i = 0; i < 8; i++)
    {
        if (cell[i] != (i + 1))
            return false;
    }
    if (cell[8] != 0)
        return false;
    return true;
}
ostream &operator<<(ostream &os, Puzzle &pz)
{
    int k = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            os << pz.cell[k++] << " ";
        }
        os << endl;
    }
    return os;
}

int main()
{
    Puzzle mypuzzle;
    cout << mypuzzle;
    while (!(mypuzzle.isDone()))
    {
        char c;
        cout << "Choice movement: ";
        cin >> c;
        try
        {
            mypuzzle.move(c);
            cout << mypuzzle;
        }
        catch (notMovable &e)
        {
        }
    }
    cout << "It's done" << endl;
}