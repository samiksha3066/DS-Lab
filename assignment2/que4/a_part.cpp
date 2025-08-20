#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the order of matrix : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements for diagonal matrix : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"The diagonal matrix is : "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) cout<<arr[i]<<" ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
    return 0;
}