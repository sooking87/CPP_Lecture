#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> buildings)
{
    vector<string> answer;
    for (int i = 0; i < buildings.size(); i++)
    {
        string connect;
        int cnt = 0;
        for (int j = 0; j < buildings[i].size(); j++)
        {
            cout << "buildings[i][j]: " << buildings[i][j] << endl;

            if (buildings[i][j] == 'n' && connect == "")
            {
                connect = "n";
            }
            else if (buildings[i][j] == 'a' && connect == "n")
            {
                connect += "a";
            }
            else if (buildings[i][j] == 'k' && connect == "na")
            {
                connect += "k";
            }

            if (connect == "nak")
            {
                cnt++;
                connect = "";
            }
            cout << "connect: " << connect << endl;
        }
        if (cnt == 2)
        {
            answer.push_back("O");
        }
        else
        {
            answer.push_back("X");
        }
    }
    for (auto i : answer)
    {
        cout << i << " ";
    }
    cout << endl;
    return answer;
}
int main()
{
    solution({"sungsoo_naknak", "i_am_not_a_kim_and_not_awk", "nananananannakkk"});
}