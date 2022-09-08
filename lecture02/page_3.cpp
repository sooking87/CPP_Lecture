#include <iostream>
#include <string>
using namespace std;
// 원래의 full name: std::cout , std::cin 그래야 애매함이 없어짐.

// c시절 코딩
int main()
{
    char first_name[100];
    printf("Please enter your first name (followed ");
    printf("by 'enter'):\n");
    scanf("%s", first_name);

    printf("Hello %s\n", first_name);
}

// cpp 코딩
// 이 방법이 직관적이고 편리하다.
int main()
{
    cout << "Please enter your first name (followed "
         << "by 'enter'):\n";
    string first_name;
    cin >> first_name;
    cout << "Hello, " << first_name << "\n";
}
// include 없이 컴파일하게 되려면