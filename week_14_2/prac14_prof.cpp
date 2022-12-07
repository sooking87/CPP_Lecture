#include <string>
#include <iostream>
#include <vector>

using namespace std;

class OutOfBound
{
};
// MyGame 클래스에서 최종 도착점을 나왔따.  새로 만들 클래스를 통해서 지나온 길을 저장한다. 어떻게 길을 정의할 것인가. 죄표 두개로 표현할 수 있고, 한 점을 기준으로 간 경로를 줄 수 있다.
// 같은 길을 가더라도 방향성이 다른 것까지 정의를 해야되는 것이냐 이거를 같다는 것으로 볼지 다르다는 것으로 볼지가 경계가 애매하다. 일단은 방향은 달라도 같은 길을 걷게 된다면 결국 같은 길을 이동한 것이라고 표현을 해보자 = 좌표 두개로 표현을 한다.
class Path
{
    int x1, y1, x2, y2;

public:
    Path(int xx1, int yy1, int xx2, int yy2);
    friend bool operator==(Path &a, Path &b);
};
// pathque를 이용해서 계속해서 path를 집어넣는 것을 원함. 이걸 그냥 하고 싶은 것이다. 그런데 몇개가 들어갔는지는 count 하는 것이다. 근데 똑같은 경로가 잇으면 안되므로 기존에 동일한 패쓰가 저장이 된적이 있는지 검사를 하고 push를 한다.
class PathQue
{
    vector<Path> paths;
    bool isIn(Path &a);

public:
    void push(Path &a);
    int count();
};
class MyGame
{
    int x, y;
    PathQue myque;
    void move(char c);

public:
    MyGame();
    void move(string &commands);
    int getX();
    int getY();
    int getCount();
};
/* MyGame 정의 */
MyGame::MyGame()
{
    x = 0;
    y = 0;
}
void MyGame::move(char c)
{
    switch (c)
    {
    case 'U':
        // y값을 증가시킨다.
        // 이미 y가 5면 증가 못해. 그거에 대한 처리를 어떻게 할까? exception 처리를 해준다.
        if (y == 5)
            throw OutOfBound();
        else
        {
            y++;
            break;
        }
    case 'D':
        if (y == -5)
            throw OutOfBound();
        else
        {
            y--;
            break;
        }
    case 'R':
        if (x == 5)
            throw OutOfBound();
        else
        {
            x++;
            break;
        }
    case 'L':
        if (x == -5)
            throw OutOfBound();
        else
        {
            x--;
            break;
        }
    }
}
void MyGame::move(string &commands) // 여러개의 string 커멘드가 들어오면 여기서 commands의 모든 캐릭터에 대해서 순차적으로 move를 호출하는 것이다. 이름은 같지만 서로 다른 파라미터를 사용해서 결구 다른 함수인것
{
    // 기본적인 아이디어는
    for (int i = 0; i < commands.size(); i++)
    {
        try
        {
            int preX = x;
            int preY = y;
            move(commands[i]);
            Path temp(preX, preY, x, y);
            myque.push(temp);
        }
        catch (const OutOfBound &e) // 프로그램이 죽는거 방지용
        {
        }
    }
}
int MyGame::getCount()
{
    return myque.count();
}
int MyGame::getX()
{
    return x;
}
int MyGame::getY()
{
    return y;
}
/* Path 정의 */
Path::Path(int xx1, int yy1, int xx2, int yy2)
{
    x1 = xx1;
    y1 = yy1;
    x2 = xx2;
    y2 = yy2;
}
bool operator==(Path &a, Path &b)
{
    if ((a.x1 == b.x1) && (a.y1 == b.y1) && (a.x2 == b.x2) && (a.y2 == b.y2))
        return true;
    if ((a.x1 == b.x2) && (a.y1 == b.y2) && (a.x2 == b.x1) && (a.y2 == b.y1))
        return true;
    return false;
}
/* PathQue 정의 */
bool PathQue::isIn(Path &a)
{
    for (int i = 0; i < paths.size(); i++)
    {
        if (paths[i] == a)
        {
            return true;
        }
        return false;
    }
}
int PathQue::count()
{
    cout << "paths.size(): " << paths.size() << endl;
    return paths.size();
}
void PathQue::push(Path &a)
{
    if (!isIn(a))
    {
        paths.push_back(a);
    }
}

int main()
{
    MyGame game;
    string commands = "ULURRDLLU"; //"LULLLLLLU" "ULURRDLLU"
    game.move(commands);
    cout << "(" << game.getX() << ", " << game.getY() << ") -> " << game.getCount() << endl;
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
// c++ 이 나온 이유 : 하드웨어에 비해서 소프트웨어의 발전 속도가 너무 초라해 생산성이 너무 떨어져 이거를 개선해야겠다. 캡슐화 다형성 상속을 통해서 개선하였다.
// 캡슐화를 통해서 모듈화를 하였다. 그 내부는 나도 몰라. 모듈화는 코드 구현의 의존도를 끊어준다. 그럼으로써 재사용성 업그레이드의 용이성 향상
// 다형성 매번 달라지는 함수 기능의 이름을 같게 된다. == 같은 경우 path 두개가 같은가 == 사용하면된다. 아 이거 함수 이름 ㅜ머써야되지? 이럴 필요가 없다. 내가 기억해야되는 이름이 훨씬 줄어들고 프로그래밍에 사용해야되는 단어가 줄어든다. 외워야될 단어가 줄어들고 그때그때 구현만 조금씩 달라져서 생산성을 높인다.
// 상속 - 기본의 코드에서 바뀌지 않아아될 코드는 그대로 재활용 가능. 내가 바꾸어야 되는 부분만 추가해야되는 부분만 콕 찝어서 추가가가능 중복 코딩의 최소화. -> 복붙은 어느 한 군데가 바뀌면 다 찾아가면서 다시 바꾸어야 된다. 그게 매우 비효율적이고 오류를 일으킬 가능성이 크다. 그런 일들이 벌어진다. 코드 재사용을 체계화. 소스 코드 없이도 제사용 가능.

// 클래스를 써서 어떻게 캡슐화 하고 어떻게 상속을 하고 어떻게 다형성을 구현하는지에 대해서 기본적인 방향성을 가져야된다. 이제 출발점을 가진것이다. 가장 기초적으로 알아야될 기초지식을 얻은 것이다. 이게 진짜 실력이 되려면 경험이 쌓여야 된다. 그래야 수업시간에 배운게 우리것이 된다. 숙제, 동아리, 학부 연구원........을 통해서 경험을 쌓자