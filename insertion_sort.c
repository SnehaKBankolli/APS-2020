#include <stdio.h>
#include <stdlib.h>
#define N 10


void insertion_sort(int a[N],int n)
{
    int i=0;
    int j=0;
    int v=0;
    for(i=1;i<n;i++)
    {
        v=a[i];
        j=i-1;
        while(j>=0 && a[j]>v)
        {

            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=v;
    }
}

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


int main()
{
    printf("Enter the size of the array:\n");
    int n;
    int a[N]={0};
    scanf("%d",&n);
    read(a,n);
    print(a,n);
    insertion_sort(a,n);
    print(a,n);


}


