#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *next;
    int data;
    struct node *prev;
};

void displaylist(struct node *head){
    struct node *ptr = head;
    printf("The Double Linked List");

    if(head == NULL){
        printf(" Empty");
    }

    while(ptr != NULL){
        printf(" %d", ptr -> data);
        ptr = ptr -> next;
    }

    puts("");
}

struct node *insertionAtEnd(struct node *head, int data){
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    struct node *ptr = head;

    temp -> data = data;
    temp -> next = NULL;

    while(ptr -> next != NULL){
        ptr = ptr -> next;
    }

    temp -> prev = ptr;
    ptr -> next = temp;

    return head;
    
}
 
int main(){

    struct node *head = (struct node*) malloc(sizeof(struct node));
    struct node *first = (struct node*) malloc(sizeof(struct node));

    head -> prev = NULL;
    head -> data = 10;
    head -> next = first;

    first -> prev = head;
    first -> data = 20;
    first -> next = NULL;

    head = insertionAtEnd(head, 30);
    displaylist(head);

    free(first);
    free(head);

    return 0;
}