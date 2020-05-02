#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<limits.h>


int main()
{
    int n , q , i,max1=INT_MAX,index;
    scanf("%d%d",&n,&q) ;
    int arr[n] ;
    for(i=0;i<n;i++)    {
        scanf("%d",&arr[i]) ;
        if(arr[i]<max1)
        {
            max1=arr[i];
            index=i;
            
        }
    }
    while(q--)
    {
        int s , e , min = INT_MAX ;
        scanf("%d%d",&s,&e) ;
        if(index>=s && index<=e)
             printf("%d\n",max1) ;
        else{
        for(i=s;i<=e;i++)
        {
            if(min>arr[i])
                min = arr[i] ;
        }
        printf("%d\n",min) ;
        }
    }
    return 0;
}
