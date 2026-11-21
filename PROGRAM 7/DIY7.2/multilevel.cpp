#include <iostream>
#include <string>
using namespace std;

class Shape {
protected:
    string color;
public:
    Shape(string c) : color(c) { cout << "1. Shape ctor (color=" << color << ")\n"; }
};

class Polygon : public Shape {
protected:
    int sides;
public:
    Polygon(string c, int s) : Shape(c), sides(s) {
        cout << "2. Polygon ctor (sides=" << sides << ")\n";
    }
};

class Rectangle : public Polygon {
    double area;
public:
    Rectangle(string c, double w, double h) : Polygon(c, 4), area(w * h) {
        cout << "3. Rectangle ctor (area=" << area << ")\n";
    }
};

int main() {
    Rectangle r("Blue", 5.0, 3.0);
    return 0;
}