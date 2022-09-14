#include <iostream>
using namespace std;

int main()
{
    string first, second;

    cout << "Please enter your first and second names" << endl;
    cin >> first >> second;
    string name = first + ' ' + second;

    cout << "Hello, " << name << endl;
}