#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string w1, w2;
    cout << "Enter two words: ";
    cin >> w1 >> w2;

    sort(w1.begin(), w1.end());
    sort(w2.begin(), w2.end());

    if (w1 == w2)
        cout << "Anagram\n";
    else
        cout << "Not an anagram\n";

    return 0;
}