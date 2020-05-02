#include<iostream>
#include<bits/stdc++.h>
using namespace std;  

bool ith_set_bit( int i,n){
    if(n&(1<<i))
        return true;
    return false;
}
   int main()
    {
        cout<< ith_set_bit(4)<<endl;
        cout<< ith_set_bit(23)<<endl;
        return 0;
    }
