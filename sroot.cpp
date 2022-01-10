#include<iostream>
#include<math.h>
#include<iomanip>
//#include<bits/stdc++.h>
using namespace std;

int main(){
    double x[4];
    cout << "Enter the numbers" << endl;
    cin >> x[0] >>  x[1] >> x[2] >> x[3] >> x[4];
    cout << "Number \t" << "Square Root \t" << endl;
    for (int i;i<5;i++){
        cout << x[i] << "\t";
        cout << setprecision(4);
        cout << sqrt(x[i]) << "\t" << endl;
    }
}