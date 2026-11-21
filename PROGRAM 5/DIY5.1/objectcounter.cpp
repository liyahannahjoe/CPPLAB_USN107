#include <iostream>
using namespace std;

class Counter {
    int count = 0;
    static int created;
    static int alive;
public:
    Counter()  { ++created; ++alive; }
    ~Counter() { --alive; }

    void increment() { ++count; }
    void reset()     { count = 0; }
    int get() const  { return count; }

    static int totalCreated()   { return created; }
    static int currentlyAlive() { return alive; }
};

int Counter::created = 0;
int Counter::alive   = 0;

int main() {
    Counter c1, c2;
    {
        Counter c3;
        cout << "Created: " << Counter::totalCreated()
             << ", Alive: " << Counter::currentlyAlive() << endl;
    }
    cout << "Created: " << Counter::totalCreated()
         << ", Alive: " << Counter::currentlyAlive() << endl;
    return 0;
}