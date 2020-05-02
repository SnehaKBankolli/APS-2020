// C++ program to Count set 
// bits in an integer 
#include <bits/stdc++.h> 
using namespace std; 
  
/* Function to get no of set bits in binary 
representation of positive integer n */
unsigned int countSetBits(unsigned int n) 
{ 
    unsigned int count = 0; 
    while (n) { 
        count += n & 1; 
        n >>= 1; 
    } 
    return count; 
} 

int main()
{
    unsigned int n,temp,sum=0;
    cin>>n;
    for(unsigned int i=0;i<n;i++)
    {
        cin>>temp;
        sum=sum+countSetBits(temp);
    }
    cout<<sum<<endl;
    return 0;
}

