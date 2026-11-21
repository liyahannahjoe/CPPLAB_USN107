#include <iostream>
using namespace std;

class Rectangle {
private:
    double length = 0, width = 0;
public:
    void setLength(double l) {
        if (l >= 0) length = l;
        else cout << "Invalid length (negative rejected)\n";
    }
    void setWidth(double w) {
        if (w >= 0) width = w;
        else cout << "Invalid width (negative rejected)\n";
    }
    double area() const      { return length * width; }
    double perimeter() const { return 2 * (length + width); }
};

int main() {
    Rectangle r;
    r.setLength(-5); // rejected
    r.setLength(10);
    r.setWidth(4);
    cout << "Area = " << r.area() << ", Perimeter = " << r.perimeter() << endl;
    return 0;
}