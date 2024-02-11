//Program to segregate a user input string stored in a linked list into even and odd using 3 different linked lists. 
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head, *odd, *even;

void printListeven(struct node *head)
{
    struct node *temp = even;
    int x = temp->data;

    
    while(temp != NULL)
    {
         printf("%d->", temp->data);
         temp = temp->next;
    }
    printf("NULL\n");
}
void printListodd(struct node *head)
{
    struct node *temp = odd;
    int x = temp->data;
    
    while(temp != NULL)
    {
         printf("%d->", temp->data);
         temp = temp->next;
    }
    printf("NULL\n");
}

void evennode(struct node **head,int p){
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = p;
    newNode->next= NULL;

    
    if(*head == NULL)
         *head = newNode;
    else
    {
        struct node *lastNode = *head;

       
        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }

    
        lastNode->next = newNode;
    }
}


void oddnode(struct node **head,int p){
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = p;
    newNode->next     = NULL;

    
    if(*head == NULL)
         *head = newNode;
    else
    {
        struct node *lastNode = *head;

       
        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }

    
        lastNode->next = newNode;
    }
}
int main()
{
    int n;
    struct node *temp, *new_node, *temp1 = NULL, *temp2 = NULL;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    head = malloc(sizeof(struct node));

    printf("Enter data for node 1: ");
    scanf("%d", &head->data);
    head->next = NULL;

    temp = head;

    for (int i = 2; i <= n; i++)
    {
        new_node = malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &new_node->data);
        new_node->next = NULL;
        temp->next = new_node;
        temp = temp->next;
    }

    temp = head;

    
    
    while(temp != NULL)
    {
        
        if (temp->data & 1 != 0)
        {
            
            oddnode(&odd,temp->data);
        }
        else
        {
            evennode(&even,temp->data);
        }
        temp = temp->next;
    }
    printf("even Linked List: ");
    printListeven(even);
    printf("\nodd Linked List: ");
    printListodd(odd);
}