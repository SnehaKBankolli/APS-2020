#include <iostream>
#include <bits/stdc++.h>
#define N 1000
#define f for
#define  ll long long int
using namespace std;

ll lcs(string s1,string s2)
{
   ll a[N][N]={0};
   
   f(ll i=1;i<=s1.size();i++)
   {
       for(ll j=1;j<=s2.size();j++)
       {
           a[i][j]=max(a[i-1][j],a[i][j-1]);
           if(s1[i-1]==s2[j-1])
           {
               a[i][j]=a[i-1][j-1]+1;
           }
           
       }
   }
   //cout<<s1<<endl;
   //cout<<s2<<endl;

   
   return a[s1.size()][s2.size()];
}

int main() {
    
    string s1;
    string s2;
    
    cin>>s1>>s2;
    cout<<lcs(s1,s2)<<endl;
    
    return 0;
}

