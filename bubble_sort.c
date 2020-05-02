#include <stdio.h>
#include <stdlib.h>
#define N 10

void bubble_sort(int a[N],int n)
{
    int i=0;
    int j=0;
    int temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
             temp=a[j];
             a[j]=a[j+1];
             a[j+1]=temp;
            }
        }
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
    bubble_sort(a,n);
    print(a,n);


}


