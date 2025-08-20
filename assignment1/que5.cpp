#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout<<"Enter number of rows: ";
    cin>>rows;
    cout<<"Enter number of columns: ";
    cin>>cols;

    int matrix[rows][cols];

    cout<<"Enter elements of the matrix : "<<endl;
    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
            cin>>matrix[i][j];
        }
    }

    for (int i=0;i<rows;i++) {
        int rowSum = 0;
        for (int j=0;j<cols;j++) {
            rowSum += matrix[i][j];
        }
        cout<<"Sum of row "<<i + 1<<" = "<<rowSum<<endl;
    }

    for (int j=0;j<cols;j++) {
        int colSum = 0;
        for (int i=0;i<rows;i++) {
            colSum += matrix[i][j];
        }
        cout<<"Sum of column "<< j + 1 << " = "<<colSum<<endl;
    }

    return 0;
}