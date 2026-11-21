#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

int main() {
    // Create sample nums.txt first so the program runs immediately
    ofstream sample("nums.txt");
    sample << "12 45 7 89 23 56\n";
    sample.close();

    ifstream in("nums.txt");
    if (!in) { cerr << "Cannot open nums.txt\n"; return 1; }

    int x, count = 0, sum = 0;
    int minVal = INT_MAX, maxVal = INT_MIN;

    while (in >> x) {
        ++count;
        sum += x;
        if (x < minVal) minVal = x;
        if (x > maxVal) maxVal = x;
    }

    if (count > 0) {
        cout << "Count: " << count << "\nSum: " << sum
             << "\nMin: " << minVal << "\nMax: " << maxVal << endl;
    } else {
        cout << "No numbers found in file.\n";
    }
    return 0;
}