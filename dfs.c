#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define N 10

int v=5;
int source=4;
int m[5][5]={{0,1,1,0,0},{1,0,0,1,1},{1,0,0,1,1},{0,1,0,0,0},{0,1,1,0,0}};
int visited[5]={0};

void print(int arr[N],int v)
{
    int i=0;
    for(i=0;i<v;i++)
    {
        printf("%d\t",arr[i]);
    }
}

void dfs(int m[5][5],int source,int v)
{
    int i=0;
    visited[source]=1;
    for(i=0;i<v;i++)
    {
        if(m[source][i] == 1 && visited[i]==0)
        {
            printf("%d\t",i);
            dfs(m,i,v);
        }
    }
}

void bfs(int m[5][5],int source,int v)
{
    int queue[10]={0},front=0,rear=0,u=0;
    int visited[5]={0};
    int i=0;

    visited[source]=1;
    queue[rear]=source;

    printf("The bfs is:\n");

    while(front<=rear)
    {
        u=queue[front];
        printf("%d\t",queue[front]);
        front++;

        for(i=0;i<v;i++)
        {
            if(visited[i]==0 && m[u][i]== 1)
            {
                visited[i]=1;
                rear++;
                queue[rear]=i;

            }

        }


    }


}

void da(int cost[N][N],int v,int source,int destination,int distance[N],int path[N])
{
        int j=0;
        int selected[N];
        int i=0;
        int min=99999;
        int index=-1;

         for(i=0;i<v;i++)
        {
            selected[i]=0;
            distance[i]=cost[source][i];
            path[i]=source;
        }

        selected[source]=1;
    for(j=0;j<v;j++)
    {

         min=999999;
         index=-1;

        printf("This is j %d\n",j);
        for(i=0;i<v;i++)
        {
            printf("%d selected key\n",selected[i]);
            printf("%d minimum value \n",distance);
            if(selected[i] == 0 && distance[i]<=min)
            {
                min=distance[i];
                index=i;
                printf("%d...INDEX\n",index);
            }

            printf("%d\n",i);
            printf("Its reaching here\n");
        }

            printf("%d INDEX\n",index);
            if(index==-1)
            {
                printf("Has the function returned\n");
                return;
                printf("Yes it has\n");
            }

            selected[index]=1;
            if(index == destination)
            {
                return;
            }



            for(i=0;i<v;i++)
            {
                if(visited[i]==0)
                {
                    if(distance[i]>(distance[index]+cost[index][i]))
                    {
                        distance[i]=distance[index]+cost[index][i];
                        path[i]=index;
                    }
                }
            }
    }
            print(distance,v);
            printf("\n");
            print(path,v);
}




int main()
{

    int source=5;
    int destination=9;
    int distance[N]={0};
    int v=6;
    int path[N]={0};
    int cost[N][N]={{0,15,10,INT_MAX,45,INT_MAX},{INT_MAX,0,15,INT_MAX,20,INT_MAX},{20,INT_MAX,0,20,INT_MAX,INT_MAX},{INT_MAX,10,INT_MAX,0,35,INT_MAX},{INT_MAX,INT_MAX,INT_MAX,30,0,INT_MAX},{INT_MAX,INT_MAX,INT_MAX,4,INT_MAX,0}};
    da(cost,v,source,destination,distance,path);

   /*
    printf("The dfs of the given graph is:\n");
    printf("%d\t",source);
    dfs(m,source,v);*/
    //bfs(m,source,v);

    return 0;

}

