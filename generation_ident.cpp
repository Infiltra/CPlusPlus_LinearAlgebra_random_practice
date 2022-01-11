#include<iostream>

using namespace std;

int m;
void display(int *arr, int m){
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << *((arr+i*m)+j) << "\t";
        }
        cout << endl;
    }
    
}
int generateIdent(){
    int arra[m][m];
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (i==j)
            {
                arra[i][j] = 1; 
            }
            else
                arra[i][j] = 0;
            
        }
    }
    display((int *)arra, m);
    return arra[m][m];
}

int main(){
    //generate identity matrix of size m, c r==m
    cout << "Enter the size of the matrix" << endl;
    cin >> m;
    cout << "Size of matrix " << m << " x " << m << endl;
    generateIdent();
}
