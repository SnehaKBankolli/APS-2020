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

void merge(int a[N],int b[N],int c[N],int p,int q)
{
    int i=0;
    int j=0;
    int k=0;
    while(i<p&&j<q)
    {
        if(b[i]<=c[j])
        {
            a[k]=b[i];
            i++;
        }
        else
        {
            a[k]=c[j];
            j++;
        }
        k++;

    }

    if(i==p)
    {
        while(k<(p+q))
        {
            a[k]=c[j];
            k++;
            j++;
        }
    }
    else{
            while(k<(p+q))
            {
            a[k]=b[i];
            k++;
            i++;
            }

        }

}




void mergesort(int a[N],int n)
{
    if(n>1)
    {
    int i=0;
    int j=0;
    int b[N]={0};
    int c[N]={0};
    int p=0;
    int q=0;

    for(i=0;i<n/2;i++)
    {
        b[i]=a[i];
    }
    p=i;
    j=0;
    for(i=i;i<n;i++)
    {
        c[j]=a[i];
        j++;
    }
    q=j;
    //print(b,p);
    //print(c,q);
    //printf("this is the value of p=%d and q=%d\n",p,q);
    mergesort(b,p);
    //printf("It has reached here!!\n");
    mergesort(c,q);
    merge(a,b,c,p,q);
    //printf("This is b\n");
    //print(b,n/2);
    //printf("This is c\n");
    //print(c,n/2+1);
    }
}




int main()
{
    printf("Enter the size of the array:\n");
    int n;
    int a[N]={0};
    scanf("%d",&n);
    read(a,n);
    print(a,n);
    mergesort(a,n);
    print(a,n);


}


