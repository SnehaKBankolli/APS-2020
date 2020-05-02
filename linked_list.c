#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

struct node{
int data;
struct node * next;
};
typedef struct node NODE;

NODE * insert_at_start(NODE * start)
{
    NODE * newnode = (NODE*)malloc(sizeof(NODE));

    if(newnode == NULL)
    {
        printf("Memory is not allocated\n");
        return start;
    }

    newnode->next=NULL;
    printf("Enter the data\n");
    scanf("%d",&newnode->data);
    if(start == NULL)
    {
        printf("Root created\n");
        return newnode;
    }

    else
    {
            newnode->next=start;
            return newnode;
    }

}


NODE * insert_at_end(NODE * start){

    NODE * newnode = (NODE*)malloc(sizeof(NODE));

    if(newnode == NULL)
    {
        printf("Memory is not allocated\n");
        return start;
    }

    newnode->next=NULL;

    printf("Enter the data\n");
    scanf("%d",&newnode->data);

    if(start == NULL)
    {
        printf("Root created\n");
        return newnode;
    }

    NODE * curr=start;
    while(curr->next != NULL)
    {
       curr=curr->next;
    }

    curr->next=newnode;

    return start;

}

void print(NODE * start){

NODE * newnode=start;
while(newnode!= NULL)
{
    printf("%d\t",newnode->data);
    newnode=newnode->next;
}
printf("\n");

}

NODE * delete_from_start(NODE * start){

if(start == NULL)
{
    printf("The list is empty\n");
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
        NODE * newnode=start;
        start=start->next;
        free(newnode);
        return start;
    }

}


NODE * delete_from_end(NODE * start)
{
    if(start == NULL)
{
    printf("The list is empty\n");
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
        NODE * curr = start;
        NODE * prev = NULL;
        while(curr->next!=NULL)
        {
            prev=curr;
            curr=curr->next;
        }

        free(curr);
        prev->next=NULL;
        return start;
    }

}

NODE * delete_at_any_postion(NODE * start)
{
    printf("enter the position where item is to be deleted\n");
    int pos;
    scanf("%d",&pos);

    if(start == NULL)
    {
        printf("List is empty\n");
        return(start);
    }

    if(start->next == NULL)
    {
        printf("Start is deleted\n");
        free(start);
        start=NULL;
        return(start);
    }
    else{
    NODE * curr=start;
    NODE * prev=NULL;
    int i=0;
    while(curr!=NULL && i<pos)
    {
        prev=curr;
        curr=curr->next;
        i++;
    }


    printf("%d this is that data\n",curr->data);
    printf("%d prev",prev->data);
    if(curr == NULL)
        {
            printf("Invalid Position\n");
            return start;
        }

        prev->next=curr->next;
        free(curr);
        return start;

    }
    return start;
}

NODE * insert_at_postition(NODE * start)
{
    NODE * newnode=(NODE*)malloc(sizeof(NODE));
    newnode->next=NULL;
    if(newnode == NULL)
    {
            printf("No data is allocated\n");
            return start;
    }

    printf("Enter the data\n");
    scanf("%d",&newnode->data);

    if(start==NULL)
    {
        printf("Newnode is created\n");
        start=newnode;
    }
    else{
        printf("Enter the position to be inserted:\n");
        int pos=0;
        scanf("%d",&pos);
        NODE * curr = start;
        NODE * prev = NULL;
        int i=0;
        while(curr!=NULL && i<pos)
        {
            prev=curr;
            curr=curr->next;
            i++;
        }

        if(curr == NULL)
            {
            printf("Invalid index\n");
            return start;
            }

            newnode->next=curr;
            prev->next=newnode;
            return start;

    }

    return start;
}

int main()
{
        NODE * start=NULL;

        int choice=1;

        while(1)
        {
            printf("Enter the choice:\n");
            printf("MENU:\n1.Insert at start\n2.Print\n3.insert_at_end\n4.delete_from_start\n5.delete_from_end\n6.Delete at any position\n7.Insert at position\n8.Exit\n");
            scanf("%d",&choice);
            switch(choice){


                case 1:printf("Insert at start\n");
                       start=insert_at_start(start);
                       break;

                case 2:printf("Print\n");
                       print(start);
                       break;


                case 3:start=insert_at_end(start);
                       break;

                case 4:start=delete_from_start(start);
                       break;

                case 5:start=delete_from_end(start);
                       break;

                case 6:printf("Delete from any position:\n");
                        start=delete_at_any_postion(start);
                        break;

                case 7:printf("Insert at given position:\n");
                       start=insert_at_postition(start);
                       break;

                case 8: printf("Exit\n");
                        printf("Exiting program\n");
                        exit(0);


            }
        }
}
