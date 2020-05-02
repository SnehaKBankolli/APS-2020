#include<iostream>
#include<bits/stdc++.h>
using namespace std;  

int setBitNumber2(int n) 
{ 
    // Below steps set bits after 
    // MSB (including MSB) 
  
    // Suppose n is 273 (binary 
    // is 100010001). It does following 
    // 100010001 | 010001000 = 110011001 
    n |= n >> 1; 
  
    // This makes sure 4 bits 
    // (From MSB and including MSB) 
    // are set. It does following 
    // 110011001 | 001100110 = 111111111 
    n |= n >> 2; 
  
    n |= n >> 4; 
    n |= n >> 8; 
    n |= n >> 16; 
  
    // Increment n by 1 so that 
    // there is only one set bit 
    // which is just before original 
    // MSB. n now becomes 1000000000 
    n = n + 1; 
  
    // Return original MSB after shifting. 
    // n now becomes 100000000 
    return (n >> 1); 
} 

int setBitNumber1(int n) 
{ 
    // To find the position 
    // of the most significant 
    // set bit 
    int k = (int)(log2(n)); 
  
    // To return the the value 
    // of the number with set 
    // bit at k-th position 
    return (int)(pow(2, k)); 
} 

int main() 
{ 
    int n = 273; 
    cout << setBitNumber1(n); 
    cout << setBitNumber2(n); 
    return 0; 
} 
