#include <bits/stdc++.h>
using namespace std;
class Fraction
{
    bool valid;

public:
    int num, den;
    void simplify()
    {
        if (valid)
        {
            for (int j = 2; j <= den; j++)
            {
                if (num % j == 0 && den % j == 0)
                {
                    num = num / j;
                    den = den / j;
                }
            }
            for (int j = 2; j <= num; j++)
            {
                if (num % j == 0 && den % j == 0)
                {
                    num = num / j;
                    den = den / j;
                }
            }
            if (num % den == 0)
            {
                num = num / den;
                den = den / den;
            }
        }
    }
    Fraction(int n = 1, int d = 1)
    {
        num = n;
        if (d < 1)
        {
            cout << "Invalid Denominator Value" << endl;
            valid = false;
        }
        else
        {
            valid = true;

            den = d;
            simplify();
        }
    };
    Fraction operator+(Fraction f)
    {
        Fraction temp;
        temp.num = (f.den * num) + (den * f.num);
        temp.den = den * f.den;
        temp.simplify();
        return temp;
    }
    Fraction operator-(Fraction f)
    {
        Fraction temp;
        temp.num = (f.den * num) - (den * f.num);
        temp.den = den * f.den;
        temp.simplify();
        return temp;
    }
    Fraction operator*(Fraction f)
    {
        Fraction temp;
        temp.num = num * f.num;
        temp.den = den * f.den;
        temp.simplify();
        return temp;
    }
    Fraction operator/(Fraction f)
    {
        Fraction temp;
        temp.num = num * f.den;
        temp.den = den * f.num;
        temp.simplify();
        return temp;
    }
    bool operator==(Fraction f)
    {
        int a = num * f.den;
        int b = f.num * den;
        return a == b;
    }
    bool operator<=(Fraction f)
    {
        int a = num * f.den;
        int b = f.num * den;
        return a <= b;
    }

    bool operator>=(Fraction f)
    {
        int a = num * f.den;
        int b = f.num * den;
        return a >= b;
    }
    bool operator<(Fraction f)
    {
        int a = num * f.den;
        int b = f.num * den;
        return a < b;
    }
    bool operator>(Fraction f)
    {
        int a = num * f.den;
        int b = f.num * den;
        return a > b;
    }
    void print()
    {
        if (valid)
        {
            cout << num << "/" << den << endl;
        }
    }
};
int main()
{
    int x, y;
    cout << "Enter numerator of A :";
    cin >> x;
    cout << "Enter denominator of A :";
    cin >> y;
    Fraction a(x, y);
    cout << "Enter numerator of B :";
    cin >> x;
    cout << "Enter denominator of B :";
    cin >> y;
    Fraction b(x, y);
    Fraction c;
    c = a + b;
    cout << "Addition :";
    c.print();
    c = a - b;
    cout << "Subtraction :";
    c.print();

    c = a * b;
    cout << "Multiplication :";
    c.print();
    c = a / b;
    cout << "Division :";
    c.print();
    cout << "A == B :";
    cout << (a == b) << endl;
    cout << "A <= B :";
    cout << (a <= b) << endl;
    cout << "A >= B :";
    cout << (a >= b) << endl;
    cout << "A < B :";
    cout << (a < b) << endl;
    cout << "A > B :";
    cout << (a > b) << endl;
    return 0;
}