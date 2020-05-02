
#include<iostream>
#include<bits/stdc++.h>
#define ll long long int
#define N 1000
#define ff(i,l,n) for(ll i=l;i<n;i++)

using namespace std;
ll getCoins(ll arr[N],ll n,ll total)
{
    ll ways[N]={0};

    ways[0]=1;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<=total;j++)
        {
            if(arr[i]<=j)
            {
                //cout<<"array: "<<j-arr[i]<<" ";
                ways[j]=ways[j-arr[i]]+ways[j];
            }
        }
        // ff(i,0,total)
        //      cout<<ways[i]<<" ";
        // cout<<endl;
    }

    
    return ways[total];
}

using namespace std;
int main()
{
    ll n,arr[N];
    ll total;
    cin>>total>>n;
    ff(i,0,n)
    {
        cin>>arr[i];
    }
cout<<getCoins(arr,n,total)<<endl;
return 0;
} 

