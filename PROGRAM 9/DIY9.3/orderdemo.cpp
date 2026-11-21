#include <iostream>
#include <exception>
using namespace std;

class MathError : public exception {
public:
    const char* what() const noexcept override { return "General MathError"; }
};

class DivideByZero : public MathError {
public:
    const char* what() const noexcept override { return "DivideByZero error"; }
};

double divide(double a, double b) {
    if (b == 0) throw DivideByZero();
    return a / b;
}

int main() {
    // 1. Wrong order: base MathError first hides DivideByZero
    try {
        divide(10, 0);
    } catch (const MathError& e) {
        cout << "Wrong order caught: " << e.what() << endl;
    } catch (const DivideByZero& e) {
        cout << "Unreachable: " << e.what() << endl;
    }

    // 2. Fixed order: derived DivideByZero first, base MathError second
    try {
        divide(10, 0);
    } catch (const DivideByZero& e) {
        cout << "Fixed order caught: " << e.what() << endl;
    } catch (const MathError& e) {
        cout << "Caught: " << e.what() << endl;
    }
    return 0;
}