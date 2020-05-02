#include <stdio.h>
#include <stdlib.h>
#define N 10



void read(int a[N],int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

}

void print(int a[N],int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}

void heapsort(int a[N],int n)
{
    int i=n/2;
    int k=0;
    int j=0;
    int heap=0;
    int v=0;
    for(i=n/2;i>=1;i--)
    {
        k=i;
        v=a[k];
        heap=0;
        while(!heap && 2*k<=n)
        {
            j=2*k;
            if(j<n)
            {
                if(a[j]<a[j+1])
                {
                    j=j+1;
                }

               if(v>=a[j])
               {
                   heap=1;
               }

               else
               {
                   a[k]=a[j];
                   k=j;
               }
               a[k]=v;
            }
        }
    }
}




int main()
{
    printf("Enter the size of the array:\n");
    int n;
    int a[N]={0};
    scanf("%d",&n);
    read(a,n);
    heapsort(a,n);
    print(a,n);



}


