#include<iostream>
using namespace std;

void multiplyMatrices() { 
    int r1, r2, c1, c2; 
    cout<<"Enter rows and columns of first matrix : "; 
    cin>>r1>>c1; 
    cout<<"Enter rows and columns of second matrix : "; 
    cin >> r2 >> c2; 
    if (c1 != r2) {
         cout <<"Matrix multiplication not possible!!!!"<<endl;
    }
    else{
        int A[r1][c1], B[r2][c2]; 
        cout <<"Enter elements of first matrix: "<<endl; 
        for (int i=0;i<r1;i++){
            for (int j = 0; j < c1; j++){
                cin>>A[i][j];
            }
        }

        cout << "Enter elements of second matrix:\n"; 
        for (int i=0;i<r2;i++) {
            for (int j=0;j<c2;j++) {
                cin>>B[i][j];
            }
        }

        int C[r1][c2];
        for (int i=0;i<r1;i++) {
                for (int j=0;j<c2;j++) {
                    C[i][j]=0;
                    for (int k=0;k<c1;k++) {
                        C[i][j] += A[i][k] * B[k][j];
                    }
                }
                cout<<endl;
            }

        cout<<"Result of matrix multiplication : "<<endl;
            for (int i=0;i<r1;i++) {
                for (int j=0;j<c2;j++) {
                    cout<<C[i][j]<<" ";
                }
                cout<<endl;
            }  
    }
}

int main(){
    multiplyMatrices();
}