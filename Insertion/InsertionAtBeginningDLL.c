#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
};

void displaylist(struct node *head){
    struct node *ptr = head;
    printf("The Double Linked List Elements are:");

    if(head == NULL){
        printf(" Empty");
    }

    while(ptr != NULL){
        printf(" %d", ptr -> data);
        ptr = ptr -> next;
    }

    puts("");
}

struct node* insertionAtBeginning(struct node* head, int data){
    struct node *temp = (struct node*) malloc(sizeof(struct node));

    temp -> prev = NULL;
    temp -> data = data;
    temp -> next = head;
    head -> prev = temp;
    head = temp;
    
    return head;
}

int main(){

    struct node *head = (struct node*) malloc(sizeof(struct node));

    head -> prev = NULL;
    head -> data = 17;
    head -> next = NULL;

    int data = 16;
    head = insertionAtBeginning(head, data);

    displaylist(head);

    return 0;
}