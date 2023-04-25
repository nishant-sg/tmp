#include <cstring>
#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
class Employee
{
private:
    char *myName_p;

public:
    Employee(const char *name)
    {
        myName_p = (new char[strlen(name) + 1]);
        strcpy(myName_p, name);
        cout << "Employee created with name: " << myName_p << endl;
    }
    ~Employee()
    {
        delete[] myName_p;
    }
    void display() const
    {
        cout << "Employee name: " << myName_p << endl;
    }
};

class Company
{
private:
    char *name_p;
    Employee *myEmp_p;

public:
    Company(const char *name)
    {
        name_p = new char[strlen(name) + 1];
        myEmp_p = nullptr;
        strcpy(name_p, name);
        cout << "Company established with name: " << name_p << endl;
    }
    ~Company()
    {
        cout << "Company with name: " << name_p << " destroyed ." << endl;
        delete[] name_p;
    }
    void setEmployee(Employee *emp)
    {
        myEmp_p = emp;
        cout << "New Employee added: " << myEmp_p << endl;
    }
    void displayEmployees() const
    {
        if (myEmp_p != nullptr)
        {
            cout << "Employees associated with the company " << name_p << ":" << endl;
            myEmp_p->display();
        }
    }
};

int main()
{
    Employee emp1("Snehal");

    Employee emp2("Nishant");
    Company comp("OOAD LAB");
    cout << endl;
    comp.setEmployee(&emp1);
    comp.setEmployee(&emp2);
    comp.displayEmployees();
    cout << endl;
    comp.~Company();
    cout << endl;
    emp1.display();
    emp2.display();
    return 0;
}