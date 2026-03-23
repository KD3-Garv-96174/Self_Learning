#include <iostream>
using namespace std;

void swapByValue(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}
void swapByReference(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main()
{
    int num1 = 10;
    int num2 = 20;
    cout << "Before swapByValue: ";
    cout << num1 << " " << num2 << endl;
    swapByValue(num1, num2);
    cout << "After swapByValue: ";
    cout << num1 << " " << num2 << endl;
    cout << "\nBefore swapByReference: ";
    cout << num1 << " " << num2 << endl;
    swapByReference(num1 , num2);
    cout << "After swapByReference: ";
    cout << num1 << " " << num2 << endl;
    return 0;
}