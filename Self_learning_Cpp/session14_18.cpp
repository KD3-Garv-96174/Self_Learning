#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
class Array
{
    T *data;
    int size;

public:
    Array(int n = 0) : size(n) { data = (n > 0) ? new T[n] : nullptr; }
    ~Array() { delete[] data; }

    Array(const Array &other) : size(other.size)
    {
        data = new T[size];
        for (int i = 0; i < size; i++)
            data[i] = other.data[i];
    }

    Array &operator=(const Array &other)
    {
        if (this != &other)
        {
            delete[] data;
            size = other.size;
            data = new T[size];
            for (int i = 0; i < size; i++)
                data[i] = other.data[i];
        }
        return *this;
    }

    T &operator[](int i)
    {
        if (i < 0 || i >= size)
        {
            cout << "Index out of bounds" << endl;
            exit(0);
        }
        return data[i];
    }

    int getSize() { return size; }
    void display()
    {
        for (int i = 0; i < size; i++)
            cout << data[i] << " ";
        cout << endl;
    }
};

int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;
    Array<int> arr(n);

    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Array elements: ";
    arr.display();

    Array<int> arr2 = arr; 
    cout << "Copied array: ";
    arr2.display();
}
