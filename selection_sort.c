#include <stdio.h>
#include <stdlib.h>
#define N 10


void selectionSort(int a[N],int n)
{
    int i=0;
    int j=0;
    int min=0;
    int temp=0;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        temp=a[min];
        a[min]=a[i];
        a[i]=temp;
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
    selectionSort(a,n);
    print(a,n);


}


