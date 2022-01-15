#include<iostream>
#include<complex>
#include<iomanip>
#include<cmath>
#define RAND_MAX 360
using namespace std;
using namespace std:: complex_literals;

int m;

void displayMtx(float *arr, int m){
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << *((arr+i*m)+j) << "\t";
        }
        cout << endl;
    }
    
}

// Matric generation function here
float chanGen(int n){
    srand(time(nullptr));
    // change the matrix to real and complex matrices separately and to float
    float H_real[m][m], H_imag[m][m];
    for (int k = 0; k < n; ++k)
    {
        for (int l = 0; l < n; ++l)
        {
            complex<float> CMtx(cos(1+rand()/(100000000)), sin(1+rand()/(100000000)));
            cout << CMtx << '\t';
            H_real[k][l] = CMtx.real();
            H_imag[k][l] = CMtx.imag();
        }
        cout << endl;
    }
    cout << "Channel Matrix Real Components" << endl;
    displayMtx((float *)H_real, m);
    cout << "Channel Matrix Imaginary Components" << endl;
    displayMtx((float *)H_imag, m);
    return H_real[m][m], H_imag[m][m];
}

int main(){
    cout << "Channel Matrix generation" << endl;
    cout << "Enter the size of Channel in powers of 2 (2^n)" << endl;
    cin >> m;
    chanGen(m);
}
