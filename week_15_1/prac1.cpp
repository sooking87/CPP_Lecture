#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class SevenSegs;
class SevenSeg
{
private:
    int n;
    char seg[15];
    void Set();

public:
    SevenSeg(int n);
    friend ostream &operator<<(ostream &os, SevenSeg &ss);
    friend ostream &operator<<(ostream &os, SevenSegs &ss);
};
class SevenSegs
{
private:
    int n;
    vector<SevenSeg> segs;
    void Set();

public:
    SevenSegs(int n);
    friend ostream &operator<<(ostream &os, SevenSegs &ss);
};
/* SevenSeg 정의 */
SevenSeg::SevenSeg(int n)
{
    this->n = n;
    Set();
}
void SevenSeg::Set()
{
    // 숫자를 이쁘게 만들어주기 위한 빈 공간
    seg[0] = ' ';
    seg[2] = ' ';
    seg[4] = ' ';
    seg[6] = ' ';
    seg[8] = ' ';
    seg[10] = ' ';
    seg[12] = ' ';
    seg[14] = ' ';

    if (n == 0 || n == 2 || n == 3 || n == 5 || n == 6 || n == 7 || n == 8 || n == 9)
        seg[1] = '-';
    else
        seg[1] = ' ';

    if (n == 0 || n == 4 || n == 5 || n == 6 || n == 7 || n == 8 || n == 9)
        seg[3] = '|';
    else
        seg[3] = ' ';

    if (n == 0 || n == 1 || n == 2 || n == 3 || n == 4 || n == 7 || n == 8 || n == 9)
        seg[5] = '|';
    else
        seg[5] = ' ';

    if (n == 2 || n == 3 || n == 4 || n == 5 || n == 6 || n == 8 || n == 9)
        seg[7] = '-';
    else
        seg[7] = ' ';

    if (n == 0 || n == 2 || n == 6 || n == 8)
        seg[9] = '|';
    else
        seg[9] = ' ';

    if (n == 0 || n == 1 || n == 3 || n == 4 || n == 5 || n == 6 || n == 7 || n == 8 || n == 9)
        seg[11] = '|';
    else
        seg[11] = ' ';

    if (n == 0 || n == 2 || n == 3 || n == 5 || n == 6 || n == 8)
        seg[13] = '-';
    else
        seg[13] = ' ';
}
ostream &
operator<<(ostream &os, SevenSeg &ss)
{
    // for (int i = 0; i < 15; i++)
    // {
    //     if (i % 3 == 0)
    //     {
    //         os << endl;
    //     }
    //     os << ss.seg[i];
    // }
    int k = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            os << ss.seg[k++];
        }
        os << endl;
    }
    return os;
}
/* SevenSegs 정의 */
SevenSegs::SevenSegs(int n)
{
    this->n = n;
    Set();
}
void SevenSegs::Set()
{
    for (int k = n; k > 0; k /= 10)
    {
        SevenSeg temp(k % 10);
        segs.push_back(temp);
    }
}
ostream &
operator<<(ostream &os, SevenSegs &ss)
{
    int k = 0;

    for (int i = 0; i < 5; i++)
    {
        for (int j = ss.segs.size() - 1; j >= 0; j--)
        {

            for (int l = 0; l < 3; l++)
            {

                os << ss.segs[j].seg[k + l];
            }
        }
        k += 3;
        os << endl;
    }
    return os;
}
int main()
{
    int n;
    cin >> n;
    SevenSeg s(n);
    cout << s;

    int k;
    cin >> k;
    SevenSegs ss(k);
    cout << ss;
}