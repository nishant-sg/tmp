#include <iostream>
#include <string.h>
using namespace std;

class pizza
{
public:
    virtual int cost(int size) = 0;
    virtual int cost(double size) = 0;
};

class RegularPizza : public pizza
{
public:
    int extracost = 10;
    void details()
    {
        cout << "This is a regular pizza" << endl;
    }
    int cost(int size)
    {
        cout << "Size of pizza is -" << size << endl;
        return size * extracost;
    }
    int cost(double size)
    {
        cout << "Size of pizza is -" << size << endl;
        return (size * extracost) + int(size);
    }
};

class VegiterianPizza : public pizza
{
public:
    int extracost = 20;
    void details()
    {
        cout << "This is a Vegitarian pizza" << endl;
    }
    int cost(int size)
    {
        cout << "Size of pizza is -" << size << endl;
        return size * extracost;
    }
    int cost(double size)
    {
        cout << "Size of pizza is -" << size << endl;
        return size * extracost + int(size / 10);
    }
};

class MeatLoversPizza : public pizza
{
public:
    int extracost = 30;
    void details()
    {
        cout << "This is a MeatLovers pizza" << endl;
    }
    int cost(int size)
    {
        cout << "Size of pizza is -" << size << endl;
        return size * extracost;
    }
    int cost(double size)
    {
        cout << "Size of pizza is -" << size << endl;
        return size * extracost + int(size / 10);
    }
};

int main()
{

    RegularPizza p1;
    RegularPizza p2;
    VegiterianPizza p3;
    MeatLoversPizza p4;

    p1.details();
    cout << p1.cost(10) << endl;
    p1.details();
    cout << p1.cost(15.5) << endl;
    p2.details();
    cout << p2.cost(10) << endl;
    p3.details();
    cout << p3.cost(10) << endl;
    p4.details();
    cout << p4.cost(10) << endl;
}