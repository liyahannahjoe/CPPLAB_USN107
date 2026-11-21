#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int id;
public:
    Employee(string n, int i) : name(n), id(i) {}
    void showBase() const { cout << "Name: " << name << ", ID: " << id; }
};

class Manager : public Employee {
    int teamSize;
public:
    Manager(string n, int i, int t) : Employee(n, i), teamSize(t) {}
    void show() const {
        showBase();
        cout << ", Team Size: " << teamSize << endl;
    }
};

class Engineer : public Employee {
    string skill;
public:
    Engineer(string n, int i, string s) : Employee(n, i), skill(s) {}
    void show() const {
        showBase();
        cout << ", Skill: " << skill << endl;
    }
};

int main() {
    Manager m("Asha", 101, 12);
    Engineer e("Ravi", 102, "Embedded C++");

    m.show();
    e.show();
    return 0;
}