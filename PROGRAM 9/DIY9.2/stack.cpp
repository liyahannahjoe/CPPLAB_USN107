#include <iostream>
#include <exception>
using namespace std;

class Overflow : public exception {
public:
    const char* what() const noexcept override { return "Stack Overflow!"; }
};

class Underflow : public exception {
public:
    const char* what() const noexcept override { return "Stack Underflow!"; }
};

class Stack {
    int* arr;
    int top;
    int capacity;
public:
    Stack(int cap = 3) : capacity(cap), top(-1) {
        arr = new int[capacity];
    }
    void push(int x) {
        if (top >= capacity - 1) throw Overflow();
        arr[++top] = x;
    }
    int pop() {
        if (top < 0) throw Underflow();
        return arr[top--];
    }
    ~Stack() { delete[] arr; }
};

int main() {
    Stack s(2);
    try {
        s.push(10);
        s.push(20);
        s.push(30); // triggers Overflow
    } catch (const Overflow& e) {
        cout << "Caught: " << e.what() << endl;
    }

    try {
        cout << "Popped: " << s.pop() << endl;
        cout << "Popped: " << s.pop() << endl;
        cout << "Popped: " << s.pop() << endl; // triggers Underflow
    } catch (const Underflow& e) {
        cout << "Caught: " << e.what() << endl;
    }
    return 0;
}