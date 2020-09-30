#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* head=NULL;
int top=0;
int add_beg(int no)
{
    
        struct node * temp=(struct node *)malloc(sizeof( struct node));
        temp->data=no;
        temp->next=head;
        head=temp;
        top++;
        return 1;
    
    
}
int del_beg()
{
    if(head!=NULL)
    {
        head=head->next;
        top--;
        return 1;
    }
    else
    {
        printf("Stack Underflow");
        return -1;
    }
    
}
int print_list()
{
    if(top!=0)
    {
        struct node * temp=(struct node *)malloc(sizeof( struct node));
         temp=head;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        return 1;
    }
    else
    {
        printf("Stack is empty");
        return -1;
    }
    

}
int update(int index,int no_change)
{
    if(index<=top&&index>=1)
    {
         struct node * temp=(struct node *)malloc(sizeof( struct node));
         temp=head;
        for(int i=1;i!=index;i++)
        {
           // printf("%d ",temp->data);
         temp=temp->next;
        }
        temp->data=no_change;
        return 1;
    }
    else
    {
        printf("Indexed item not present in stack");
        return -1;
    }
    
}
int is_paranthesis(char exp)
{
    if(exp=='(')
    {
        return 1;
    }
    else if(exp==')')
    {
        return 2;
    }
    else
    {
        return 0;
    }
    
}
int is_empty()
{
    if(top==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}














