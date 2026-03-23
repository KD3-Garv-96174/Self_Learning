#include <iostream>
using namespace std;

class Programmer {
public:
    Programmer() {
        cout << "Programmer constructor called" << endl;
    }
    void work() {
        cout << "Programmer Working Function called" << endl;
    }
};

class Teacher {
public:
    Teacher() {
        cout << "Teacher constructor called" << endl;
    }
    void work() {
        cout << "Teacher Working Function called" << endl;
    }
};


class ProgrammingTeacher : public Programmer, public Teacher {
public:
    ProgrammingTeacher() {
        cout << "ProgrammingTeacher constructor called" << endl;
    }
};

int main() {
    ProgrammingTeacher pt;
    // pt.work(); ambiguity
    cout << "\n--- Resolving Ambiguity ---" << endl;
    pt.Programmer::work();
    pt.Teacher::work();

    return 0;
}
