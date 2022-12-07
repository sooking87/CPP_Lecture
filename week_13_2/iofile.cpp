// C:\STUDY\4학기\CPP_Lecture\week_13_2
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Reading
{
public:
    int hour;
    double temperature;
};

int main()
{
    vector<Reading> temps;
    ifstream ist("sample.txt"); // 생성자가 파일 경로에 따라서 기본으로 열고, ist의 소멸자로 의해ㅓ 자동으로 닫힘.
    int hour;
    double temperature;
    cout << "!!" << endl;
    if (ist.is_open())
    {
        while (ist >> hour >> temperature) // (ist >> hour >> temperature) //(ist.get(c))
        {
            if (hour < 0 || 23 < hour)
            {
                cout << "hour out of range" << endl;
            }
            cout << hour << ", " << temperature << endl;
            temps.push_back(Reading{hour, temperature});
        }
    }
    else
    {
        cout << "no file search" << endl;
    }
}

// void fill_vector(istream &ist, vector<int> &v, char terminator)
// {
//     for (int i; ist >> i;)
//     {
//         v.push_back(i);
//     }
//     if (ist.eof())
//         return;
//     if (ist.bad())
//         cout << "error" << endl;
//     if (ist.fail())
//     {
//         ist.clear();
//         char c;
//         ist >> c;
//         if (c != terminator)
//         {
//             ist.unget();
//             ist.clear(ios_base::failbit);
//         }
//     }
// }
// int main()
// {
//     vector<int> temps;
//     ifstream ist("sample2.txt");
//     ist.exceptions(ist.exceptions() | ios_base::failbit); // fail로 만나면 exception으로 던지라 default는 예외 던지지 말고 참어 조용히 error status에 참을 인을 그으렴. status bit만 fail로 그어놓아. 동작을 exception으로 날리느 방식으로 처리하지 않는다 defualt는. 좀더 c++ 스러운 방식은 exception을 날리는 것이다. 특히 bad() 같은 경우는. 이걸 날려서 코드ㅔ서 명시적으로 알리는 것이 ㅊ++ 스러운 것이다. failbit 날려 이게 1이 되면 예외를 날리라는 것이다.
//     // ist의 지금 현재 exceptions 값을 유지하면서 failtbit를 더하기 시킨다는 것이다. 기존의 ㄷxception은 그대로 유지하고 거기에 failbit도 추가로 키겠다는 것이다. 그래서 이렇게 쓰게 된다면 fail을 하더라도 exception을 날리게 된다.
//     try
//     {
//         fill_vector(ist, temps, 'q');
//     }
//     catch (ios_base::failure &e)
//     {
//         cout << "exception handling " << endl;
//     }
//     cout << ist.eof() << endl;  // fail의 스페셜한 케이스이다. eof는 fail이기도 하지만 스페셔라게 eof 라는 것이다.
//     cout << ist.fail() << endl; // eof도 fail에 하나의 종류로 본다.
// }