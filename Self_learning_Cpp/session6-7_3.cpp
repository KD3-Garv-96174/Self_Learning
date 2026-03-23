#include <iostream>
using namespace std;

class Student
{
private:
    int rollNo;
    double marks;

public:
    void acceptRecord()
    {
        cout << "enter rollNo : " << endl;
        cin >> this->rollNo;
        cout << "enter marks : " << endl;
        cin >> this->marks;
    }
    void printRecord(void)
    {
        cout << "Roll : " << rollNo << endl;
        cout << "Marks : " << marks << endl;
    }
    int getRollNo(){
       return this->rollNo;
    }
    int getMarks(){
       return this->marks;
    }
};
int main()
{
    int n;
    cout << "enter no. of students : " << endl;
    cin >> n;
    Student *arr = new Student[n];
    for (int i = 0; i < n; i++)
    {
        arr[i].acceptRecord();
    }
    for (int i = 0; i < n; i++)
    {
        arr[i].printRecord();
    }
    double highest = arr[0].getMarks();
    int topRoll = arr[0].getRollNo();

    for (int i = 1; i < n; i++)
    {
        if (arr[i].getMarks() > highest)
        {
            highest = arr[i].getMarks();
            topRoll = arr[i].getRollNo();
        }
    }

    cout << "\nHighest Marks: " << highest<< " (Roll No: " << topRoll << ")" << endl;

    delete[] arr;
    arr = NULL;
    return 0;
};