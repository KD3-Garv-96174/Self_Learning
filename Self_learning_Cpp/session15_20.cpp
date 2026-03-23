#include <iostream>
#include <memory>
using namespace std;

class Student
{
    int rollNo;

public:
    Student(int r) : rollNo(r) { cout << "Student " << rollNo << " created\n"; }
    ~Student() { cout << "Student " << rollNo << " destroyed\n"; }
    void display() { cout << "Roll No: " << rollNo << "\n"; }
};

int main()
{
    unique_ptr<Student> u1 = make_unique<Student>(101);
    u1->display();
    unique_ptr<Student> u2 = move(u1);
    if (!u1)
        cout << "u1 no longer owns\n";
    u2->display();

    shared_ptr<Student> s1 = make_shared<Student>(202);
    shared_ptr<Student> s2 = s1;
    cout << "Shared count: " << s1.use_count() << "\n";
    s2->display();

    weak_ptr<Student> w = s1;
    if (auto sp = w.lock())
    {
        cout << "Weak pointer locked\n";
        sp->display();
    }
    cout << "Shared count still: " << s1.use_count() << "\n";

    return 0;
}
