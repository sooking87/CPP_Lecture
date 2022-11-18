#include <iostream>
#include <new> // 없어도 에러는 안뜸.
using namespace std;

int main()
{
    int i, n;
    int *p; // 포인터 new를 통해서 int[i] 만큼 배열을 만듬.
    cout << "How many numbers would you like to type? ";
    cin >> i;
    p = new (nothrow) int[i];
    // nothrow 원래 메모리 할당 실패하면 예외처리를 다루는데 이 예제에서는 예외 없이 하려고 nothrow로 처리를 한 것이다.
    if (p == 0)
    {
        cout << "Error: memory could not be allocated";
    }
    else
    {
        for (n = 0; n < i; n++)
        {
            cout << "Enter number: ";
            cin >> p[n];
        }
        cout << "You have entered: ";
        for (n = 0; n < i; n++)
        {
            cout << p[n] << ", ";
        }
        delete[] p; // 배열 전체 삭제
    }
    return 0;
}