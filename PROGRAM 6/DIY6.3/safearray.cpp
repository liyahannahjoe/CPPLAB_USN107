#include <iostream>
#include <stdexcept>
using namespace std;

class SafeArray {
    int* arr;
    int size;
public:
    SafeArray(int s) : size(s) {
        arr = new int[size]{0};
    }

    int& operator[](int i) {
        if (i < 0 || i >= size) {
            throw out_of_range("Index out of range");
        }
        return arr[i];
    }

    ~SafeArray() { delete[] arr; }
};

int main() {
    SafeArray a(3);
    try {
        a[0] = 10;
        a[1] = 20;
        cout << "a[1] = " << a[1] << endl;
        cout << a[5] << endl; // out of range
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}