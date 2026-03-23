#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

namespace college
{

    class NegativeMarksException
    {
    private:
        int marks;

    public:
        NegativeMarksException(int marks)
        {
            this->marks = marks;
        }
        void displayMessage()
        {
            cout << "Exception: Negative marks entered (" << marks << ")" << endl;
        }
    };

    class Student
    {
    private:
        int rollNo;
        string name;
        int age;
        int marks;

    public:
        Student(int rollNo, string name, int age)
        {
            this->rollNo = rollNo;
            this->name = name;
            this->age = age;
            this->marks = 0;
        }

        void setRollNo(int rollNo)
        {
            this->rollNo = rollNo;
        }
        void setName(string name)
        {
            this->name = name;
        }
        void setAge(int age)
        {
            this->age = age;
        }
        void setMarks(int marks)
        {
            if (marks < 0)
            {
                throw NegativeMarksException(marks);
            }
            this->marks = marks;
        }

        int getRollNo()
        {
            return rollNo;
        }
        string getName()
        {
            return name;
        }
        int getAge()
        {
            return age;
        }
        int getMarks()
        {
            return marks;
        }

        void display()
        {
            cout << "Student Roll No: " << rollNo << endl;
            cout << "Student Name: " << name << endl;
            cout << "Student Age: " << age << endl;
            cout << "Student Marks: " << marks << endl;
        }
    };

    class Teacher
    {
    private:
        int empId;
        string name;
        string subject;

    public:
        Teacher(int empId, string name, string subject)
        {
            this->empId = empId;
            this->name = name;
            this->subject = subject;
        }

        void setEmpId(int empId)
        {
            this->empId = empId;
        }
        void setName(string name)
        {
            this->name = name;
        }
        void setSubject(string subject)
        {
            this->subject = subject;
        }

        int getEmpId()
        {
            return empId;
        }
        string getName()
        {
            return name;
        }
        string getSubject()
        {
            return subject;
        }

        void display()
        {
            cout << "Teacher ID: " << empId << endl;
            cout << "Teacher Name: " << name << endl;
            cout << "Subject: " << subject << endl;
        }
    };
}

int main()
{
    int rollNo, age, marks;
    string name;

    cout << "Enter student roll no: ";
    cin >> rollNo;
    cout << "Enter student name: ";
    cin >> name;
    cout << "Enter student age: ";
    cin >> age;

    college::Student s1(rollNo, name, age);

    try
    {
        cout << "Enter student marks: ";
        cin >> marks;
        s1.setMarks(marks);
    }
    catch (college::NegativeMarksException &e)
    {
        e.displayMessage();
        exit(0);
    }

    s1.display();

    int empId;
    string tname, subject;
    cout << "\nEnter teacher ID: ";
    cin >> empId;
    cout << "Enter teacher name: ";
    cin >> tname;
    cout << "Enter subject: ";
    cin >> subject;

    college::Teacher t1(empId, tname, subject);
    t1.display();

    return 0;
}
