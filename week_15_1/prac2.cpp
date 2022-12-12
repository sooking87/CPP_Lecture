#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
/* for rand() */
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */

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
    int convert(int x, int y); // 2차원을 1차원으로 바꾸어주는 함수

public:
    Puzzle();
    void move(char c);
    bool isDone();
    friend ostream &operator<<(ostream &os, Puzzle &pz);
};

/* Puzzle 정의 */
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
        rn = rand() % 4;
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
                move('l');
                break;
            case 3:
                move('r');
                break;
            }
        }
        catch (notMovable &e)
        {
        }
    }
}
int Puzzle::convert(int x, int y)
{
    return 3 * y + x;
}
void Puzzle::move(char c)
{
    int to, from;
    switch (c)
    {
    case 'u':
        if (y == 0)
            throw notMovable();
        to = convert(x, y - 1);
        from = convert(x, y);
        cell[from] = cell[to];
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
        if (cell[i] != i + 1)
        {
            return false;
        }
    }
    if (cell[8] = 0)
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
            os << pz.cell[k++] << ' ';
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