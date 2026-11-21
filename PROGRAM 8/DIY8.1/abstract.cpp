#include <iostream>
using namespace std;

class Account {
protected:
    double balance;
public:
    Account(double b) : balance(b) {}
    virtual double calculateInterest() const = 0;
    virtual ~Account() {}
};

class Savings : public Account {
public:
    Savings(double b) : Account(b) {}
    double calculateInterest() const override { return balance * 0.04; } // 4%
};

class Current : public Account {
public:
    Current(double b) : Account(b) {}
    double calculateInterest() const override { return balance * 0.01; } // 1%
};

int main() {
    Account* accounts[] = { new Savings(10000), new Current(10000) };

    for (Account* acc : accounts) {
        cout << "Interest = " << acc->calculateInterest() << endl;
        delete acc;
    }
    return 0;
}