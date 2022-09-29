#include <iostream>
#include <string>
#include <vector>

using namespace std;

int match(vector<string> id_pw, vector<string> each_db)
{
    if (id_pw[0] == each_db[0])
    {
        if (id_pw[1] == each_db[1])
        {
            return 2;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}
string solution(vector<string> id_pw, vector<vector<string>> db)
{
    string answer = "fail";
    int case_each;

    for (int i = 0; i < db.size(); i++)
    {
        case_each = match(id_pw, db[i]);

        if (case_each == 2)
            return "login";
        else if (case_each == 1)
            return "wrong pw";
        else
            return "fail";
    }
    return answer;
}