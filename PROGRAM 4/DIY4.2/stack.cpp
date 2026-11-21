#include <iostream>
using namespace std;

class Stack {
    int* arr;
    int top;
    int capacity;
public:
    Stack(int cap = 10) : capacity(cap), top(-1) {
        arr = new int[capacity];
    }

    void push(int x) {
        if (top < capacity - 1) arr[++top] = x;
        else cout << "Stack overflow\n";
    }

    int pop() {
        if (top >= 0) return arr[top--];
        cout << "Stack underflow\n";
        return -1;
    }

    bool empty() const { return top < 0; }

    ~Stack() {
        delete[] arr;
    }
};

int main() {
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    while (!s.empty()) cout << s.pop() << " ";
    cout << endl;
    return 0;
}