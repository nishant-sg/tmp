#include <iostream>
#include "rectangle.cpp"
using namespace std;
int main()
{
    float c1x;
    float c1y;
    float c2x;
    float c2y;
    float c3x;
    float c3y;
    float c4x;
    float c4y;
    cout << "Enter Coordinates of first point: " << endl;
    cout << "x :";
    cin >> c1x;
    cout << "y :";
    cin >> c1y;
    cout << endl;

    cout << "Enter Coordinates of second point: " << endl;
    cout << "x :";
    cin >> c2x;
    cout << "y :";
    cin >> c2y;
    cout << endl;
    cout << "Enter Coordinates of third point: " << endl;
    cout << "x :";
    cin >> c3x;
    cout << "y :";
    cin >> c3y;
    cout << endl;

    cout << "Enter Coordinates of fourth point: " << endl;
    cout << "x :";
    cin >> c4x;
    cout << "y :";
    cin >> c4y;
    cout << endl;
    Rectangle R(c1x, c1y, c2x, c2y, c3x, c3y, c4x, c4y);
    float w = R.getWidth();
    float h = R.getLength();
    cout << "The height of the rectangle is :" << h << endl;
    cout << "The width of the rectangle is :" << w << endl;
    if (R.isSquare())
    {
        cout << "The given rectangle is actually a square" << endl;
    }
    else
    {
        cout << "The given rectangle is not a square" << endl;
    }
    return 0;
}

rectangle.h class Rectangle
{
private:
    float length;
    float width;
    float c1x;
    float c1y;
    float c2x;
    float c2y;
    float c3x;
    float c3y;
    float c4x;
    float c4y;

public:
    Rectangle(float c1x, float c1y, float c2x, float c2y, float c3x, float c3y, float c4x, float c4y);
    void setWidth(float w);
    void setLength(float l);
    void setCoordinates(float c1x, float c1y, float c2x, float c2y, float c3x, float c3y, float c4x, float c4y);
    bool isSquare() const;
    float getWidth() const;
    float getLength() const;
    float perimeter() const;
    float area() const;
};

rectangle.cpp
#include "rectangle.h"
    using namespace std;
Rectangle::Rectangle(float c1x, float c1y, float c2x, float c2y, float c3x, float c3y, float c4x,
                     float c4y)
{
    setCoordinates(c1x, c1y, c2x, c2y, c3x, c3y, c4x, c4y);
}
void Rectangle::setCoordinates(float c1x, float c1y, float c2x, float c2y, float c3x, float c3y,
                               float c4x, float c4y)
{
    c1x = c1x;
    c1y = c1y;
    c2x = c2x;
    c2y = c2y;
    c3x = c3x;
    c3y = c3y;
    c4x = c4x;
    c4y = c4y;
    // cout << c1x << " " << c1y <<" " <<c2x << " " <<c2y <<" " <<c3x <<" " << c3y
    << " " << c4x << " " << c4y << endl;
    if (c1x > 20.0 or c1x < 0.0 or c1y > 20.0 or c1y < 0)
    {
        cout << "Entered invalid first coordinate";
    }
    if (c2x > 20.0 or c2x < 0.0 or c2y > 20.0 or c2y < 0)
    {
        cout << "Entered invalid second coordinate";
    }
    if (c3x > 20.0 or c3x < 0.0 or c3y > 20.0 or c3y < 0)
    {
        cout << "Entered invalid third coordinate";
    }
    if (c4x > 20.0 or c4x < 0.0 or c4y > 20.0 or c4y < 0)
    {
        cout << "Entered invalid fourth coordinate";
    }
    if (c1y == c2y)
    {
        length = c1x > c2x ? c1x - c2x : c2x - c1x;
    }
    else if (c1y == c3y)
    {
        length = c1x > c3x ? c1x - c3x : c3x - c1x;
    }
    else if (c1y == c4y)
    {

        length = c1x > c4x ? c1x - c4x : c4x - c1x;
    }
    if (c1x == c2x)
    {
        width = c1y > c2y ? c1y - c2y : c2y - c1y;
    }
    else if (c1x == c3x)
    {
        width = c1y > c2y ? c1y - c2y : c2y - c1y;
    }
    else if (c1x == c4x)
    {
        width = c1y > c4y ? c1y - c4y : c4y - c1y;
    }
    if (length < width)
    {
        float tmp = length;
        length = width;
        width = tmp;
    }
}
void Rectangle::setWidth(float w)
{
    width = w > 0 && w < 20.0 ? w : 1.0;
}
void Rectangle::setLength(float l)
{
    length = l > 0 && l < 20.0 ? l : 1.0;
}
float Rectangle::getWidth() const
{
    return width;
}
float Rectangle::getLength() const
{
    return length;
}
float Rectangle::perimeter() const
{
    return 2 * (width + length);
}
float Rectangle::area() const
{
    return width * length;
}

bool Rectangle::isSquare() const
{
    return (length == width) ? true : false;
}