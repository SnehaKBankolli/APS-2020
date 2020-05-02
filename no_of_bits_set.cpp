#include<iostream>
#include<bits/stdc++.h>
using namespace std;  


int no_of_bits_set(int x)
{
     int count=0;
    while(x)
    {
        x=x&(x-1);
        count++;
    }
    return count;
}


    int main()
    {
        cout<<no_of_bits_set(4)<<endl;
        cout<<no_of_bits_set(23)<<endl;
        return 0;
    }
