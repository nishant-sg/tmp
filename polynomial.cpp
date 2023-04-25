#include <iostream>
// #include<coefficientnio.h>
#include <string.h>
#include <math.h>
using namespace std;
#define SIZE 10

class polynomial
{
public:
    int coefficient[SIZE];
    int degree;

public:
    polynomial()
    {
        for (int i = 0; i < SIZE; i++)

        {
            coefficient[i] = 0;
        }
    }
    void getvalues()
    {
        cout << "Enter highest value of exponent of x : ";
        cin >> degree;
        for (int i = degree; i >= 0; i--)
        {
            cout << "Enter value of coefficient x^" << i << ": ";
            cin >> coefficient[i];
        }
        for (int i = degree + 1; i < SIZE; i++)
        {
            coefficient[i] = 0;
        }
    }

    polynomial operator+(polynomial);
    polynomial operator-(polynomial);
    polynomial operator*(polynomial);
    polynomial operator+=(polynomial);
    polynomial operator-=(polynomial);
    polynomial operator*=(polynomial);

    void print(int i = 4)
    {

        for (i = degree; i >= 0; i--)
        {
            cout << coefficient[i] << "x^" << i;
            if (i != 0)
            {
                cout << "+ ";
            }
        }
        cout << endl
             << endl;
    }
};

polynomial polynomial ::operator+(polynomial P2)
{
    int t = max(degree, P2.degree);
    for (int i = 0; i <= t; i++)
    {
        P2.coefficient[i] += coefficient[i];
    }
    return P2;
}

polynomial polynomial ::operator-(polynomial P2)
{
    polynomial P3;
    int t = max(degree, P2.degree);
    for (int i = 0; i <= t; i++)
    {
        P3.coefficient[i] = coefficient[i] - P2.coefficient[i];
    }
    P3.degree = t;
    return P3;
}

polynomial polynomial ::operator*(polynomial P2)
{
    polynomial P3;
    int t = max(degree, P2.degree);
    for (int i = 0; i <= t; i++)
    {

        for (int j = 0; j <= P2.degree; j++)
        {
            P3.coefficient[i + j] += coefficient[i] * P2.coefficient[j];
            P3.degree = max(i + j, P3.degree);
        }
    }

    return P3;
}

polynomial polynomial ::operator+=(polynomial P2)
{
    polynomial P3;

    int t = max(degree, P2.degree);
    for (int i = 0; i <= t; i++)
    {
        P3.coefficient[i] = coefficient[i] + P2.coefficient[i];
        coefficient[i] = P3.coefficient[i];
    }

    return P3;
}

polynomial polynomial ::operator-=(polynomial P2)
{
    polynomial P3;
    int t = max(degree, P2.degree);
    for (int i = 0; i <= t; i++)
    {
        P3.coefficient[i] = coefficient[i] - P2.coefficient[i];
        coefficient[i] = P3.coefficient[i];
    }
    P3.degree = t;

    return P3;
}

polynomial polynomial ::operator*=(polynomial P2)
{
    polynomial P3;
    int t = max(degree, P2.degree);
    for (int i = 0; i <= t; i++)
    {
        for (int j = 0; j <= 4; j++)
        {
            P3.coefficient[i + j] += coefficient[i] * P2.coefficient[j];
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        coefficient[i] = P3.coefficient[i];
    }
    P3.degree = t;

    return P3;
}

int main()
{
    polynomial P1, P2, P3;
    P1.getvalues();
    P2.getvalues();

    cout << "Polynomial 1 is : \n";
    P1.print();
    cout << "Polynomial 2 is : \n";
    P2.print();
    P3 = P1 + P2;
    cout << "Addition of two Polynomial is \n";

    P3.print();
    P3 = P1 - P2;
    cout << "Subtraction of two polynomial is \n";
    P3.print();
    P3 = P1 * P2;
    cout << endl
         << "Multiplication of two polynomial is \n";
    P3.print();
    return 0;
}