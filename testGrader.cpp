#include <iostream>
#include <string>
#include "testgrader.cpp"
using namespace std;
int main()
{
    string solution[20] = {"B", "D", "A", "A", "C", "A", "B", "A", "C", "D", "B", "C", "D", "A", "D",
                           "C", "C", "B", "D", "A"};
    TestGrader test;
    test.setKey(solution);

    string answer[20];
    int choice;
    do
    {
        for (int x = 0; x < 20; x++)
        {
            cout << "Enter the answer for question " << x + 1 << ": ";
            cin >> answer[x];

            while (answer[x] > "D" || answer[x] < "A")
            {
                cout << "Please enter from A-D: ";
                cin >> answer[x];
            }
        }
        test.grade(answer);
        cout << endl
             << "Enter 0 to quit, else enter any number to retake the test: ";
        cin >> choice;
    } while (choice != 0);

    return 0;
}

testgrader.h
#include <string>
    using namespace std;
class TestGrader
{
private:
    string answer[20];

public:
    void setKey(string[]);
    void grade(string[]) const;
};

testgrader.cpp
#include <iostream>
#include "testgrader.h"
    using namespace std;
void TestGrader::setKey(string correct[])
{
    for (int x = 0; x < 20; x++)
    {
        answer[x] = correct[x];
    }
}
void TestGrader::grade(string test[]) const
{
    int right = 0;
    int wrong = 0;
    int count = 0;

    for (int x = 0; x < 20; x++)
    {
        if (test[x] == answer[x])
        {
            right += 1;
        }
        else if (test[x] != answer[x])
        {
            wrong += 1;
        }
    }
    if (right >= 15)
    {
        cout << "Congratulations you have passed the driver's license exam" << endl;
    }
    else
    {
        cout << "You failed the driver's license exam" << endl;
    }
    cout << "You got a total of " << right << " right answers and a total of " << wrong << "
        wrong answers in the test " << endl;
        cout
         << "You got questions ";
    for (int x = 0; x < 20; x++)
    {
        if (test[x] != answer[x])
        {
            cout << x + 1 << " ";
        }
    }
    cout << "wrong" << endl;
}