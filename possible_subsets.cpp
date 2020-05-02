#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void possible_subsets(char a[],int n)
{
    //(1<<n): 2^n
    //0 = (000)2 = {}
    //1 = (001)2 = {c}
    //2 = (010)2 = {b}
    //3 = (011)2 = {b, c}
    //4 = (100)2 = {a}
    //5 = (101)2 = {a, c}
    //6 = (110)2 = {a, b}
    //7 = (111)2 = {a, b, c}
    for(int i=0;i<(1<<n);i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j))
            {
                cout<<a[j];
            }
        }
        cout<<endl;
    }
}

int main{
    
    char a[]={'a','b','c'};
    possible_subsets(a,3); 
    return 0;
}
