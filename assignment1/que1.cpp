#include<iostream>
using namespace std;

void createArray(int* arr,int n){
    cout<<"Enter elements of array : "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}

void displayArray(int* arr,int n){
    createArray(arr,n);
    cout<<"Array is : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void insert(int* arr,int n){
    createArray(arr,n);
    int pos,value;
    cout<<"Enter position and value of element to be entered ";
    cin>>pos>>value;
    for(int i=n;i>pos-1;i--){
        arr[i]=arr[i-1];
    }
    arr[pos-1]=value;
    n++;
    displayArray(arr,n);
}

void deleteElm(int* arr,int n){
    createArray(arr,n);
    int pos;
    cout<<"Enter position of element to be deleted ";
    cin>>pos;
    for(int i=pos-1;i<n;i++){
        arr[i]=arr[i+1];
    }
    n--;
    displayArray(arr,n);
}

int linearSearch(int* arr,int n){
    createArray(arr,n);
    int value;
    cout<<"Enter element to be found ";
    cin>>value;
    for(int i=0;i<n;i++){
        if(arr[i]==value){
            return i+1;
        }
    }
    return -1;
}

int main(){
   int a[20];
   int x,pos;
   cout<<"----MENU----"<<endl;
   cout<<" 1.CREATE \n 2.DISPLAY \n 3.INSERT \n 4.DELETE \n 5.LINEAR SEARCH \n 6.EXIT \n";
   int n;
   cout<<"Enter the number of elements of array(less than 20): ";
   cin>>n;
   cout<<endl<<"Enter your choice : ";
   cin>>x;
   switch(x){
    case 1: 
        createArray(a,n); 
        break;
    case 2: 
        displayArray(a,n); 
        break;
    case 3: 
        insert(a,n); 
        break;
    case 4: 
        deleteElm(a,n); 
        break;
    case 5: 
        pos=linearSearch(a,n);
            if(pos>0)
                cout<<"Element found at position "<<pos; 
            else  cout<< "Element doesn't exist in array"; 
        break;
    case 6: 
        cout<<"Exiting program";  
        break;
    default: 
        cout<<"Invalid choice"; 
        break;
   }

   return 0;
}