#include <iostream>
#include <string>
using namespace std;
class bankAccount
{
    string Name;
    int accountNumber;
    string accountType;
    int balance;

public:
    void initialize(string N, int num, string type, int bal)
    {
        Name = N;
        num = accountNumber;
        accountType = type;
        balance = bal;
        cout << "Initialized values succesfully..." << endl;
    }
    void deposit(int amt)
    {
        balance += amt;
        cout << "Money Deposited succesfully..." << endl;
    }
    void withdraw(int amt)
    {
        if (balance >= amt)
        {

            balance -= amt;
            cout << "Remaining Balance :" << balance << endl;
        }
        else
        {
            printf("Unsufficient Balance \n");
        }
    }
    void display()
    {
        printf("Name - %s \nBalance - %d\n", Name.c_str(), balance);
    }
};
int main()
{
    bankAccount A, B;
    A.initialize("Nishant", 23, "Savings", 10000);
    B.initialize("Lakshya", 24, "Savings", 10000);
    A.display();
    A.withdraw(23333);
    A.display();
    A.deposit(15000);
    A.display();
    B.display();
    return 0;
}