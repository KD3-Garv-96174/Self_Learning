#include <iostream>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));
    list<int> numbers;

    for (int i = 0; i < 10; i++)
        numbers.push_back(rand() % 100);

    cout << "Original list: ";
    for (auto it = numbers.begin(); it != numbers.end(); ++it)
        cout << *it << " ";
    cout << "\n";

    cout << "Reverse order: ";
    for (auto rit = numbers.rbegin(); rit != numbers.rend(); ++rit)
        cout << *rit << " ";
    cout << "\n";

    for (auto it = numbers.begin(); it != numbers.end(); ++it)
        *it += 5;

    cout << "After increment (+5): ";
    for (list<int>::const_iterator cit = numbers.begin(); cit != numbers.end(); ++cit)
        cout << *cit << " ";
    cout << "\n";

    numbers.sort();

    cout << "Sorted list: ";
    for (auto it = numbers.begin(); it != numbers.end(); ++it)
        cout << *it << " ";
    cout << "\n";

    return 0;
}
