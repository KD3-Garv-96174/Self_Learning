#include <iostream>
using namespace std;

namespace college
{
    class Student
    {
    private:
        string name;
        int rollNo;

    public:
        Student(string name, int rollNo) : name(name), rollNo(rollNo) {}

        string getName()
        {
            return name;
        }
        int getRollNo()
        {
            return rollNo;
        }

        void setName(string name)
        {
            this->name = name;
        }
        void setRollNo(int rollNo)
        {
            this->rollNo = rollNo;
        }

        void display()
        {
            cout << "[Student] Name: " << name << ", Roll No: " << rollNo << endl;
        }
    };

    class Teacher
    {
    private:
        string name;
        string subject;

    public:
        Teacher(string name, string subject) : name(name), subject(subject) {}

        string getName()
        {
            return name;
        }
        string getSubject()
        {
            return subject;
        }

        void setName(string name)
        {
            this->name = name;
        }
        void setSubject(string subject)
        {
            this->subject = subject;
        }

        void display()
        {
            cout << "[Teacher] Name: " << name << ", Subject: " << subject << endl;
        }
    };
}

int main()
{
    college::Student s1("garv", 101);
    college::Teacher t1("harsh", "cpp");
    std::cout << "--- Initial Details ---" << endl;
    s1.display();
    t1.display();
    s1.setName("anand");
    t1.setSubject("java");
    cout << "\nUpdated Student Name: " << s1.getName() << endl;
    cout << "\n--- Updated Details ---" << endl;
    s1.display();
    t1.display();

    return 0;
}
