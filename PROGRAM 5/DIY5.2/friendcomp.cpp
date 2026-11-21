#include <iostream>
using namespace std;

class Time {
    int hh, mm;
public:
    Time(int h = 0, int m = 0) : hh(h), mm(m) {}
    friend Time laterOf(const Time& t1, const Time& t2);
    void show() const {
        cout << (hh < 10 ? "0" : "") << hh << ":"
             << (mm < 10 ? "0" : "") << mm << endl;
    }
};

Time laterOf(const Time& t1, const Time& t2) {
    if (t1.hh > t2.hh || (t1.hh == t2.hh && t1.mm > t2.mm))
        return t1;
    return t2;
}

int main() {
    Time t1(14, 30), t2(16, 15);
    Time later = laterOf(t1, t2);
    cout << "Later time: ";
    later.show();
    return 0;
}