#include <stdio.h>
#include <stdlib.h>
#define N 10

int partition(int a[N],int l,int r)
{
    int p=a[l];
    int i=l+1;
    int j;
    int temp=-1;
    for(j=l+1;j<=r;j++)
    {
        if(a[j]<p)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i=i+1;
        }
    }

        temp=a[i-1];
        a[i-1]=a[l];
        a[l]=temp;
        return i-1;
}


void quicksort(int a[N],int l,int r)
{
    if(l<r)
    {
    int s=partition(a,l,r);
    quicksort(a,l,s-1);
    quicksort(a,s+1,r);
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
    quicksort(a,0,n-1);
    print(a,n);
    return 0;
}


