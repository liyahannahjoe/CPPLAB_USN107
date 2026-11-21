#include <iostream>
#include <memory>
#include <cstring>
using namespace std;

class MyString {
    unique_ptr<char[]> data; // replaces raw char* and manual delete[]
public:
    MyString(const char* s) {
        data = make_unique<char[]>(strlen(s) + 1);
        strcpy(data.get(), s);
    }
    void print() const { cout << data.get() << endl; }
};

int main() {
    auto a = make_unique<MyString>("smart pointers");
    a->print();
    return 0; // memory freed automatically with zero delete calls
}