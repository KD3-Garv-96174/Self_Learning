#include <iostream>
using namespace std;

inline int factorial(int a)
{
    if (a == 0 || a == 1)
    {
        return 1;
    }
    return a * factorial(a - 1);
}
inline int power(int base, int pow)
{
    if (pow == 0)
    {
        return 1;
    }
    return base * power(base, pow - 1);
}

int main()
{
    int fact, num = 5;
    int base = 2 , pow = 3 , result;
    fact = factorial(num);
    cout << "factorial : " << fact<<endl;
    result = power(base , pow);
    cout << "calculated power : " << result;
}