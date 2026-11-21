#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

long counter = 0;
mutex m;

void addUnsafe(int times) {
    for (int i = 0; i < times; ++i) {
        // lock_guard commented out to trigger a data race:
        // lock_guard<mutex> lk(m);
        ++counter;
    }
}

void addSafe(int times) {
    for (int i = 0; i < times; ++i) {
        lock_guard<mutex> lk(m); // lock restored
        ++counter;
    }
}

int main() {
    // 1. Unsafe run (likely prints less than 200000)
    counter = 0;
    thread t1(addUnsafe, 100000);
    thread t2(addUnsafe, 100000);
    t1.join(); t2.join();
    cout << "Unsafe counter = " << counter << " (expected 200000)\n";

    // 2. Safe run with lock_guard restored (always prints 200000)
    counter = 0;
    thread t3(addSafe, 100000);
    thread t4(addSafe, 100000);
    t3.join(); t4.join();
    cout << "Safe counter   = " << counter << " (expected 200000)\n";
    return 0;
}