#include <stdio.h>
#include <stdlib.h>
#define MAXQUEUE 5
#define TRUE 1
#define FALSE 0

struct pqueue
{
    int front;
    int rear;
    int items[MAXQUEUE];
};
typedef struct pqueue PQUEUE;

int empty(PQUEUE *pq)
{
    if(pq->front==0 && pq->rear==-1)
        return TRUE;
    else
        return FALSE;
}

int full(PQUEUE *pq)
{
    if(pq->rear == MAXQUEUE-1)
        return TRUE;
    else
        return FALSE;
}

void compaction(PQUEUE *pq){
int i=0,j=0;
for(i=0;i<pq->rear;i++)
    {
       if(pq->items[i]==-1)
       {
           for(j=i;j<pq->rear;j++)
               pq->items[j]=pq->items[j+1];
               (pq->rear)--;

       }
    }

    if(pq->items[pq->rear]==-1)
    {
        pq->rear--;
    }

}

void Enqueue(PQUEUE *pq,int x,int *poverflow){
if(full(pq)){
    compaction(pq);

    if(full(pq)){
        *poverflow=TRUE;
        return;
    }
}
*poverflow=FALSE;
(pq->rear)++;
pq->items[pq->rear]=x;
}

void Dequeue(PQUEUE *pq,int *px,int *punderflow)
{
    *punderflow=TRUE;
    if(empty(pq))
    {
        return;
    }

    else{

        compaction(pq);
        if(empty(pq))
            return;

        *punderflow=FALSE;
        int dequeue_data=0,dequeue_index=0,i=0;
        dequeue_data=pq->items[pq->front];

        for(i=1;i<=pq->rear;i++)
        {
            if(pq->items[i]<dequeue_data)
            {
                dequeue_data=pq->items[i];
                dequeue_index=i;
            }
        }

        *px=pq->items[dequeue_index];
        pq->items[dequeue_index]=-1;
    }
}

void Display(PQUEUE q)
{
    while(q.front<=q.rear)
    {
        if(q.items[q.front]!=-1)
        printf("%d\t",q.items[q.front]);
        q.front++;
    }
    printf("\n");
    return;
}



int main()
{
    int choice=0,x;
    int overflow=0,underflow=0;
    PQUEUE q;
    q.front=0;
    q.rear=-1;
    while(1)
    {
        printf("\n****MENU****\n");
        printf("1-Enqueue\n");
        printf("2-Dequeue\n");
        printf("3-Display\n");
        printf("4-Exit\n");
        printf("*****************\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:printf("Enter the item to be inserted\n");
                   scanf("%d",&x);
                   Enqueue(&q,x,&overflow);
                   if(overflow)
                        printf("PQUEUE FULL.\n");
                    else
                        printf("Item insertion successful");
                    break;

            case 2:Dequeue(&q,&x,&underflow);
                if(underflow)
                    printf("Empty queue\n");
                else
                    printf("%d removed\n",x);
                break;

          case 3:if(empty(&q))
                printf("Pqueue is empty\n");
                else
                    Display(q);
                break;

        case 4:printf("Exiting..\n");
                exit(0);


        }
    }
    return 0;
}
