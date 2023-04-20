#include <iostream>
#include <vector>
using namespace std;
class CarbonFootprint
{
public:
    virtual float getCarbonFootprint() = 0;
};
class Building : public CarbonFootprint
{
    float area;
    float people;

public:
    Building(float a, float n)
    {
        area = a;
        people = n;
    }
    float getCarbonFootprint()
    {
        float carbonFootprint = area * 50 + people * 10;
        return carbonFootprint;
    }
};
class Car : public CarbonFootprint
{
private:
    string company;
    string model;

    float milleage;
    float totalDistance;

public:
    Car(string mk, string mdl, float m, float km)
    {
        company = mk;
        model = mdl;
        milleage = m;
        totalDistance = km;
    }
    float getCarbonFootprint()
    {
        float carbonFootprint = totalDistance / milleage * 19.4;
        return carbonFootprint;
    }
};
class Bicycle : public CarbonFootprint
{
private:
    string company;
    bool electric;

public:
    Bicycle(string company, bool isElectric)
    {
        company = company;
        electric = isElectric;
    }
    float getCarbonFootprint()
    {
        float carbonFootprint = electric ? 0.0 : 22.0;
        return carbonFootprint;
    }
};
int main()
{
    vector<CarbonFootprint *> objects;

    objects.push_back(new Building(500.0, 10));
    objects.push_back(new Car("Honda", "City", 35.0, 10000.0));
    objects.push_back(new Bicycle("FireFox", false));
    objects.push_back(new Bicycle("Electric", false));
    cout << "Folowing are the carbon footprints of the objects" << endl;
    for (int i = 0; i < objects.size(); i++)
    {
        cout << "Carbon footprint :" << objects[i]->getCarbonFootprint()

             << " lbs CO2e\n\n";
    }
    return 0;
}