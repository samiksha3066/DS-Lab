#include<iostream>
using namespace std;

int MissingNo(int arr[],int size) {
    int left = 0;
    int high = size - 1;
    int start_diff = arr[0] - 0;

    while (left <= high) {
        int mid = left + (high - left) / 2;
        int current_diff = arr[mid] - mid;

        if (current_diff == start_diff) {
            left = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    
    return left + start_diff;
}

int main() {
    int arr[] = {3, 4, 5, 6, 8, 9, 10};
    int size = sizeof(arr)/sizeof(arr[0]);

    int missing = MissingNo(arr,size);
    cout<<"Missing number is : "<<missing<<endl;

    return 0;
}
