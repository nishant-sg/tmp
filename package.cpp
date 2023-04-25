#include <bits/stdc++.h>
#include <string.h>
using namespace std;
class Package
{
    string Sname;
    string Saddress;
    string Scity;
    int Szipcode;
    string Rname;
    string Raddress;
    string Rcity;
    int Rzipcode;
    double weight;
    double cost;

public:
    Package(double w = 1, double c = 1, string sn = "DefaultSender", string rn = "DefaultReciever", string sa = "DefaultSenderAddress", string ra = "DefaultRecieverAdress", string sc = "DefaultCity", string rc = "DefaultCity", int rz = 1234,
            int sz = 1234)
    {
        Sname = sn;
        Saddress = sa;
        Scity = sc;
        Szipcode = sz;
        Rname = rn;
        Raddress = rc;
        Rcity = ra;
        Rzipcode = rz;
        if (w > 0 && c > 0)
        {
            weight = w;
            cost = c;
        }
        else
        {
            cout << "Invalid Values for weight and cost" << endl;
            return;
        }
    };
    void setWeight(double w)
    {
        if (w > 0)
        {
            weight = w;
        }
    }
    void setCost(double c)
    {
        if (c > 0)
        {
            cost = c;
        }
    }
    double getWeight()
    {
        return weight;
    }
    double getCost()
    {
        return cost;
    }
    double calculateCost()
    {
        return weight * cost;
    }
    void printDetails()
    {
        cout << "Sender name is : " << Sname << endl;
        cout << "Sender address is : " << Saddress << endl;
        cout << "Sender city is : " << Scity << endl;
        cout << "Sender zipcode is : " << Szipcode << endl;
        cout << "Reciever name is : " << Rname << endl;
        cout << "Reciever address is : " << Raddress << endl;
        cout << "Reciever city is : " << Rcity << endl;
        cout << "Reciever zipcode is : " << Rzipcode << endl;
    }
};
class TwoDayPackage : public Package
{
    double fee;

public:
    TwoDayPackage(double w, double c, double f)
    {
        setWeight(w);

        setCost(c);
        fee = f;
    };
    TwoDayPackage(double f)
    {
        fee = f;
    };
    double calculateCost()
    {
        int w = getWeight();
        int c = getCost();
        return (w * c) + fee;
    }
};
class OvernightPackage : public Package
{
    double fee;

public:
    OvernightPackage(double w, double c, double f)
    {
        setWeight(w);
        setCost(c);
        fee = f;
    };
    OvernightPackage(double f)
    {
        fee = f;
    };
    double calculateCost()
    {
        int w = getWeight();
        int c = getCost();
        return (w * c) + fee;
    }
};
int main()
{
    double x, y, f1, f2;
    cout << "Enter the weight of the package in ounces :";
    cin >> x;
    cout << "Enter the cost per ounce :";
    cin >> y;
    cout << "Enter additional fee for 2 day package:";
    cin >> f1;
    cout << "Enter additional fee for overnight package :";
    cin >> f2;
    cout << endl;
    Package a(x, y);

    TwoDayPackage b(x, y, f1);
    OvernightPackage c(x, y, f2);
    cout << "Normal package delivery cost :" << a.calculateCost() << endl;
    cout << "Two day package delivery cost :" << b.calculateCost() << endl;
    cout << "Overnight package delivery cost :" << c.calculateCost() << endl;
    // c.printDetails();
    return 0;
}