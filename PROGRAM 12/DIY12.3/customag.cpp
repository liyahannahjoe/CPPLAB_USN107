#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    vector<int> nums = {2, 3, 4, 5, 6};

    // Product of all elements (initial value = 1)
    int product = accumulate(nums.begin(), nums.end(), 1, [](int acc, int x) {
        return acc * x;
    });

    // Sum of only the even elements (initial value = 0)
    int evenSum = accumulate(nums.begin(), nums.end(), 0, [](int acc, int x) {
        return (x % 2 == 0) ? acc + x : acc;
    });

    cout << "Product of all = " << product << endl;
    cout << "Sum of evens = " << evenSum << endl;
    return 0;
}