#include<iostream>

using namespace std;
int m, n; // m rows, n cols
void display(int *arr, int m, int n){
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << *((arr+i*n)+j) << "\t";
        }
        cout << endl;
    }
    
}

void Tpose(int *arrO, int m, int n){
    // passed down as row and col interchanges in fcall
    // col first declared then row, i.e m==n and n==m
    int arrb[m][n], arra[n][m];
    for (int i = 0; i < n ; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            arra[i][j] =  *((arrO+i*m)+j);
        }
    }
    // transpose ops
   for (int i = 0; i < m; ++i)
   {
       for (int j = 0; j < n; ++j)
       {
           arrb[i][j] = arra[j][i];
           /* code */
       }
   }
   
    display((int *)arrb, m, n);
}

int main(){
    // int m, n;
    cout << "Enter the number of rows" << endl;
    cin >> m;
    cout << "Enter the number of colmns" << endl;
    cin >> n;
    int arra[m][n];
    cout << "Enter Mtx " << endl;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            /* code */
            cin >> arra[i][j];
        }
    }
    //native mtx
    cout << "native" << endl;
    display((int *)arra, m, n);
    //transpose
    cout << "Transpose" << endl;
    Tpose((int *)arra, n, m);
    return arra[m][n];
}