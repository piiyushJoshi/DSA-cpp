                    /** Doubly Linked Lists **/

#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node*prev;
}*head,*last;

void createlist(int n);
void displayfrombeg();
void displayfromend();
void insertatbeg();
void insertatend();
void insertatindex(int index);
void deleteatbeg();
void deleteatend();
void deleteatindex(int index);

int main()
{
    int n,data,index,choice;
    printf("Enter the number of nodes: \n");
    scanf("%d", &n);
    createlist(n);
    displayfrombeg();
    printf("Enter '1' to insert at beginning: \nEnter '2' to display list from end: \nEnter '3' to insert at index: \n");
    printf("Enter '4' to insert at end: \nEnter '5' to delete at beginnig: \nEnter '6' to delete at index: \n");
    printf("Enter '7' to delete at end: \n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
        insertatbeg();
        displayfrombeg();
        break;
        case 2:
        displayfromend();
        break;
        case 3:
        printf("Enter the node after which data is to be inserted: \n");
        scanf("%d", &index);
        insertatindex(index);
        displayfrombeg();
        break;
        case 4:
        insertatend(data);
        displayfrombeg();
        break;
        case 5:
        deleteatbeg(data);
        displayfrombeg();
        break;
        case 6:
        printf("Enter the node after whose data is to be deleted: \n");
        scanf("%d", &index);
        deleteatindex(index);
        displayfrombeg();
        break;
        case 7:
        deleteatend(n);
        displayfrombeg();
        break;
    }
    return 0;
}

void createlist(int n){
    int i,data;
    struct node *newnode;
    head = (struct node*)malloc(sizeof(struct node));
 
    printf("Enter the data in node 1: \n");
    scanf("%d", &data);
 
    head->data = data;
    head->next = NULL;
    head->prev = NULL;
    last = head;
    
    for(i=1;i<n;i++){
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data in node %d: \n", i+1);
        scanf("%d", &data);
       
        newnode->data = data;
        newnode->prev = last;
        newnode->next = NULL;
       
       last->next = newnode;
       last = newnode;
    }
}
    
void displayfrombeg(){
    struct node *ptr = head;
    printf("Data in the list from beginning is: \n");
    while(ptr!=NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

void displayfromend(){
    struct node *ptr = last;
    printf("Data in the list from end is: \n");
    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->prev;
    }
}

void insertatbeg(){
    int data;
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data to be inserted: \n");
    scanf("%d", &data);
    
    newnode->next = head;
    newnode->data = data;
    newnode->prev = NULL;
    head->prev = newnode;
    head = newnode;
}

void insertatend(){
    int data;
    struct node *newnode,*ptr = head;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data to be inserted: \n");
    scanf("%d", &data);
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    newnode->data = data;
    newnode->next = NULL;
    ptr->next = newnode;
    newnode->prev = ptr;
    last = newnode;
}

void insertatindex(int index){
    int data,i;
    struct node *newnode,*ptr = head;
    newnode = (struct node*)malloc(sizeof(struct node));
    if(index == 0){
        insertatbeg();
    }
    else{
    printf("Enter the data to be inserted: \n");
    scanf("%d", &data);
    for(i=1;i<index;i++){
        ptr = ptr->next;
    }
    newnode->data = data;
    newnode->next = ptr->next;
    newnode->prev = ptr;
    ptr->next = newnode;
    }
}

void deleteatbeg(){
    struct node*ptr = head;
    head = head->next;
    head->prev = NULL;
    free(ptr);
}

void deleteatend(){
    struct node*ptr = last;
    last = ptr->prev;
    last->next = NULL;
    free(ptr);
}

void deleteatindex(int index){
    int i;
    struct node*ptr = head;
    if(index==1){
        deleteatbeg();
    }
    else{
    for(i=1;i<index;i++){
        ptr = ptr->next;
    }
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    free(ptr);
    }
}
