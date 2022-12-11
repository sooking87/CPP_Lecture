#include <string>
#include <vector>

using namespace std;

/* Eneymy 선언 */
class Enemy
{
private:
    vector<int> enemy;

public:
    Enemy(vector<int> enemy);
    vector<int> getEnemy();
};
/* MyExp 선언 */
class MyExp
{
private:
    int n;
    int k;

public:
    MyExp(int n, int k);
    MyExp operator-(int e);
    friend ostream &operator<<(ostream &os, MyExp &me);
    int getN();
    int getK();
};
/* Enemy 정의 */
Enemy::Enemy(vector<int> enemy)
{
    this->enemy = enemy;
}
vector<int> Enemy::getEnemy()
{
    return enemy;
}
/* MyExp 정의 */
MyExp::MyExp(int n, int k)
{
    this->n = n;
    this->k = k;
}
int MyExp::getN()
{
    return n;
}
int MyExp::getK()
{
    return k;
}
MyExp MyExp::operator-(int e)
{
    n -= e;
    return MyExp(n, k);
}
ostream &operator<<(ostream &os, MyExp &me)
{
    os << "n: " << me.n << "k: " << me.k << endl;
    // os << me.n;

    return os;
}
int solution(int n, int k, vector<int> enemy)
{
    int answer = 0;
    MyExp me(n, k);
    Enemy e(enemy);

    cout << me;
    me - enemy[0];
    cout << me;

    return answer;
}