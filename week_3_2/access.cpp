#include <iostream>
#include <vector>
using namespace std;

// 접근할 수 있는 방법
int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6};

    // 클래식 문법
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }

    // 최근 지원
    for (int i : v)
    {
        cout << i << endl;
    }

    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }
}