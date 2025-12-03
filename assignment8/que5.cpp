#include <iostream>
#include <vector>
using namespace std;
void heapifyMax(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyMax(arr, n, largest);
    }
}

void heapifyMin(vector<int>& arr, int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapifyMin(arr, n, smallest);
    }
}
void heapSortIncreasing(vector<int>& arr) {
    int n = arr.size();

    // Build max-heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapifyMax(arr, n, i);

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);            
        heapifyMax(arr, i, 0);         
    }
}
void heapSortDecreasing(vector<int>& arr) {
    int n = arr.size();

    // Build min-heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapifyMin(arr, n, i);

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);          
        heapifyMin(arr, i, 0);         
    }
}
int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    // Increasing Order
    vector<int> incArr = arr;
    heapSortIncreasing(incArr);

    cout << "Sorted in Increasing Order: ";
    for (int x : incArr) cout << x << " ";
    cout << endl;

    // Decreasing Order
    vector<int> decArr = arr;
    heapSortDecreasing(decArr);

    cout << "Sorted in Decreasing Order: ";
    for (int x : decArr) cout << x << " ";
    cout << endl;

    return 0;
}
