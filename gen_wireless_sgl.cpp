// T0DO Generalize the entire code for 2^n size
// Currently channel and received signal is generated for 2x2 system

#include<iostream>
#include<iomanip>
#include<complex>
#include<cmath>
#include<time.h>

using namespace std;
using namespace std:: complex_literals;
int m;
//int n=1;

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

void displayVec(float *arr, int m, int n){
    for (int ii = 0; ii < m; ++ii)
    {
        for (int jj = 0; jj < n; ++jj)
        {
             cout << *((arr+ii*n)+jj) << "\t";
        }
        cout << endl;
    }
    
}


int main(){
    // SNR parameters to be added to the noise
    float snr_db = 10;
    cout << setprecision(4);
    cout << "Enter the number of samples in 2^n" << '\t';
    cin >> m;
    cout << endl;
    if (m>2)
    {
        cout << "Current code is only for a 2x2 system" << endl;
        exit(-1);
    }else if (m==1)
    {
        cout << "Current code is only for a 2x2 system" << endl;
        exit(-1);
    }
    else
        cout << "Generating Wireless signal now" << endl;
    
    
    /* Setup constants */
    const static int q = 15;
    const static float c1 = (1 << q) - 1;
    const static float c2 = ((int)(c1 / 3)) + 1;
    const static float c3 = 1.f / c1;
    // Work flow is simple, generate a channel matrix, noise vector and signal vector
    // First generate a binary stream of 0 and 1
    srand(time(nullptr)); // Random number generator with time as seed
    float random;
    float sgl[m];
    // TODO: Generate this as a equiprobable stream, this is the binary data
    for (int ii = 0; ii < m; ++ii)
    {
            /* code */
         random = ((float)rand() / (float)(RAND_MAX));
        // cout << random << endl;
        if (random > 0.5){
            sgl[ii] = 1;
        }
        else if(random < 0.5){
            sgl[ii] = 0;
        }
    } // Symbols that are generated are not equiprobable occurrances, will cause porblems in source coding IRL
    cout << "Generated Signal" << endl;
    displayVec((float *) sgl, m, 1);
    // Generate a channel
    float H_real[m][m], H_imag[m][m];
    // Create a modulation module here, for now use a BPSK modulation module
    float x_real[m], x_imag[m]; // real and imaginary arrays for Tx symbols
    for (int k = 0; k < m; ++k)
    {
        /* 1+0j->1, -1+0j->0 */
        complex <float> sym1(1, 0);
        complex <float> sym2(-1, 0);
        if (sgl[k] == 1)
        {
            x_real[k] = sym1.real();
            x_imag[k] = sym1.imag();
        }else
            x_real[k] = sym2.real();
            x_imag[k] = sym2.imag();
        }
    cout << "Real part of trnsmit symbols" << endl;
    displayVec((float *) x_real, m, 1);
    cout << "Imaginary part of transmit symbols" << endl;
    displayVec((float *) x_imag, m, 1);
    cout << "Complex channel matrix" << endl;
    for (int k = 0; k < m; ++k)
    {
        for (int l = 0; l < m; ++l)
        {
            /* code */
            complex <float> c(cos(((float)rand() / (float)(RAND_MAX))), sin(((float)rand() / (float)(RAND_MAX))));
            H_real[k][l] = c.real();
            H_imag[k][l] = c.imag();
            cout << c << '\t';
        }
        cout << endl;
    }
    cout << "Channel Matrix Real Components" << endl;
    displayMtx((float *)H_real, m);
    cout << "Channel Matrix Imaginary Components" << endl;
    displayMtx((float *)H_imag, m);
    // generate some complex gaussian noise
    float noise_real[m], noise_imag[m];
    for (int k = 0; k < m; ++k)
    {
        complex <float> gen_noise(cos(((float)rand() / (float)(RAND_MAX))), sin(((float)rand() / (float)(RAND_MAX))));
            noise_real[k] = sqrt(0.5)*gen_noise.real();
            noise_imag[k] = sqrt(0.5)*gen_noise.imag();
            cout << "Noise " << gen_noise << endl;
    }
    cout << "Noise Real Samples" << endl;
    displayVec((float *)noise_real, m, 1);
    cout << "Noise Imaginary Samples" << endl;
    displayVec((float *)noise_imag, m, 1);
    // the nose and signal array is now in Nx1 format, this was done with pre-forming of array values
    // generate wireless received signal
    // One way for now would be to make this work only for a 2x2 channel
    float M_real[m], M_imag[m];
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (i==0&&j==0 || i==0&&j==1 || i==1&&j==0 || i==1&&j==1)
            {
                M_real[0] = {H_real[0][0]*x_real[0] +  H_real[0][1]*x_real[1]};
                M_real[1] = {H_real[1][1]*x_real[0] +  H_real[1][1]*x_real[1]};
                M_imag[0] = {H_imag[0][0]*x_imag[0] +  H_imag[0][1]*x_imag[1]};
                M_imag[1] = {H_imag[1][1]*x_imag[0] +  H_imag[1][1]*x_imag[1]};
            }
            
        }
    }
    float y_real[m], y_imag[m];
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < 1; ++j)
        {
         y_real[i] = M_real[i] + pow(10, (-snr_db/20))*noise_real[i]; // SNR is included with noise
         y_imag[i] = M_real[i] + pow(10, (-snr_db/20))*noise_real[i];
        }
    }
    cout << "The real components of received signal" << endl;
    displayVec((float *) y_real, m, 1);
    cout << "The imaginary components of received signal" << endl;
    displayVec((float *)y_imag, m, 1);
    // The next few lines are debug to understand array and matrice (2d arrays)
    // cout << " VEC DBG" << endl;
    // for (int i = 0; i < m; ++i)
    // {
    //     for (int j = 0; j < 1; ++j)
    //     {
    //         /* code */
    //         cout << x_real[i] << '\t' << "i row" << i << '\t'  << "j col" << j << endl;
    //     }
    // }
    // cout << " MTX DBG" << endl;
    // for (int i = 0; i < m; ++i)
    // {
    //     for (int j = 0; j < m; ++j)
    //     {
    //         /* code */
    //         cout << H_real[i][j] << '\t' << "i row" << i << '\t'  << "j col" << j << endl;
    //     }
    // }
    
    
} 

