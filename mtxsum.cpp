#include<iostream>
#include<math.h>

using namespace std;

int main(){
    float a[2][2], b[2][2], s[2][2];

    //Taking input using nested for loop
    cout << "Enter elements of first matrix" << endl;
    for(int i=0;i<2;++i){
        for (int j = 0; j < 2; ++j)
        {
            cin >> a[i][j];
        }
    }
    cout << "Enter elements of second matrix" << endl;
    for (int i = 0; i < 2; ++i){
        for (int j = 0; j < 2; ++j)
        {
             cin >> b[i][j];
        }
       
    }
    
        //display the elements of matrix
        cout << "Elements of first matrix" << endl;
        for (int i = 0; i < 2; ++i){
            for (int j = 0; j < 2; ++j){
                cout << a[i][j] << "\t";
            }
            cout << endl;
        }
        cout << "Elements of second matrix" << endl;
        for (int i = 0; i < 2; ++i){
            for (int j = 0; j < 2; ++j){
                cout << b[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
        //calculate sum of matrices
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                s[i][j] = a[i][j] + b[i][j];
            }
        }
        cout << "Sum of the matrices" << endl;
        for (int i = 0; i < 2; ++i){
            for (int j = 0; j < 2; ++j){
                cout << s[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
        
    return 0;
}
