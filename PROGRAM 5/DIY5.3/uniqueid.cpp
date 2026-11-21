#include <iostream>
using namespace std;

class Order {
    int id;
    static int nextId;
public:
    Order() { id = nextId++; }
    int getId() const { return id; }
};

int Order::nextId = 1001;

int main() {
    Order o1, o2, o3;
    cout << "Order 1 ID: " << o1.getId() << endl;
    cout << "Order 2 ID: " << o2.getId() << endl;
    cout << "Order 3 ID: " << o3.getId() << endl;
    return 0;
}