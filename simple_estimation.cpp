#include<iostream>
#include<complex>
#include<iomanip>

int m;

using namespace std;

void display(float *arr, int m){
    for (int i = 0; i < m; ++i)
    {
        /* code */
        cout << *(arr+i) << '\t';
    }
    cout << endl;
    
}

int main(){
    // Start generating noise
    srand(time(0));
    cout << "Enter the number of samples" << endl;
    cin >> m;
    srand(time(0));

    /* Setup constants */
    const static int q = 15;
    const static float c1 = (1 << q) - 1;
    const static float c2 = ((int)(c1 / 3)) + 1;
    const static float c3 = 1.f / c1;

    /* random number in range 0 - 1 not including 1 */
    float random;

    /* the white noise */
    //float noise = 0.f;
    float noise[m];

    for (int ii = 0; ii < m; ++ii)
    {
        random = ((float)rand() / (float)(RAND_MAX));
        noise[ii] = (2.f * ((random * c2) + (random * c2) + (random * c2)) - 3.f * (c2 - 1.f)) * c3;
    }
    //display((float *) noise, m);
    // Generate signal vector
    // The singnal vecotrs are random numbers of the value is
    // <0 then ceil to 1, >0 floor to -1
    float sgl[m], x;
    float random1;
    for (int ii = 0; ii < m; ++ii)
    {
        random1 = ((float)rand() / (float)(RAND_MAX));
        x = (2.f * ((random1 * c2) + (random1 * c2) + (random1 * c2)) - 3.f * (c2 - 1.f)) * c3;
        if (x > 0)
            sgl[ii] = 1;
        else if(x < 0)
            sgl[ii] = -1;
    }
    // generate received signal vector
    float y[m];
    for (int ii = 0; ii < m; ++ii)
    {
        /* code */
        y[ii] = sgl[ii] + noise[ii];
    }
    // Hard decision hypothesis
    float y_hat[m];
    for (int ii = 0; ii < m; ++ii)
    {
        /* code */
        if (y[ii] > 0)
        {
            y_hat[ii] = 1;
        }else if (y[ii] < 0){
            y_hat[ii] = -1;
            /* code */
        }
    }
    cout << "Noise" << endl;
    display((float *)noise, m);
    cout << "Data" << endl;
    display((float *)sgl, m);
    cout << "Received Signal" << endl;
    display((float *)y, m);
    cout << "Estimated Siganal" << endl;
    display((float *)y_hat, m);
} // namespace std;
