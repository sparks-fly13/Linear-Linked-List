#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
 struct node
{
    int data;
    struct node *next;  //linear linked list
};
struct node *head=0;

void printlist()
{
    struct node *temp;
    temp=head;
    printf("The datas are: ");
    while(temp!=0)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void insertbegin()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value: ");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
}

void insertend()
{
    struct node *newnode, *temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value: ");
    scanf("%d",&newnode->data);
    newnode->next=0;
    temp=head;
    while(temp->next!=0)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}

void insertpos()   //inserting at a given position
{
    int pos,i=2;
    struct node *newnode, *temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter a valid position: ");
    scanf("%d",&pos);
    temp=head;
    while(i<pos)
    {
        temp=temp->next;
        i++;
    }
    printf("Enter the value: ");
    scanf("%d",&newnode->data);
    newnode->next=temp->next;
    temp->next=newnode;
}

struct node* reverse(struct node *Node)
{
    if(Node==NULL)
        return NULL;
    if(Node->next==0){
        head=Node;
        return Node;
    }
    struct node *Node1=reverse(Node->next);
    Node1->next=Node;
    Node->next=0;
    return Node;
}

int deletebegin()
{
    struct node *temp;
    int i=0;
    if(head==0)
    {
        printf("No list present");
        exit(0);
    }
    else{
    temp=head;
    head=head->next;
    free(temp);
    i++;
    }
}

int deleteend()
{
    struct node *temp,*prev;
    if(head==0)
    {
        printf("No list present");
        exit(0);
    }
    else{
        temp=head;
        while(temp->next!=0)
        {
            prev=temp;
            temp=temp->next;
        }
        if(temp==head)
           head=0;
        else
           prev->next=0;
        free(temp);
    }
}

void deletepos()      //deleting at a given position
{
    struct node *temp, *prev;
    int pos, i=1,j=0;
    if(head==0)
      printf("The list does not exist");
    else{while(j<2){
        printf("Enter the position: ");
        scanf("%d",&pos);
        temp=head;
        while(i<pos)
        {
            prev=temp;
            temp=temp->next;
            i++;
        }
        prev->next=temp->next;
        free(temp);
        j++;}
    }
}

int main()
{
    int opt;
    label:
    printf("\n1.reverse a linked list.\n2.print a linked list\n3.Insert at beginning.\n4.Insert at end.\n5.Insert at the given position.\n6.Delete at the beginning.\n7.Delete at the end.\n8.Delete at the given position.\n9.Exit the program.\t");
    scanf("%d",&opt);
    switch(opt){
        case 1: {
            reverse(head);
            printlist();
            break;
        }
        case 2: {
            printlist(); break;
        }
        case 3: {
            insertbegin(); break;
        }
        case 4: {
            insertend(); break;
        }
        case 5: {
            insertpos(); break;
        }
        case 6: {
            deletebegin(); break;
        }
        case 7: {
            deleteend(); break;
        }
        case 8: {
            deletepos(); break;
        }
        case 9: {
            exit(0); break;
        }
    }
    goto label;
}
