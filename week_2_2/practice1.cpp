#include <iostream>
using namespace std;

// 숫자 두개 입력받아서 사칙연산 출력하기

int main()
{
    int val1, val2; // declaration과 definition(변수를 위한 메모리 할당을 받는 것)이 동시에 진행됨.
    // 이렇게 적으면 val1, val2 에 대한 메모리가 자동으로 생성 => 즉 declaration과 definition이 동시에 진행된 것
    int largest, smallest; // 초기화를 하는 것이 좋은 습관이다.

    // extern을 쓰게 되면 declaration만 진행된것 -> int j가 어딘가 있는 애야 다른 파일에 있는 앤데 내가 지금 쓸꺼니까 컴파일러야 이거 에러띄우면 안돼!
    // j가 어딘가 진짜로 정의되어있는 파일에서 메모리 할당을 받는 것. 그 이름을 가져다가 쓰기만 하는 것이므로 선언만 해주는 것이고 메모리는 잡히지 않은 것

    cout << "Please enter two integers: ";
    cin >> val1 >> val2;

    // 큰 값과 잡은값 정도는 변수로 저장해놓는 것이 편할 듯 하다.
    largest = (val1 > val2) ? val1 : val2;
    smallest = (val1 > val2) ? val2 : val1;
    cout << "largest: " << largest << endl; // endl을 권장하는 이유 : 머신 의존성 때문에 endl 사용하는 것을 권장
    cout << "smallest: " << smallest << endl;
    // 타자기 -> 키보드를 만들게 되었다. : 타자기는 잉크가 적셔져 있는 천이 있는데 그 앞에 하얀 종이가 있다. 타자기의 키판을 누르면 키 판에 해당하는 활자가 잉크가 묻어있는 천을 쿵 때린다. 때릴 때, 활자 모양대로 종이에 찍힌다.
    // 쓰다보면 줄바꿈이 필요: 아래로 한줄 내리고 맨 앞으로 종이를 당겨야된다. 즉 x 축이동, y축 이동이 필요 -> 이거를 newline(y축)과 line feed(x축)이라고 함
    // 근데 이거를 구현함에 있어서 사람들마다 다르다. 줄바꿈이 두개의 코드가 필요하다고 말한 os 가 있다. 타자기도 2개의 작업이 필요했으니까
    // 아니야! 타자기니까 그렇지. 컴퓨터는 줄바꿈 하나만 있으면 되지 -> newline 만 필요해!
    // 그래서 컴퓨터 OS 마다 줄바꿈 코드가 살짝 다르다.
    // 즉 \n은 newline 하나를 의미한다. 그래서 이거는 머신 의존성이 존재하게 된다.
    // endl은 os에 맞춰서 정의가 올바르게 된다. newline만 필요하면 newline을 쓰고 두개가 다 필요하면 두개를 자동으로 사용하게 된다.

    cout << largest << " + " << smallest << " = " << (largest + smallest) << endl; // + 가 << 보다 우선순위가 높다. -> 애매하다면 괄호를 치자!
    cout << largest << " - " << smallest << " = " << (largest - smallest) << endl;
    cout << largest << " * " << smallest << " = " << (largest * smallest) << endl;
    cout << largest << " / " << smallest << " = " << (largest / smallest) << endl;

    return 0;
}