#include<iostream>
using namespace std;
void createArray(int* arr,int n){
    cout<<"Enter elements of array : "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}

void displayArray(int* arr,int n){
    cout<<"Array is : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void reverseArray(int* arr,int n){
    createArray(arr,n);
    for(int i=0;i<=n/2;i++){
        int temp=arr[i];
        arr[i]=arr[n-i-1];
        arr[n-i-1]=temp;
    }
    displayArray(arr,n);
}

int main(){
    int arr[10];
    int n;
    cout<<"Enter the number of elements of array : ";
    cin>>n;
    reverseArray(arr,n);
    return 0;
}