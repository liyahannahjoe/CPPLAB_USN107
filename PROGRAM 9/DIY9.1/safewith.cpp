#include <iostream>
#include <exception>
#include <string>
using namespace std;

class InsufficientFunds : public exception {
    string msg;
public:
    InsufficientFunds(double requested, double available) {
        msg = "Insufficient funds: requested " + to_string(requested) +
              ", available " + to_string(available);
    }
    const char* what() const noexcept override { return msg.c_str(); }
};

class BankAccount {
    string owner;
    double balance;
public:
    void open(const string& name, double initial) {
        owner = name;
        balance = (initial > 0) ? initial : 0;
    }
    void deposit(double amt) { if (amt > 0) balance += amt; }
    void withdraw(double amt) {
        if (amt > balance) throw InsufficientFunds(amt, balance);
        if (amt > 0) balance -= amt;
    }
    double getBalance() const { return balance; }
};

int main() {
    BankAccount acc;
    acc.open("Asha", 1000);
    try {
        acc.withdraw(400);
        cout << "Balance after 400 withdrawal: " << acc.getBalance() << endl;
        acc.withdraw(800); // throws InsufficientFunds
    } catch (const InsufficientFunds& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}