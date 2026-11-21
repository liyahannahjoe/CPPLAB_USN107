#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
public:
    Person(string n = "Unknown") : name(n) { cout << "Person ctor\n"; }
    void introduce() const { cout << "Name: " << name << endl; }
};

class Student : virtual public Person {
protected:
    int rollNo;
public:
    Student(string n, int r) : Person(n), rollNo(r) {}
};

class Employee : virtual public Person {
protected:
    int empId;
public:
    Employee(string n, int e) : Person(n), empId(e) {}
};

class TA : public Student, public Employee {
public:
    TA(string n, int r, int e) : Person(n), Student(n, r), Employee(n, e) {}
    void show() const {
        introduce(); // unambiguous because Person is virtual
        cout << "Roll No: " << rollNo << ", Emp ID: " << empId << endl;
    }
};

int main() {
    TA ta("Meera", 42, 9001);
    ta.show();
    return 0;
}