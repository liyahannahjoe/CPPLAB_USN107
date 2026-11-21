#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

struct Shape {
    virtual double area() const = 0;
    virtual ~Shape() {}
};

struct Circle : Shape {
    double r;
    Circle(double r) : r(r) {}
    double area() const override { return 3.14159 * r * r; }
};

struct Square : Shape {
    double s;
    Square(double s) : s(s) {}
    double area() const override { return s * s; }
};

struct Triangle : Shape {
    double b, h;
    Triangle(double b, double h) : b(b), h(h) {}
    double area() const override { return 0.5 * b * h; }
};

unique_ptr<Shape> makeShape(const string& kind) {
    if (kind == "circle")   return make_unique<Circle>(2.0);
    if (kind == "square")   return make_unique<Square>(3.0);
    if (kind == "triangle") return make_unique<Triangle>(4.0, 5.0);
    return nullptr;
}

int main() {
    vector<unique_ptr<Shape>> shapes;
    string choice;

    cout << "Enter shapes (circle, square, triangle) or 'done':\n";
    while (cin >> choice && choice != "done") {
        auto s = makeShape(choice);
        if (s) shapes.push_back(move(s));
        else cout << "Unknown shape!\n";
    }

    for (const auto& s : shapes) {
        cout << "Area = " << s->area() << endl;
    }
    return 0;
}
