#include<stdio.h>
#include<stdlib.h>
typedef struct nodetype{
	int data;
	struct node *next;
}node;

void createEmptyList(node **head){
    *head = NULL;

}

void insertAtEnd(node **head, int item){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = item;
    newNode->next = NULL;

    if(*head == NULL){
        *head = newNode;
    }
    else{
        node *temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtStart(node **head, int item){
    *head = (node*)malloc(sizeof(node));
    (*head)->data = item;
    (*head)->next = *head;
    node *temp = *head;
    while(temp->next != *head){
        temp = temp->next;
    }
    temp->next = *head;
}

int listLength(node *head){
    int length = 0;
    while (head != NULL)
    {
        length++;
        head = head->next;
    }
    printf("Length of List is %d",length);
    
}

void traverseInOrder(node *head){
    while(head != NULL){
        printf("%d ",head->data);
        head = head->next;
    }
}

void traverseInReverseOrder(node *head){
    if(head == NULL){
        return;
    }
    traverseInReverseOrder(head->next);
    printf("%d ",head->data);
}

node *searchInUnsortedList(node *head,int item){
    while (head != NULL && head->data != item)
    {
        head = head->next;
    }
    return head;
}

node *searchInSortedList(   node *head,int item){
    while (head != NULL&& head->data !=item)
    {
        if(head->data < item)
            return NULL;
        head = head->next;

    }
    
}


void main(){

}