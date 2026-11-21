#include <iostream>
using namespace std;

// Template function to swap two values by reference
template <typename T>
void swapVals(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// Template function to find the maximum element in an array
template <typename T>
T findMax(T arr[], int n) {
    T maxVal = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int main() {
    // Testing with int
    int x = 10, y = 25;
    swapVals(x, y);
    cout << "Swapped ints: " << x << ", " << y << endl;

    int intArr[] = {4, 19, 2, 42, 15};
    cout << "Max int: " << findMax(intArr, 5) << endl;

    // Testing with double
    double d1 = 3.14, d2 = 9.81;
    swapVals(d1, d2);
    cout << "Swapped doubles: " << d1 << ", " << d2 << endl;

    double doubleArr[] = {1.5, 7.25, 3.8, 6.9};
    cout << "Max double: " << findMax(doubleArr, 4) << endl;

    return 0;
}