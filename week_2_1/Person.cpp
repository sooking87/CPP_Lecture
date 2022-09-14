#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    int age;
    string name;

public:
    Person(int a, string n) : age(a), name(n)
    {
    }
    void showName() const
    {
        cout << "Hi My name is " << name << ".  ";
    }
    void showAge() const
    {
        cout << "I am " << age << " years old. " << endl;
    }
    void showInfo() const
    {
        showName();
        showAge();
    }
};

class Student : public Person
{
private:
    int score;

public:
    Student(int a, string n, int s) : Person(a, n), score(s)
    {
    }
    // Overwriting
    void showInfo() const
    {
        showName();
        showAge();
        cout << "My score is " << score << ". " << endl
             << endl;
    }
};

class Professor : public Person
{
private:
    int classNum;

public:
    Professor(int a, string s, int cn) : Person(a, s), classNum(cn)
    {
    }
    // overwrite
    void showInfo() const
    {
        showName();
        showAge();
        cout << "My ClassNum is " << classNum << "." << endl
             << endl;
    }
};

int main()
{
    Person p1 = Person(22, "Sohn");
    p1.showInfo();

    p1 = Student(21, "Choi", 90);
    p1.showInfo();

    p1 = Professor(40, "Chul", 01);
    p1.showInfo();

    Student s1 = Student(30, "Kim", 70);
    s1.showInfo();

    Professor pro1 = Professor(50, "Yeon", 02);
    pro1.showInfo();
}