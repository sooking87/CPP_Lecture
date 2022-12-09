
#include <iostream>

using namespace std;

class Polygon
{
protected:
    int width;
    int height;

public:
    Polygon(int width, int height);
    virtual ~Polygon();
    virtual void draw() = 0;
};
class Rectangle : public Polygon
{
public:
    Rectangle(int width, int height);
    ~Rectangle();
    virtual void draw();
};
class Triangle : public Polygon
{
public:
    Triangle(int width, int height);
    ~Triangle();
    virtual void draw();
};
Polygon::Polygon(int width, int height)
{
    this->width = width;
    this->height = height;
}
Polygon::~Polygon()
{
    cout << "~Polygon() is Called" << endl;
}
Rectangle::Rectangle(int width, int height) : Polygon(width, height)
{
    ;
}
void Rectangle::draw()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
Rectangle::~Rectangle()
{
    cout << "~Rectangle() is Called" << endl;
}
Triangle::Triangle(int width, int height) : Polygon(width, height)
{
    ;
}
void Triangle::draw()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
Triangle::~Triangle()
{
    cout << "~Triangle() is Called" << endl;
}
int main(void)
{
    int a;
    int b;
    int type;
    cin >> type >> a >> b;

    Polygon *pol;
    if (type == 3)
    {
        pol = new Triangle(a, b);
    }
    else if (type == 4)
    {
        pol = new Rectangle(a, b);
    }
    pol->draw();
    delete pol;
}