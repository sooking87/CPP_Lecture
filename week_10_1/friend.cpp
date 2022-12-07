#include <iostream>
using namespace std;

class CRectangle
{
    int width, height;

public:
    void set_values(int, int);
    int area()
    {
        return width * height;
    }
    int getWidth();
    int getHeight();
    friend CRectangle duplicate(CRectangle);
};

void CRectangle::set_values(int a, int b)
{
    width = a;
    height = b;
}
int CRectangle::getWidth()
{
    return width;
}
int CRectangle::getHeight()
{
    return height;
}

CRectangle duplicate(CRectangle rectparam)
{
    CRectangle rectres;
    cout << "width: " << rectparam.getWidth() << endl;
    cout << "height: " << rectparam.getHeight() << endl;
    rectres.width = rectparam.width * 2;
    rectres.height = rectparam.height * 2;
    return rectres;
}

int main()
{
    CRectangle rect, rectb;
    rect.set_values(2, 3);
    rectb = duplicate(rect);
    cout << rectb.area();
    return 0;
}