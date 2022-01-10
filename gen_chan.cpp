#include<iostream>
#include<complex>
#include<iomanip>
#include<cmath>
#define RAND_MAX 360
using namespace std;
using namespace std:: complex_literals;

int m;
// Matric generation function here
double chanGen(int n){
    srand(time(nullptr));
    complex<double> CMtx;
    for (int k = 0; k < n; ++k)
    {
        for (int l = 0; l < n; ++l)
        {
            complex<double> CMtx(cos(1+rand()/(100000000)), sin(1+rand()/(100000000)));
            cout << CMtx << '\t';
        }
        cout << endl;
    }
    
}

int main(){
    cout << "Channel Matrix generation" << endl;
    cout << "Enter the size of Channel in powers of 2 (2^n)" << endl;
    cin >> m;
    chanGen(m);
}
