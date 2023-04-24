#include <iostream>
using namespace std;
class box
{
    int width;

public:
    void setWidth(int num)
    {
        width = num;
        cout << "Set Width ..." << endl;
    }
    void printWidth();
};
void box::printWidth()
{
    cout << "The width is: " << width << endl;
}
int main()
{
    box A, B;
    A.setWidth(50);
    A.printWidth();
    B.setWidth(10);
    B.printWidth();
    return 0;
}
