#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector<int> v[20];
    int n,temp;
    cin>>n;
    int temper=-1;
    int count=0;
    int flag=0;
    vector<int> v2;
    
    vector<int> p(n);
    for(unsigned long long int i=0;i<n;i++)
    {
        flag=0;
        temper=-1;
        for(unsigned long long int j=0;j<n;j++)
        {
            cin>>temp;
            v[i].push_back(temp);
            //cout<<temp<<" ";
            if(find(v2.begin(),v2.end(),temp)==v2.end() && temp!=-1 && flag==0)
            {
            //cout<<temp<<endl;
            v2.push_back(temp);
            count++;
            flag=1;
            }
            
     
        }
        //cout<<endl;
       // cout<<temper<<endl;
        
    }
    //cout<<v2.size()<<endl;
    if(v2.size()==n)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    // for(int i=0;i<v2.size();i++)
    // {
    //     cout<<v2[i]<<endl;
    // }
    for(long long int i=1;i<=n;i++)
    {
        
         if(find(v2.begin(),v2.end(),i)==v2.end() && *v2.end()!=i)
              cout<<i<<endl;
    }
        
     return 0;
}

