#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<double> temps;
    double temp;

    // 길이 신경쓰지 않고 계속 push_back 가능
    while (cin >> temp)
        temps.push_back(temp);

    double sum = 0;
    for (int i = 0; i < temps.size(); ++i)
    {
        sum += temps[i];
        //일반적으로 array에 접근하는 방식과 같으며 vector 에서도 [] 연산자를 사용할 수 있다.
    }

    cout << "Mean temperature: " << sum / temps.size() << endl;
    sort(temps.begin(), temps.end());
}