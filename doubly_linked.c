#include <stdio.h>
#include <stdlib.h>

struct node{
int data;
struct node * next;
struct node * prev;
};

typedef struct node NODE;
NODE * insert_at_end(NODE * start){

    NODE * newnode=(NODE*)malloc(sizeof(NODE));
    if(newnode == NULL)
    {
        printf("Memory not allocated\n");
        return start;
    }
    newnode->next=NULL;
    newnode->prev=NULL;

    printf("Enter the data\n");
    scanf("%d",&newnode->data);

    if(start==NULL)
    {
        start=newnode;
        return start;
    }
    else{
        NODE * curr=start;
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }

        curr->next=newnode;
        newnode->prev=curr;
        return start;
    }
    return start;

}

NODE * insert_at_start(NODE * start){

    NODE * newnode = (NODE*)malloc(sizeof(NODE));



    if(newnode == NULL)
    {
        printf("Memory not allocated\n");
        return start;
    }
    newnode->next=NULL;
    newnode->prev=NULL;
    printf("Enter the data:\n");
    scanf("%d",&newnode->data);
    if(start==NULL)
    {
            printf("Enter the root\n");
            start=newnode;
            return start;
    }

    else{

        newnode->next=start;
        start->prev=newnode;
        start=newnode;
        return start;
        }

}

NODE * delete_from_start(NODE * start){

if(start==NULL)
{
    printf("List is empty\n");
    return start;
}

if(start->next == NULL)
{
    printf("Root is deleted\n");
    free(start);
    start=NULL;
    return start;
}
else{
    NODE * temp=start;
    start=start->next;
    free(temp);
    return(start);
}
return start;
}

NODE * delete_from_end(NODE * start){
    if(start == NULL)
    {
        printf("List is empty\n");
        return start;
    }

    if(start->next == NULL)
    {
        printf("start is deleted\n");
        free(start);
        start=NULL;
        return start;
    }
    else{

        NODE *curr=start;

        while(curr->next!=NULL)
        {
            curr=curr->next;
        }

        curr->prev->next=NULL;
        free(curr);
        return start;
    }
    return start;

}

NODE * delete_from_position(NODE * start){

if(start == NULL)
{
    printf("The list is empty\n");
    return start;
}

if(start->next == NULL)
 {
 printf("Deleting start\n");
    free(start);
    start=NULL;
    return start;
 }
int t;
int i=0;
printf("Enter the position of deletion:\n");
scanf("%d",&t);
NODE * temp=start;
 while(temp!=NULL && i<t)
 {
     temp=temp->next;
     i++;
 }

 temp->prev->next=temp->next;
 temp->next->prev=temp->prev;
 free(temp);
 return start;
}

NODE*add_from_position(NODE * start)
{
    NODE * temp=(NODE*)malloc(sizeof(NODE));
    if(temp == NULL)
    {
        printf("The memory was not allocated\n");
        return start;
    }
    if(start==NULL)
    {
        printf("The list is empty\n");
        return start;
    }

    temp->next=NULL;
    temp->prev=NULL;

    printf("Enter the data to be entered:\n");
    scanf("%d",&temp->data);

    printf("Enter the position:\n");
    int x;
    scanf("%d",&x);
    NODE * currnode=start;
    int i=0;
    while(currnode!=NULL && i<x)
    {
        currnode=currnode->next;
        i++;
    }

    currnode->prev->next=temp;
    currnode->prev=temp;
    temp->next=currnode;
    temp->prev=currnode->prev;
    return start;

}


void print(NODE * start)
{
    NODE * temp=start;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
        NODE * start=NULL;
        int choice=0;
        while(1)
        {
        printf("Enter the choice:\n");
        printf("1.insert_at_start\n2.insert_at_end\n3.delete_from_start\n4.delete_from_end\n5.delete_from_position\n6.add_from_position\n7.print\n8.exit");
        scanf("%d",&choice);
        switch(choice){

            case 1:start=insert_at_start(start);
                   break;

            case 2:start=insert_at_end(start);
                   break;

            case 3:start=delete_from_start(start);
                    break;

            case 4:start=delete_from_end(start);
                    break;

            case 5:start=delete_from_position(start);
                   break;

            case 6:start=add_from_position(start);
                   break;

            case 7:print(start);
                   break;

            case 8:printf("Exiting..\n");
                   exit(0);

        }

    }

}



