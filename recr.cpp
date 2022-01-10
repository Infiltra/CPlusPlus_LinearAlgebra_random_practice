#include<iostream>
using namespace std;
int sum(int n);
 int main(){
     int n, result;
     cout << "Enter a number" << endl;
     cin >> n;
     result = sum(n);
     cout << "Sum " << result << endl;
     return 0;
 }
 int sum(int n){
     if(n!=0)
         //sum function calling itself
         return n+sum(n-1); //this is recursing
    else
        return n;
 }