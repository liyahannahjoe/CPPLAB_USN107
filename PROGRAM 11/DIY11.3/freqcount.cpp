#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string line;
    cout << "Enter a line of words: ";
    getline(cin, line);

    stringstream ss(line);
    string word;
    unordered_map<string, int> freq;

    while (ss >> word) {
        ++freq[word];
    }

    string mostFreq;
    int maxCount = 0;

    for (const auto& p : freq) {
        cout << p.first << ": " << p.second << endl;
        if (p.second > maxCount) {
            maxCount = p.second;
            mostFreq = p.first;
        }
    }

    if (maxCount > 0) {
        cout << "Most frequent word: " << mostFreq << " (" << maxCount << ")\n";
    }
    return 0;
}