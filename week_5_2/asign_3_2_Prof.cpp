#include <iostream>
#include <string>
#include <vector>

using namespace std;

int changeToDec(vector<int> temp)
{
    int k = 1;
    int num = 0;
    for (int i = temp.size() - 1; i >= 0; i--, k *= 10)
    {
        num += temp[i] * k;
    }

    return num;
}
// sol 1.
vector<int> getNumbers(string my_string)
{
    vector<int> numbers;
    // 반복문이 있는데 , 걔는 my_string을 한글자씩 볼 수 있도록 하는 애 -> 문자면 버리고, 숫자면 temp에다가 한자리씩 push 해서 넣는다. -> 그런 다음 vector 안에 있는 1, 2, 3을 123으로 바꾸어 주어야 한다. 문자가 나타나면, changeToDec을 호출(changeToDec()의 역할)
    vector<int> temp;
    for (int i = 0; i < my_string.size(); i++)
    {
        // 숫자가 아닌 경우 = 아무일도 안하던지, temp에 넣어놓은 숫자가 있다면 숫자형으로 바꾸는 일을 해주어야된다.
        if (my_string[i] < '0' || my_string[i] > '9')
        {
            if (temp.size() > 0)
            {
                numbers.push_back(changeToDec(temp));
                temp.clear();
            }
        }
        else
        {
            temp.push_back(my_string[i] - '0');
        }
    }
    if (temp.size() > 0)
    {
        numbers.push_back(changeToDec(temp));
    }
    return numbers;
}

int solution(string my_string)
{
    int answer = 0;
    // 1. 숫자를 다 찾아서 찾은 숫자를 벡터에 저장된 저장된 숫자를 순서대로 더할까?
    vector<int> numbers = getNumbers(my_string);
    // getNumbers는 분리 -> 숫자를 찾아서 벡터를 리턴한다.
    for (int i = 0; i < numbers.size(); i++)
    {
        answer += numbers[i];
    }

    cout << answer << endl;
    return answer;
}
int main()
{
    solution("a1b2dc34");
}