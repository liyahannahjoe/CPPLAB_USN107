#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    priority_queue<int> pq;
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        pq.push(val);
    }

    cout << "Three largest: ";
    for (int i = 0; i < 3 && !pq.empty(); ++i) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    return 0;
}