#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> masks, vector<string> dates)
{
    int result = 0;
    sort(dates.begin(), dates.end());
    for (auto i : dates)
    {
        cout << i << endl;
    }
    return result;
}
int main()
{
    solution({{3200, 4}, {2300, 2}, {1100, 1}, {4200, 6}}, {"2022/05/02", "2022/05/01", "2022/05/07", "2022/05/05", "2022/05/08", "2022/05/13~2022/05/15", "2022/05/14~2022/05/17", "2022/05/01~2022/05/02", "2022/05/16", "2022/04/12"});
}