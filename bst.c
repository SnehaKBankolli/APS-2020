#include <stdio.h>
#include <stdlib.h>

struct tree{

int data;
struct tree * left;
struct tree * right;
};

typedef struct tree TREE;

TREE * insert_in_bst(TREE * root)
{
    TREE * newnode =(TREE*)malloc(sizeof(TREE));
    if(newnode == NULL)
    {
        printf("No memory allocated\n");
        return root;
    }
    newnode->left=NULL;
    newnode->right=NULL;
    printf("Enter the data\n");
    scanf("%d",&newnode->data);

    if(root == NULL)
    {
        printf("Root created\n");
        return newnode;
    }

    else{
         TREE * curr=root;
         TREE * prev=NULL;
         while(curr != NULL)
         {
             prev=curr;
             if(newnode->data<curr->data)
             {
                 curr=curr->left;
             }
             else
                curr=curr->right;

         }
         if(prev->data>newnode->data)
         {
             prev->left=newnode;
         }
         else
             prev->right=newnode;
    }

    printf("Node attached\n");
    return root;
}

void inorder(TREE * root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
}

void preorder(TREE * root)
{
    if(root == NULL)
        return;
    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->right);
}


TREE * delete_from_bst(TREE * root)
{
    if(root == NULL)
    {
        printf("No tree\n");
        return root;
    }

    printf("Enter the item to be deleted\n");
    int item;
    scanf("%d",&item);
    TREE * p;
    TREE * successor;
    TREE * parent;
    TREE *curr;
    curr=root;
    parent=NULL;

    while(curr!= NULL && curr->data!=item)
    {
        if(curr->data>item)
        {
            curr=curr->left;
        }
        else
            curr=curr->right;
    }

    if(curr == NULL)
    {
        printf("ITEM NOT FOUND\n");
        return root;
    }

    if(curr->left==NULL)
        p=curr->right;

    else if(curr->right == NULL)
        p=curr->left;

    else{
        successor=curr->right;
        while(successor->left!=NULL)
        {
            successor=successor->left;
        }
        successor->left=curr->left;
        p=curr->right;
    }

    if(parent == NULL)
    {
        free(root);
        return p;
    }

    if(parent->left == curr)
    {
        parent->left=p;
    }
    else
        parent->right=p;

    free(curr);
    return root;

}

void postorder(TREE * root)
{
    if(root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d\t",root->data);
}


int main()
{
    TREE * root = NULL;
    int choice=0;
    while(1)
    {
        printf("MEnu\n1.insert\n2.inorder\n3.preorder\n4.postorder\n5.delete\n6.exit\n");
        printf("Enter choice\n");
        scanf("%d",&choice);
        switch(choice){

        case 1:root=insert_in_bst(root);
                break;
        case 2:inorder(root);
                break;

        case 3:preorder(root);
                break;

        case 4:postorder(root);
                break;

        case 5:root=delete_from_bst(root);
              break;

        case 6:exit(0);

        default:printf("Wrong option\n");
        }
    }


    return 0;
}
