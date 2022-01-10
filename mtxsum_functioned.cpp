#include<iostream>
#include<math.h>
using namespace std;
 
//User defined function list
int getDim(int r, int c);
int getA(a[100][100]);
// global access variables
int rows, cols;
int a[][100], b[][100], c[][100];


 
int main(){
    //get the input for rows and cols
    getDim(rows, cols);
    cout << "The total rows are: " << rows << "\t" << endl << "The total cols are: " << cols << "\t" << endl;
    int a[rows][cols], b[rows][cols], c[rows][cols];
    return 0;
}

int getDim(int r, int c){
    cout << "Enter the rows of the matrix: \t";
    cin >> rows;
    cout << "Enter the cols of the matrix: \t";
    cin >> cols;
    return rows, cols;
}