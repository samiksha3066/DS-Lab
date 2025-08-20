#include<iostream>
using namespace std;
int main(){
    int n=0;
    int arr[6]={1,2,3,4,5,6};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i>=j) {
                cout<<arr[n]<<" ";
                n++;
            }
            else cout<<"0 ";
        }
        cout<<endl;
    }
    return 0;
}