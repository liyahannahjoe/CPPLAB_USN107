#include <iostream>
using namespace std;

inline int minVal(int a, int b) {
    return (a < b) ? a : b;
}

inline int minVal(int a, int b, int c) {
    return minVal(minVal(a, b), c);
}

int main() {
    cout << "minVal(10, 4) = " << minVal(10, 4) << endl;
    cout << "minVal(10, 4, 7) = " << minVal(10, 4, 7) << endl;
    return 0;
}