#include <iostream>
using namespace std;


int binarySearch(int a[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  // Avoid potential overflow

        if (a[mid] == target) {
            return mid;  // Target found at index mid
        }
        else if (a[mid] < target) {
            left = mid + 1;  // Search in the right half
        }
        else {
            right = mid - 1;  // Search in the left half
        }
    }

    return -1;  // Target not found
}

int main() {
    int a[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(a)/sizeof(a[0]);
    int target;

    cout << "Enter number to search: ";
    cin >> target;

    int result=binarySearch(a,size,target);

    if (result!=-1)
        cout<<"Element found at index "<<result<<endl;
    else
        cout<<"Element not found in the array."<<endl;

    return 0;
}
