#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head;

void createlist(int n);
void display(struct node *ptr);
void insertatbeg(int data);
void insertatend(int data);
void insertatindex(int index,int data);
void deleteatbeg();
void deleteatend(int n);
void deleteatindex(int index);

int main()
{
    int n,data,index,choice;
    printf("Enter the number of nodes: \n");
    scanf("%d", &n);
    createlist(n);
    display(head);
    printf("Enter '1' to insert at beginning: \nEnter '2' to insert after node: \nEnter '3' to insert at end: \n");
    printf("Enter '4' to delete at beginning: \nEnter '5' to delete at node: \nEnter '6' to delete at end: \n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
        printf("Enter the data you want to insert in beginning: \n");
        scanf("%d", &data);
        insertatbeg(data);
        display(head);
        break;
        case 2:
        printf("Enter the data you want to insert: \n");
        scanf("%d", &data);
        printf("Enter the node after which data is to be inserted: \n");
        scanf("%d", &index);
        insertatindex(index,data);
        display(head);
        break;
        case 3:
        printf("Enter the data you want to insert in end: \n");
        scanf("%d", &data);
        insertatend(data);
        display(head);
        break;
        case 4:
        deleteatbeg(data);
        display(head);
        break;
        case 5:
        printf("Enter the node whose data is to be deleted: \n");
        scanf("%d", &index);
        deleteatindex(index);
        display(head);
        break;
        case 6:
        deleteatend(n);
        display(head);
        break;
    }
    return 0;
}


void createlist(int n){
    int i,data;
    struct node *newnode,*temp;
    head = (struct node*)malloc(sizeof(struct node));
 
    printf("Enter the data in node 1: \n");
    scanf("%d", &data);
 
    head->data = data;
    head->next = NULL;
 
    temp = head;
    for(i=1;i<n;i++){
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data in node %d: \n", i+1);
        scanf("%d", &data);
       
        newnode->data = data;
        newnode->next = NULL;
       
        temp->next = newnode;
        temp = temp->next;
    }
}

void display(struct node *ptr){
    printf("Data in the list is: \n");
    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

void insertatbeg(int data){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = head;
    head = newnode;
}

void insertatend(int data){
    struct node *newnode,*ptr = head;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    while(ptr->next != NULL){
        ptr=ptr->next;
    }
    ptr->next = newnode;
    newnode->next = NULL;
}

void insertatindex(int index,int data){
    int i;
    struct node *newnode,*ptr = head;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    if(index==0){
        insertatbeg(data);
    }
    else{
    for(i=1;i<index;i++){
        ptr = ptr->next;
    }
    newnode->next = ptr->next;
    ptr->next = newnode;
    }
}

void deleteatbeg(){
    struct node *delete = head;
    head = head->next;
    free(delete);
}

void deleteatend(int n){
    int i;
    struct node *delete = head;
    for(i=1;i<n-1;i++){
        delete = delete->next;
    }
    delete->next=NULL;
}

void deleteatindex(int index){
    int i;
    struct node *delete = head,*p;
    if(index == 1){
        deleteatbeg();
    }
    else if(index>1){
    for(i=1;i<index-1;i++){
        delete = delete->next;
    }
    p=delete->next;
    delete->next = p->next;
    free(p);
    }
}
