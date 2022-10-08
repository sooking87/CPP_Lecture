#include <iostream>
#include <string>
#include <vector>

using namespace std;

class overflowError
{
};
class incorrectInput
{
};
// from 부터 count 개수만큼 곱해주는 함수(아래로 내려가면서)
int product(int from, int count)
{
    int answer = 1;
    if (from <= 0 || count <= 0)
        throw incorrectInput();
    int temp;
    for (int i = 0; i < count; i++)
    {
        temp = answer * (from - i); // temp가 overflow가 벌어질지 의심이 돼 저 값이 기존의 anser보다 작아지면 overflow라고 판단하겠다.
        if (temp < answer)
            throw overflowError(); // 문제 상황을 보고 저 상황은 정상 상황이 아니다. = overflow 메세지를 던져주겠다.
        answer = temp;
    }

    cout << "answer: " << answer << endl;
    return answer;
}
int solution(int balls, int share)
{
    int answer;
    if (balls < share)
    {
        throw incorrectInput(); // 야는 main이 잡아주어야 돼
    }

    try
    {
        int a = product(balls, share);
        int b = product(share, share);
        answer = a / b;
    }
    // 이거를 통해서 내가 일일이 디버거하지 않는 이상 그 문제를 명시적으로는 알 수 ㅇ벗다. 그러나 이런식으로 문제가 벌어질 숭 ㅣㅆ는 상광에 대해서 미리 throw 할 수 있도록 문제를 만들었을 경우, 그 문제상황이 보고가 된다.
    catch (overflowError e)
    {
        cout << "Overflow Error" << endl;
        answer = -1;
    }
    catch (incorrectInput e)
    {
        cout << "solution Icorrect Input" << endl;
    }
    // catch가 된다음은 정상적인 라인으로 돌ㄷ아간다.
    return answer;
}
int main()
{
    // cathc가 수행되고 나면 정상 수행이 가능하다는 것을 확인할 수 잇는 반복문.
    for (int i = 0; i < 5; i++)
    {
        int balls, share;
        cin >> balls >> share;
        try
        {
            cout << solution(balls, share);
        }
        catch (incorrectInput e)
        {
            cout << "main Icorrect Input" << endl;
        }
    }

    // 예외 처리 : 문제를 미리 예상 조건을 비교해서 적절한 exception을 던지는게 첫 번째 목표 = 지금 무슨 문제때문ㅇ 발생했는지 알려주고 싶어 => 그래서 에러 명을 따로 클래스로 만들어준것이다. 누가 던져진것인지를 구별한다. 예를 들어서 input이 음수인경우에도 incorrectInput이다 .
    /*
    product를 호출하는데 또 다시 incorrectinput 에러를 throw할 수 있다. = 그러면 궁금해하는 거는 product 함수안에 던지는 에러 타임이 다르다. 하나는 incorrect, 하나는 overflow 근데 밑에 solution 함수의 try, catch를 보면 incorrectInput을 잡지를 않는다.

    다시다시
    product에서 throw -> 되는 순간 하뭇로부터 빠져나가 throw 아래에 있는 라인들은 모두 무시된다. (해당 함수 안에서의 밑에 있는 코드들) 그러면서 그 실행했던 func은 바로 종료 그러면서 내가 던지는 incorrectInput이라는 객체만 날라가 -> 그러면서 product가 종료 -> 이게 종료되면 solution 함수로 넘어온다. 그러면서 product 함수가 정상 종료가 되지 않았기 때문에 그 solution 아래 라인도 모두 무시 그러면서 이 함수도 원칙적으로는 종료시켜야됨. throw되는 순간 모든 함수로부터 다 빠져나와 그렇게 무섭게 빠져나오는 exception object를 멈추고 싶어 그ㅓ면 그 주위를 try & catch로 감쌓야된다. try라고 되어있는 그 안에서 던져지는 exception은 그 바깥에서 catch해줄께. exception이 벌어져도 적절한 조치후 정상 종료를 원한다.

    가장 바람직하 ㄴ시나리오는 적절한 예외를 깨닫고, 이에 ㄸ른 적절한 예외를 처리 -> 정상 운영이 목적. 따라서 throw가 던져지는 순간 무조건 프로그램 종료인데 즉, 동작의 원리는 원래 바ㅗㄹ out인데 예외 처리의 목적은 정상적인 상황처리이다. 그러기 위해서는 정상적인 상황 처리를 위한 문법이 필요하다. 그개 try & catch이다. try에서 날라오는 excepton을 catch가 잡아준다. 문제는 catch가 골라잡는다는 것이다. solution의 catch는 overflowError 예외만 잡는다. catch안에 문장이 수행이 되고 비상 상황이 아니기 때문에 catch 다음문장으로 정상상황으로 넘어가게 된다. "이제 부터는 정상상황 입니다^^" 한번 잡아주면 그 다음부터 정상 플로우로 복귀! + 어떤 문제인지에 대한 정보를 주는 것이다. 문제의 원인을 구분해서 정보를 주기 위해서 클래스를 만드는 것이다.

    ?? 만약 input이 음수로 인한 에러가 뜬다면 product : exit -> solution : exit -> main 에서 catch 로 넘어가는거?

    incorrectInput에 대한 catch를 solution과 main으로 둘다 했을 때 위에서 먼저 잡는 순간 이미 정상 상황으로 돌아간 것이다. throw는 한번 잡히면 거기서 소멸된다. 잡을 때 자기의 타입이 정해져있다. catch가 잡을 수 잇는 애가 정해져 있따. 바람직하지 않지만 자주 쓰는 방법이 있다. 뭐든 잡겠어!!!!!!!!! 그 문법이 있다.
    catch(...) {}; -> 이거임. 이걸 즐겨쓴느거는 권장되지 않아. 원인을 모르게되니까 최악의 경우를 막기 위해서 일단 잡는 것이지 무가 날라온지를 몰라서 그 상황에 맞는 적절한 조치를 할 수 없다. 그래서 일밙거으로 권장되지는 않는다.

    부가적인 정보를 더 보낼 수 있긴함. 근데 클래스를 배우지 않았기 때문에 이거에 대한 설명은 하지 않음. 클래스를 통해서, 상속을 통해서 예외처리를 좀 더 구체적으로 할 수는있다.

    throw, 클래스를 구별하는 위미 catch는 어느 영역을 감쌓야되는지, catch에 의해서 잡히지 않으면 어떻게 동작하는지, 잡히면 어덯ㄱ 동작하는지에 대해서 배웠다. C와 c++의 차이는 c는 이거와 유사하게 구현은 하지만 궇ㄴ법이 정상 플로우를 따라가게 되어있다. throw하면 중간에 함수를 종료시키는 return, exit이 필요하지 않아 c++에서는) -> 그러나 C의 경우는 값을 판단ㅎ고 그런다음 에러라면 이렇게 처리하고,, 이렇게 해야되는데 단점은 코드를 읽는 사람이 정상적인 플로우인지 예외에 대한 처리를 위한 플로우인지를 확인하기가 힘들다. C++처럼 가독성이 좋도록 만드는 코드가 예쁜 코드다. throw = 문제, try = 의심 구간, catch = 문제 해결/처리

    시험: 8주차 화요일에 시험 /  컴 or 종이인지는 나중에 다시 노티
    다음 주 화요일 수업시간 직전까지 제출하는 과제가 나갈 것이니까 체크하고 화요일 전까지 과제할 것
    */
}