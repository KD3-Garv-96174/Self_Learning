#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

class Student
{
    int rollNo, age, marks;
    string name;

public:
    Student(int r = 0, string n = "", int a = 0, int m = 0) : rollNo(r), name(n), age(a), marks(m) {}
    void setRollNo(int r) { rollNo = r; }
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setMarks(int m)
    {
        if (m < 0)
        {
            cout << "Exception: Negative marks (" << m << ")" << endl;
            exit(0);
        }
        marks = m;
    }
    void display() { cout << "Roll No: " << rollNo << "\nName: " << name << "\nAge: " << age << "\nMarks: " << marks << endl; }
    void save(const string &file)
    {
        ofstream out(file);
        if (!out)
        {
            cout << "File error!" << endl;
            exit(0);
        }
        out << rollNo << " " << name << " " << age << " " << marks;
    }
    void load(const string &file)
    {
        ifstream in(file);
        if (!in)
        {
            cout << "File error!" << endl;
            exit(0);
        }
        in >> rollNo >> name >> age >> marks;
    }
};

int main()
{
    int rollNo, age, marks;
    string name;
    cout << "Enter roll no: ";
    cin >> rollNo;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter marks: ";
    cin >> marks;

    Student s1;
    s1.setRollNo(rollNo);
    s1.setName(name);
    s1.setAge(age);
    s1.setMarks(marks);
    s1.save("student.txt");

    Student s2;
    s2.load("student.txt");
    cout << "\nLoaded Student:\n";
    s2.display();
}
