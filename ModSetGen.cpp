#include<iostream>
#include<iomanip>
#include<complex>
#include<cmath>

// Only PSK is present, need to do the same for QAM



using namespace std;
using namespace std:: complex_literals;

// Set universal for ou
static const double pi = 3.1415;
// static const double circle = 360; // This is in degrees, and this is not needed, impulsive var decl
int m;


void genBPSK(){
    // BPSK IQ generation function
    // Two points at +1 and -1, no imaginary component i.e 0
    // 1 bits to 1 symbol
    cout << "Computing QPSK Points" << endl;
    // Get the angles
    double phi[2];
    for (int k = 1; k <= 2; ++k)
    {
        /* code */
        phi[k] = (2*pi*k)/2; // Generated in radians only
        // cout << phi[k] << endl;
    }
    complex<double> mod_vec[2]; // 2^1
    for (int i = 0; i < 2; ++i)
    {
        /* code */
        complex <double> mod_vec(round(cos(phi[i])), round(sin(phi[i])));
        cout << mod_vec << '\t';
    }
    cout << endl;
}

void genQPSK(){
    // QPSK IQ generation function
    // 4 points at +1+1j, -1+1j, -1-1j and 1-1j
    // 2 bits to 1 symbol
    cout << "Computing QPSK Points" << endl;
    float M = 4;
    for (int i = 0; i <= M-1; ++i)
    {
        /* code */
        double phi = ((2*pi*i)/M);
        // cout << "Phi " <<phi << '\t' << endl;
        // cout << "Cosine " << cos(phi) << '\t' << endl;
        // cout << "Sine " << sin(phi) << '\t' << endl;
        complex <double> mod_vec(round(cos(phi)), round(sin(phi)));
        cout << mod_vec << '\t';
    }
    cout << endl;
}

void genOQPSK(){
    // QPSK IQ generation function
    // 4 points at pi/4 phase shifts from origital
    // 2 bits to 1 symbol
    cout << "Computing pi/4 O-QPSK Points" << endl;
    float M = 4;
    for (int i = 0; i <= M-1; ++i)
    {
        /* code */
        double phi = (pi/4)+((2*pi*i)/M);
        // cout << "Phi " <<phi << '\t' << endl;
        // cout << "Cosine " << cos(phi) << '\t' << endl;
        // cout << "Sine " << sin(phi) << '\t' << endl;
        complex <double> mod_vec(cos(phi), sin(phi));
        cout << mod_vec << '\t';
    }
    cout << endl;
}

void gen8PSK(){
    // QPSK IQ generation function
    // 8 equidistant around circle
    // 3 bits to 1 symbol
    cout << " 8-PSK Points" << endl;
    float M = 8;
    for (int i = 0; i <= M-1; ++i)
    {
        /* code */
        double phi = ((2*pi*i)/M);
        // cout << "Phi " <<phi << '\t' << endl;
        // cout << "Cosine " << cos(phi) << '\t' << endl;
        // cout << "Sine " << sin(phi) << '\t' << endl;
        complex <double> mod_vec(round(cos(phi)), round(sin(phi)));
        cout << mod_vec << '\t';
    }
    cout << endl;
}

void gen16PSK(){
    // QPSK IQ generation function
    // 8 equidistant around circle
    // 4 bits to 1 symbol
    cout << " 16-PSK Points" << endl;
    float M = 16;
    for (int i = 0; i <= M-1; ++i)
    {
        /* code */
        double phi = ((2*pi*i)/M);
        // cout << "Phi " <<phi << '\t' << endl;
        // cout << "Cosine " << cos(phi) << '\t' << endl;
        // cout << "Sine " << sin(phi) << '\t' << endl;
        complex <double> mod_vec(cos(phi), sin(phi));
        cout << mod_vec << '\t';
    }
    cout << endl;
}



int main(){
    // Generate modulation set for different types of modulation scheme
    // Get for BPSK, QPSK, 8-PSK, 16-PSK...
    // All that we are doing is generate the IQ energy points
    // User Switch case to select mod points
    cout << "Enter the modulation scheme" << endl;
    cout << "1. BPSK(2^1)" << '\n' << "2. QPSK(2^2)" 
    << '\n' << "3. (pi/4)QPSK" << '\n' << "4. 8PSK(2^3)" 
    << '\n' << "5. 16-PSK(2^4)" << '\n' << "6. 16-QAM"<< endl;
    cin >> m;
    switch (m)
    {
    case 1:
        genBPSK();
        break;
    case 2:
        genQPSK();
        break;
    case 3:
        genOQPSK();
        break;
    case 4:
        gen8PSK();
        break;
    default:
    cout << "Enter a choice from above" << endl;
        break;
    }

}