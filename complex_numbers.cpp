#include<iostream>
#include<complex>
#include<cmath>
#include<iomanip>


using namespace std;
using namespace std::complex_literals;
int n;// Total number of elements in the array
#define RAND_MAX 360

void display(double *arr, int m){
    /* Common array print function, double can be replaced with any data type */
    for (int k = 0; k < m; ++k)
    {
        cout << *(arr+k) << "\t";
    }
    cout << endl;
    
}

int main(){
    cout << "Enter the number of elements needed for real and imaginary components" << endl;
    cin >> n;
    double re[n], im[n];
    // Generate a random number for real and imagingary parts
    srand(time(nullptr));
    double rv = rand();
    for (int k = 0; k < n; ++k)
    {
        /* code */
        re[k] = 1+rand()/(100000000);
        im[k] = 1+rand()/(100000000);
    }
    cout << "Real Components" << endl;
    display((double *) re, n);
    cout << "Imaginary Components" << endl;
    display((double *) im, n);
    //form complex nubmers out of them
    complex<double> z[n];
    for (int k = 0; k < n; ++k)
    {
        /* code */
        complex<double> z(cos(re[k]), sin(im[k]));
        cout << z << endl;

    }
    
    //complex<double> z[n](cos(re[0]), sin(im[0]));
}