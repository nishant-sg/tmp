#include <iostream>
#include <string.h>
using namespace std;
class book
{
public:
    char *Title, *Author, *Publisher;
    int Price, Stock;
    static int transaction;
    book()
    {
        Title = new char[2];
        Author = new char[2];
        Publisher = new char[2];
        Price = 0;
        Stock = 0;
    }
    void inputValues();
    void display();
    int search(char str[20]);
    void purchase();
    static void fun()
    {
        cout << "\nNumber of successful transctions=" << transaction;
    }
    void update(book B, float new_price)
    {
        updateValues(B, new_price);
    }

private:
    void updateValues(book B, float new_price)
    {
        B.Price = new_price;
    }
};
int book::transaction;
void book::inputValues()
{
    cout << "Enter the title of book: " << endl;
    cin >> Title;
    cout << "Enter the author of book: " << endl;
    cin >> Author;
    cout << "Enter the publisher of book: " << endl;
    cin >> Publisher;
    cout << "Enter the price of book: " << endl;
    cin >> Price;
    cout << "Enter the stock of book: " << endl;
    cin >> Stock;
}
void book::display()
{
    cout << "\n"
         << Title << "\t" << Author << "\t" << Publisher << "\t" << Price << "\t" << Stock << "\
t"
         << "\n";
}
int book::search(char str[20])
{
    if (strcmp(str, Title) == 0)
        return 1;
    else
        return 0;
}
void book::purchase()
{
    int count;
    cout << "\nEnter the number of books to buy: ";
    cin >> count;
    if (count == Stock)
    {
        Stock = Stock - count;
        cout << "\nAmount: " << (Price * count);
        book::transaction++;
    }
    else
    {
        cout << "\nRequested book unavailable.";
    }
}
int main()
{
    book b1[20], ob;
    int n, i, ch, val;
    char str[20];
    cout << "Enter the number of records:";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        b1[i].inputValues();
    }

    cout << "Book Details:"
         << "\n";
    cout << "Title"
         << "\t"
         << "Author"
         << "\t"
         << "Publisher"
         << "\t"
         << "Price"
         << "\
t"
         << "Stock"
         << "\t";
    for (i = 0; i < n; i++)
    {
        b1[i].display();
    }
    do
    {
        cout << "\n\n1. Insert\n2. Display\n3. Search\n4. Purchase book\n5. Modify price\n6. Sucessful transactions\n7.Exit "<<"\n ";
        cout<< "Enter your choice";
        cin >> ch;
        switch (ch)
        {
        case 1:
            b1[n++].inputValues();
            break;
        case 2:
            cout << "Book Details:"
                 << "\n";
            cout << "Title"
                 << "\t"
                 << "Author"
                 << "\t"
                 << "Publisher"
                 << "\t"
                 << "Price"
                 << "\
t"
                 << "Stock"
                 << "\t";
            for (i = 0; i < n; i++)
                b1[i].display();
            break;
        case 3:
            cout << "\nEnter the title of book:";
            cin >> str;
            for (i = 0; i < n; i++)
            {
                val = b1[i].search(str);
                if (val == 1)
                {
                    cout << "\nBook found";
                    break;
                }
            }
            if (i == n)
            {
                cout << "\nBook not in stock";
            }
            break;
        case 4:
            cout << "\nEnter the title of book:";
            cin >> str;
            for (i = 0; i < n; i++)
            {
                val = b1[i].search(str);
                if (val == 1)
                {
                    b1[i].purchase();
                    break;
                }
            }
            if (i == n)
            {
                cout << "\nBook not in stock";
            }
            break;
        case 5:
            float p;
            cout << "\nEnter the title of book:";
            cin >> str;
            for (i = 0; i < n; i++)
            {
                val = b1[i].search(str);
                if (val == 1)
                {
                    cout << "\nEnter modified price:";
                    cin >> p;
                    b1[i].update(b1[i], p);
                    break;
                }
            }
            if (i == n)
            {
                cout << "\nBook not in stock";
            }
            break;
        case 6:
            book::fun();
            break;
        case 7:
            cout << "Exit";
            break;
        }
    } while (ch < 7);
    return 0;
}