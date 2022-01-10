#include<iostream>
#include<cstdint>
#include<bit>
#include<bitset>

using namespace  std;
int main(){
    uint8_t i = 0b00011101;
    cout << "i = " << bitset<8>(i) << '\n';
    cout << "rotl(i,0) = " << bitset<8>(__rotl(i,0)) << '\n';    
    cout << "rotl(i,1) = " << bitset<8>(__rotl(i,1)) << '\n';    
    cout << "rotl(i,-1) = " << bitset<8>(__rotl(i,-1)) << '\n';  
    cout << "rotr(i,0) = " << bitset<8>(__rotr(i,0)) << '\n';      
    cout << "rotr(i,1) = " << bitset<8>(__rotl(i,1)) << '\n';
    cout << "rotr(i,-1) = " << bitset<8>(__rotl(i,-1)) << '\n';
    uint8_t p = __rotl(i,-1);
    cout << p << endl;

    //check if rotr and rotl -1 are the same
    // if (bitset<8>(__rotl(i,-1)) & bitset<8>(__rotr(i,-1)) == 0)
    // {
    //     /* code */
    // }
    
} 
