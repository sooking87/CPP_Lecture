#include <string>
#include <vector>
#include <iostream>

using namespace std;

// class P12
// {
// private:
//     long long x;
// public:
//     P12(long long x);
//     vector<long long> solution(vector<long long> numbers);
// }
long long getBin(long long x)
{
    int k = 1;
    long long re = 0;
    for (long long i = x; i > 0; i /= 2, k *= 10)
    {
        re += k * (i % 2);
    }
    return re;
}
int getSameCount(long long bin1, long long bin2)
{
    int bitSize = sizeof(bin1) * 8;
    int sameCnt = 0;
    long long mask = 1; // mask
    for (int k = 0; k < bitSize; k++)
    {
        /*
        n&mask: 1의 자리가 뽑힌다.    i&mask
        */
        if ((bin1 & mask) != (bin2 & mask)) // 다른 비트를 카운트함
        {
            sameCnt++;
        }
        mask = mask << 1;
    }
    cout << "sameCnt: " << sameCnt << endl;
    return sameCnt;
}
vector<long long> solution(vector<long long> numbers)
{
    vector<long long> answer;
    for (int i = 0; i < numbers.size(); i++)
    {
        int bitSize = sizeof(numbers[i]) * 8;
        long long mask = 1; // mask
        long long j;
        for (j = numbers[i] + 1;; j++)
        // for (j = numbers[i] + 1; j < numbers[i] + 7; j++)
        {
            cout << "j: " << j << endl;
            int sameCnt = 0;
            for (int k = 0; k < bitSize; k++)
            {
                /*
                n&mask: 1의 자리가 뽑힌다.    i&mask
                */
                if ((numbers[i] & mask) != (j & mask)) // 다른 비트를 카운트함
                {
                    sameCnt++;
                }
                mask = mask << 1;
            }
            cout << "sameCnt: " << sameCnt << endl;
            if (sameCnt <= 2)
                break;
        }
        cout << "answer: " << j << endl;

        answer.push_back(j);
    }
    return answer;
}
int main()
{
    solution({2, 7});
}