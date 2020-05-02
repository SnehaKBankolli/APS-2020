#include <iostream>
#include <bits/stdc++.h>
#define N 1000
#define f for
#define  ll long long int
using namespace std;

void lcs(string s1,string s2)
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
   
   //return a[s1.size()][s2.size()];
    
    int i=s1.size();
    int j=s2.size();
    
    vector<char> st;
    while(i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            // i-=1;
            j-=1;
            i-=1;
            // j-=1;
            //cout<<s2[j]<<;
            st.push_back(s2[j]);
        }
        else if(a[i-1][j]>a[i][j-1] )
        {
            // i-=1;
            i-=1;
            // st.pub(s1[i]);
        }
        else
        {
            j-=1;
            // j-=1;
        }
        
    }
    reverse(st.begin(),st.end());
    for(auto itr=st.begin();itr<st.end();itr++)
        cout<<*itr;
        
}

int main() {
    
    string s1;
    string s2;
    
    cin>>s1>>s2;
    lcs(s1,s2);
    
    return 0;
}

