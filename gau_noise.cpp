/* Include requisits */
#include <cstdlib>
#include <ctime>
#include<iostream>

using namespace std;

/* Generate a new random seed from system time - do this once in your constructor */
int main(){
    srand(time(0));

    /* Setup constants */
    const static int q = 15;
    const static float c1 = (1 << q) - 1;
    cout << "q " << c1 << endl;
    const static float c2 = ((int)(c1 / 3)) + 1;
    const static float c3 = 1.f / c1;

    /* random number in range 0 - 1 not including 1 */
    float random;

    /* the white noise */
    //float noise = 0.f;

    int numSamples;
    cout << "Enter number of samples" << endl;
    cin >> numSamples;
    float noise[numSamples];

    for (int i = 0; i < numSamples; i++)
    {
        random = ((float)rand() / (float)(RAND_MAX));
        noise[i] = (2.f * ((random * c2) + (random * c2) + (random * c2)) - 3.f * (c2 - 1.f)) * c3;
        cout << noise[i] << endl;
    }
}