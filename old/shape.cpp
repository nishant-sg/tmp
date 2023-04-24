#include <iostream>
#include <vector>
using namespace std;
class Shape
{
public:
    virtual float getCost()
    {
        return 5.0f;
    };
};
class Square : public Shape
{
    float side;
    float rate = 50.0;

public:
    Square(int x)
    {
        side = x;
    }
    float getCost()
    {
        return side * side * rate;
    }
};
class Circle : public Shape
{
    float radius;
    float rate = 100.0;

public:
    Circle(int x)
    {
        radius = x;
    }
    float getCost()
    {
        return 3.14 * radius * radius * rate;
    }
};
class Triangle : public Shape
{
    float rate = 75.0;
    int width;
    int height;

public:
    Triangle(int x, int y)
    {
        width = x;
        height = y;
    }
    float getCost()
    {
        return 0.5 * width * height * rate;
    }
};
class Rectangle : public Shape
{
    float rate = 50.0;
    int width;
    int height;

public:
    Rectangle(int x, int y)
    {
        width = x;
        height = y;
    }
    float getCost()
    {
        return height * width * rate;
    }
};
class Custom : public Shape
{
    float rate = 50.0;
    int area;

public:
    Custom(int x, int y)
    {

        area = x;
        rate = y;
    }
    float getCost()
    {
        return area * rate;
    }
};
class Order
{
    vector<Shape *> order;
    float Ordercost;

public:
    void addShape(Shape *s)
    {
        if (order.size() > 5)
        {
            cout << "Maximum orderlimit reached" << endl;
        }
        else
        {
            order.push_back(s);
        }
    }
    float getOrderCost()
    {
        float total = 0.0;
        for (int i = 0; i < order.size(); i++)
        {
            float cost = order[i]->getCost();
            // cout << cost << endl;
            Ordercost += cost;
        }
        return Ordercost;
    }
};

int main()
{
    // Triangle s(3, 5);
    // Triangle c(3, 5);
    // Order o;
    // o.addShape(new Triangle(3, 5));
    // o.addShape(new Rectangle(3, 5));
    // o.addShape(new Circle(3));
    // o.addShape(new Square(5));
    // o.addShape(c);
    vector<Order> orders;
    int t = 0;
    int i = 0;
    bool mO = true;
    while (i < 6 and mO == 1)
    {
        bool dO = true;
        int c;
        Order o;
        while (dO == 1)
        {
            cout << "Press 1 for triangle,2 for square, 3 for rectanlge, 4 for circle and 5 for custom shape" << endl;

            cin >> c;
            if (c == 1)
            {
                int length, width;
                cout << "Enter the length of the triangle" << endl;
                cin >> length;
                cout << "Enter the width of the triangle" << endl;
                cin >> width;
                o.addShape(new Triangle(length, width));
            }
            else if (c == 2)
            {
                int side, width;
                cout << "Enter the side of the square" << endl;
                cin >> side;
                o.addShape(new Square(side));
            }
            else if (c == 3)
            {
                int length, width;
                cout << "Enter the length of the rectangle" << endl;
                cin >> length;
                cout << "Enter the width of the rectangle" << endl;
                cin >> width;
                o.addShape(new Rectangle(length, width));
            }
            else if (c == 4)
            {
                int radius;
                cout << "Enter the radius of the circle" << endl;
                cin >> radius;
                o.addShape(new Circle(radius));
            }
            else if (c == 5)
            {
                int area, rate;
                cout << "Enter the area of the custom shape" << endl;
                cin >> area;
                cout << "Enter the rate of the custom shape" << endl;
                cin >> rate;
                o.addShape(new Custom(area, rate));
            }
            cout << "Do you want to add another shape?" << endl;
            cin >> dO;
        }
        cout << "Total cost of the order is " << endl;
        t += o.getOrderCost();
        cout << o.getOrderCost() << endl;
        orders.push_back(o);
        i++;
        cout << "Do you want to add another order?" << endl;
        cin >> mO;
    }
    cout << "Total cost of all order is " << t << endl;
    return 0;
}