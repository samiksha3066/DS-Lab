#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
private:
    vector<int> heap;
    void heapifyUp(int index) {
        int parent = (index - 1) / 2;

        while (index > 0 && heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }
    void heapifyDown(int index) {
        int left, right, largest;
        int n = heap.size();

        while (true) {
            left = 2 * index + 1;
            right = 2 * index + 2;
            largest = index;

            if (left < n && heap[left] > heap[largest])
                largest = left;

            if (right < n && heap[right] > heap[largest])
                largest = right;

            if (largest == index) break;

            swap(heap[index], heap[largest]);
            index = largest;
        }
    }

public:

    void push(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }
    int top() {
        if (heap.empty()) {
            cout << "Priority Queue is empty!\n";
            return -1;
        }
        return heap[0];
    }
    void pop() {
        if (heap.empty()) {
            cout << "Priority Queue is empty!\n";
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }
    bool empty() {
        return heap.empty();
    }
    void display() {
        for (int x : heap)
            cout << x << " ";
        cout << endl;
    }
};
int main() {
    PriorityQueue pq;

    pq.push(30);
    pq.push(10);
    pq.push(20);
    pq.push(50);
    pq.push(40);

    cout << "Priority Queue (as Max Heap): ";
    pq.display();

    cout << "Top element (Highest Priority): " << pq.top() << endl;

    cout << "\nPopping top element...\n";
    pq.pop();
    cout << "After pop: ";
    pq.display();

    cout << "\nPopping again...\n";
    pq.pop();
    cout << "After pop: ";
    pq.display();

    return 0;
}
