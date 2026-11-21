#include <iostream>
using namespace std;

class Money {
    int rupees, paise;
public:
    Money(int r = 0, int p = 0) {
        int total = r * 100 + p;
        rupees = total / 100;
        paise = total % 100;
    }

    Money operator+(const Money& o) const {
        return Money(0, (rupees + o.rupees) * 100 + (paise + o.paise));
    }

    Money operator-(const Money& o) const {
        int total1 = rupees * 100 + paise;
        int total2 = o.rupees * 100 + o.paise;
        return Money(0, total1 - total2);
    }

    void show() const {
        cout << "Rs. " << rupees << "." << (paise < 10 ? "0" : "") << paise << endl;
    }
};

int main() {
    Money m1(15, 75), m2(8, 50);
    Money sum = m1 + m2;
    Money diff = m1 - m2;

    cout << "Sum: ";  sum.show();
    cout << "Diff: "; diff.show();
    return 0;
}