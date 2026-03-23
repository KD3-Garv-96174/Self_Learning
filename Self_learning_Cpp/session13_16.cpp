#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    int rollNo;
    string name;
    int age;

public:
    Student() : rollNo(0), name(""), age(0) {}
    void setRollNo(int rollNo) { this->rollNo = rollNo; }
    void setName(string name) { this->name = name; }
    void setAge(int age) { this->age = age; }
    void display()
    {
        cout << "Student Roll No: " << rollNo << endl;
        cout << "Student Name: " << name << endl;
        cout << "Student Age: " << age << endl;
    }
};

template <typename T>
class SmartPointer
{
    T *ptr;

public:
    SmartPointer(T *p = nullptr) : ptr(p) {}
    ~SmartPointer() { delete ptr; }
    T *operator->() { return ptr; }
};

int main()
{
    try
    {
        SmartPointer<Student> s(new Student);

        int rollNo, age;
        string name;
        cout << "Enter roll no: ";
        cin >> rollNo;
        if (rollNo < 0)
            throw string("Invalid roll number");

        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
        if (age < 0)
            throw string("Invalid age");

        s->setRollNo(rollNo);
        s->setName(name);
        s->setAge(age);

        s->display();
    }
    catch (string &msg)
    {
        cout << "Exception: " << msg << endl;
        exit(0);
    }
    catch (...)
    {
        cout << "invalid input" << endl;
        exit(0);
    }
    return 0;
}
