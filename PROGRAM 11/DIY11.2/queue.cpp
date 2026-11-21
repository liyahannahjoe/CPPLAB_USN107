#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

template <typename T>
class Queue {
private:
    vector<T> data;

public:
    // Add an element to the back of the queue
    void enqueue(const T& val) {
        data.push_back(val);
    }

    // Remove the front element from the queue
    void dequeue() {
        if (isEmpty()) {
            throw out_of_range("Queue is empty");
        }
        data.erase(data.begin());
    }

    // Access the front element without removing it
    T front() const {
        if (isEmpty()) {
            throw out_of_range("Queue is empty");
        }
        return data.front();
    }

    bool isEmpty() const {
        return data.empty();
    }
};

int main() {
    Queue<string> q;
    q.enqueue("First");
    q.enqueue("Second");
    q.enqueue("Third");

    cout << "Front element: " << q.front() << endl; // Outputs: First
    q.dequeue();
    cout << "Front after dequeue: " << q.front() << endl; // Outputs: Second

    return 0;
}