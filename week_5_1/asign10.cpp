#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db)
{
    string answer = "";
    cout << id_pw[0] << endl;
    for (int i = 0; i < db.size(); i++)
    {
        cout << i << endl;
        for (int j = 0; j < db[i].size(); j++)
        {
            if (id_pw[0] == db[i][0])
            {
                if (id_pw[1] == db[i][1])
                {
                    answer = "login";
                }
                else
                {
                    answer = "wrong pw";
                }
            }
            else
            {
                answer = "fail";
            }
        }
    }
    return answer;
}

int main()
{
    vector<string> ar1 = {"meosseugi",
                          "1234"};
    vector<vector<string>> ar2 = {{"rardss", "123"},
                                  {"yyoom", "1234"},
                                  {"meosseugi", "1234"}};
    solution(ar1, ar2);
}