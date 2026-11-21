#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s;
    cout << "Enter a sentence: ";
    getline(cin, s);

    int vowels = 0, consonants = 0;
    for (char c : s) {
        if (isalpha(c)) {
            char lower = tolower(c);
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u')
                ++vowels;
            else
                ++consonants;
        }
    }

    cout << "Vowels: " << vowels << ", Consonants: " << consonants << endl;
    return 0;
}