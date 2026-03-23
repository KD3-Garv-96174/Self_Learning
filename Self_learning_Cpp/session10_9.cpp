#include <iostream>
using namespace std;


class Person
{
protected:
    string name;
    int age;

public:
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    void display()
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    virtual void work() = 0;
};


class Student : public Person
{
private:
    int marks;

public:
    Student(string name, int age, int marks)
        : Person(name, age)
    {
        this->marks = marks;
    }

    void study()
    {
        cout << name << " is studying." << endl;
    }

    void work() 
    {
        cout << name << " studies and scores " << marks << " marks." << endl;
    }
};


class Teacher : public Person
{
private:
    double salary;

public:
    Teacher(string name, int age, double salary)
        : Person(name, age)
    {
        this->salary = salary;
    }

    void teach()
    {
        cout << name << " is teaching." << endl;
    }

    void work()
    {
        cout << name << " teaches and earns " << salary << " salary." << endl;
    }
};


int main()
{
    Person* person1;
    Person* person2;

    Student s1("Rahul", 20, 85);
    Teacher t1("Sharma", 45, 50000);

    person1 = &s1;
    person2 = &t1;

    person1->display();
    person1->work(); 

    cout << endl;

    person2->display();
    person2->work();  

    return 0;
}