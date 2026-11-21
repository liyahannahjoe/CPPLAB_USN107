#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    vector<pair<string, int>> items = {{"Pen", 20}, {"Book", 150}, {"Eraser", 5}, {"Bag", 800}};

    // Sort ascending by the second (int) field
    sort(items.begin(), items.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second < b.second;
    });

    for (const auto& p : items) {
        cout << p.first << ": " << p.second << endl;
    }
    return 0;
}