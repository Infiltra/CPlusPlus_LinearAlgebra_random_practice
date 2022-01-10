// C++ Program to display the elements of two
// dimensional array by passing it to a function

#include <iostream>
using namespace std;

int r, c;

void display(int n[][2]) {
    cout << "Displaying Values: " << endl;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << "num[" << i << "][" << j << "]: " << n[i][j] << endl;
        }
    }
}
void mA(){
    int a[r][c];
    cout << "Enter elements of first matrix" << endl;
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cin >> a[i][j];
        }
    }
}
void mB(){
    int b[r][c];
    cout << "Enter elements of second matrix" << endl;
    for (int i = 0; i <= r; ++i)
    {
        for (int j = 0; j <= c; ++j)
        {
            cin >> b[i][j];
        }
    }
}
void sumC(){
    int a[r][c], b[r][c], s[r][c];
    for (int i = 0; i <= r; ++i)
    {
        for (int j = 0; j <= c; ++j)
        {
            s[i][j] = a[i][j] + b[i][j];
        }
    }
}
int main() {
    cout << "Enter the number of rows " << endl;
    cin >> r;
    cout << "Enter the number of columns " << endl;
    cin >> c;
    //intialize the array
    mA();
    mB();
    sumC();
    return 0;
}