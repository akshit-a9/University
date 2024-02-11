#include<stdio.h>
#include<stdlib.h>

// Menu Driven single linked list program

struct node
{
    int data;
    struct node *next;
}*head;
void menu()
{
    printf("\n\n\n1.Create a linked list\n2.Display the entire liked list\n3.Enter a node at the beginning\n4.Enter a node at the end\n5.Enter a node after a node\n6.Delete a node from the beginning\n7.Delete a node from the end\n8.Delete a node after a node\n9.Delete entire list\n10.Exit\n\n\n");
}
void Create()
{
    int n;
    struct node *temp;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    head = malloc(sizeof(struct node));
    printf("Enter the data for node 1: ");
    scanf("%d", &head->data);
    head->next = NULL;
    temp = head;
    for (int i = 2; i <= n; i++)
    {
        struct node *new_node = malloc(sizeof(struct node));
        printf("Enter the data for node %d: ", i);
        scanf("%d", &new_node->data);
        new_node->next = NULL;
        temp->next = new_node;
        temp = new_node;
    }
}

void Display()
{
    struct node *temp = head;
    if(temp == NULL) printf("The list is empty!");
    else
    {
        while(temp != NULL) 
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    } 
}

void enterBeg()
{
    
    struct node *new_node;
    if (head == NULL) printf("Linked list is empty, create a new list!");
    else
    {
        new_node = malloc(sizeof(struct node));
        printf("Enter the data you want to insert: ");
        scanf("%d", &new_node->data);
        new_node->next = head;
        head = new_node;
        
    }

}

void enterEnd()
{
    struct node *temp = head, *new_node = NULL;
    if(head == NULL) printf("The list is empty!");
    else
    {
        new_node = malloc(sizeof(struct node));
        printf("Enter the data you want to insert: ");
        scanf("%d", &new_node->data);
        while(temp->next != NULL) temp = temp->next;
        temp->next = new_node;
        new_node->next = NULL;
        
    }
}

void enterAfter()
{
    int val, count = 0;
    struct node *temp = head, *new_node;
    if(head == NULL) printf("The list is empty!");
    else
    {
        printf("Enter the index of the node after which you want to add a new node: ");
        scanf("%d", &val);
        new_node = malloc(sizeof(struct node));
        printf("Enter the data you want to insert: ");
        scanf("%d", &new_node->data);
        new_node->next = NULL;
        while(count != val)
        {
            temp = temp->next;
            count++;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}
void delBeg()
{
    struct node *temp = head;
    head = head->next;
    free(temp);
    temp = NULL;
}

void delEnd()
{
    struct node *temp = head, *ptr = head;
    while (temp->next != NULL)
    {
        ptr = temp;
        temp = temp->next;
    }
    ptr->next = NULL;
    free(temp);
    temp = NULL;
}
void delAfter()
{
    int val, count = 0;
    struct node *temp = head, *ptr;
    if(head == NULL) printf("The list is empty!");
    else
    {
        printf("Enter the index of the node after which you want to delete a node: ");
        scanf("%d", &val);
        while(count != val)
        {
            temp = temp->next;
            count++;
        }
        ptr = temp->next;
        temp->next = temp->next->next;
        free(ptr);
        ptr = NULL;
    }
}
void delEnt()
{
   if(head == NULL) printf("The list is empty!");
    else
    {
        head = NULL;
        printf("Succesfully Deleted!\n");
    }  
}
int main()
{
    int a = 1;
    while(a == 1)
    {
        menu();
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case(1):Create(); break;
            case(2):Display(); break;
            case(3):enterBeg(); break;
            case(4):enterEnd(); break;
            case(5):enterAfter(); break;
            case(6):delBeg(); break;
            case(7):delEnd(); break;
            case(8):delAfter(); break;
            case(9):delEnt(); break;
            case(10):a = 0; break;
        }
    }
    
}