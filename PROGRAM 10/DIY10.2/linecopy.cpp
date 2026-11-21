#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Create sample in.txt first
    ofstream sample("in.txt");
    sample << "First line of text\nSecond line here\nThird and final line\n";
    sample.close();

    ifstream in("in.txt");
    ofstream out("out.txt");
    if (!in || !out) { cerr << "File open error\n"; return 1; }

    string line;
    int lineNum = 1;
    while (getline(in, line)) {
        out << lineNum++ << ": " << line << "\n";
    }
    in.close();
    out.close();

    // Display out.txt to verify
    ifstream verify("out.txt");
    cout << "Contents of out.txt:\n";
    while (getline(verify, line)) {
        cout << line << endl;
    }
    return 0;
}