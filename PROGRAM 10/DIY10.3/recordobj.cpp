#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    string name;
    int marks;
};

int main() {
    // Store name-marks pairs in a file
    ofstream out("records.txt");
    out << "Asha 88\nRavi 95\nMeera 91\nKiran 79\n";
    out.close();

    ifstream in("records.txt");
    if (!in) { cerr << "Cannot open records.txt\n"; return 1; }

    Student students[50];
    int count = 0;
    while (count < 50 && (in >> students[count].name >> students[count].marks)) {
        ++count;
    }

    if (count > 0) {
        int topIdx = 0;
        for (int i = 1; i < count; ++i) {
            if (students[i].marks > students[topIdx].marks) {
                topIdx = i;
            }
        }
        cout << "Topper: " << students[topIdx].name
             << " (" << students[topIdx].marks << " marks)\n";
    }
    return 0;
}