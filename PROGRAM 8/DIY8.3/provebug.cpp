#include <iostream>
using namespace std;

class Base {
public:
    // Remove 'virtual' below to observe the leak!
    virtual ~Base() { cout << "~Base\n"; }
};

class Derived : public Base {
    int* data;
public:
    Derived() { data = new int[100]; cout << "Derived allocated\n"; }
    ~Derived() { delete[] data; cout << "~Derived freed\n"; }
};

int main() {
    Base* ptr = new Derived();
    delete ptr; // calls ~Derived() only because ~Base() is virtual
    return 0;
}