#include <iostream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class incorrectInput
{
};
class overflowError
{
};

int product(int from, int count)
{
    int answer = 1;
    int temp;
    for (int i = 0; i < count; i++)
    {
        temp = answer * (from - i);
        if (temp < answer)
            throw overflowError();
        answer = temp;
    }

    return answer;
}
int solution(int balls, int share)
{
    int answer;
    if (balls <= 0 || share <= 0)
        throw incorrectInput();

    try
    {
        int a = product(balls, share);
        int b = product(share, share);
        answer = a / b;
    }
    catch (overflowError e)
    {
        cout << "OverFlow Error" << endl;
    }
    catch (incorrectInput e)
    {
        cout << "OverFlow Error from solution" << endl;
    }

    cout << "answer: " << answer << endl;
    return answer;
}
int main()
{
    int balls, share;
    cin >> balls >> share;
    try
    {
        cout << solution(balls, share);
    }
    catch (incorrectInput e)
    {
        cout << "Incorrect Error from Main" << endl;
    }
}