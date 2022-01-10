
#include<iostream>
#include<iomanip>
#include<random>
#include<cmath>

#define RAND_MAX 360
using namespace std;
double thetar;

void display(double *arr, int m, int n){
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << *((arr+i*n)+j) << "\t";
        }
        cout << endl;
    }
    
}

//generate random numbers
double genRV(){
    /* Generate a random theta here for the rotation matrix */  
   double theta =  1+rand()/(100000000);
   return theta;
}

int main(){
   srand(time(nullptr)); // use time as seed
   double rv = rand();
   double thetar = genRV();
   
   
    // try doing a rotational transformaiton of the generated nx1 vector
   // try generating a random array
   double rarr[2][1];
   //generate a separate rv for phase rotation theta
   for (int i = 0; i < 2; ++i)
   {
       for (int j = 0; j < 1; ++j)
       {
           /* code */
           rarr[i][j] = (1+rand())/((100000000));
       }
   }
    cout << "Vector" << endl;
    display((double *)rarr, 2, 1);
    double TMtx[2][2];
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            if (i==0&j==0)
            {
                /* fill transform [0][0] element*/
                TMtx[0][0] = cos(thetar);
            }else if(i==0&&j==1){
                TMtx[0][1] = -sin(thetar);
            }else if (i==1&&j==0)
            {
                TMtx[1][0] = sin(thetar);
            }else
                TMtx[1][1] = cos(thetar);   
        }
    }
    
    cout << "Rotation Matrix" << endl;
    display((double *)TMtx, 2, 2);
    // multiplication part
    double RMtx[2][1];
    for (int  k = 0; k < 2; ++k)
    {
        for (int l = 0; l < 1; ++l)
        {
            if (k==0&&l==0)
            {
                RMtx[0][0] = (TMtx[0][0]*rarr[0][0])+(TMtx[0][1]*rarr[1][0]);
            }else if (k==1&&l==0)
            {
                RMtx[1][0] = (TMtx[1][0]*rarr[0][0])+(TMtx[1][1]*rarr[1][0]);
            }
            
            
        }
    }
    cout << "Rotated Vector" << endl;
   display((double *)RMtx, 2, 1);
//    cout << TMtx[0][0] << TMtx[0][1] << TMtx[1][0] << TMtx[1][1] << TMtx[2][0] << endl;
}