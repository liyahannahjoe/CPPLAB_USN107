#include <iostream>
using namespace std;

// Cube (1 arg)
double volume(double s) {
    return s * s * s;
}

// Cuboid (3 args)
double volume(double l, double b, double h) {
    return l * b * h;
}

// Cylinder (2 args: radius & height)
double volume(double r, double h) {
    return 3.14159 * r * r * h;
}

int main() {
    cout << "Cube volume = " << volume(3) << endl;
    cout << "Cuboid volume = " << volume(2, 3, 4) << endl;
    cout << "Cylinder volume = " << volume(2, 5) << endl;
    return 0;
}