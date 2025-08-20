#include<iostream>
using namespace std;

void createArray(int* arr,int n){
    cout<<"Enter elements of array"<<endl;
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

void removeDuplicate(int* arr,int n){
    createArray(arr,n);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                for(int k=j;k<n-1;k++){
                    arr[k]=arr[k+1];
                }
                n--;
                j--;
            }
        }
    }
    displayArray(arr,n);
}

int main(){
    int a[10];
    int n;
    cout<<"Enter the number of elements of array(<=10) : ";
    cin>>n;
    removeDuplicate(a,n);
    return 0;
}