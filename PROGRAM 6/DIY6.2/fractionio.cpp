#include <iostream>
#include <numeric>
using namespace std;

class Fraction {
    int num, den;
    void simplify() {
        if (den < 0) { num = -num; den = -den; }
        int g = gcd(abs(num), abs(den));
        if (g != 0) { num /= g; den /= g; }
    }
public:
    Fraction(int n = 0, int d = 1) : num(n), den(d) {
        simplify();
    }

    friend ostream& operator<<(ostream& os, const Fraction& f) {
        os << f.num << "/" << f.den;
        return os;
    }

    friend istream& operator>>(istream& is, Fraction& f) {
        is >> f.num >> f.den;
        f.simplify();
        return is;
    }
};

int main() {
    Fraction f1(6, 8);
    cout << "Simplified 6/8 = " << f1 << endl;

    Fraction f2;
    cout << "Enter numerator and denominator: ";
    cin >> f2;
    cout << "Simplified = " << f2 << endl;
    return 0;
}