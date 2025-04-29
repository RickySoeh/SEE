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

struct node *insertionAfterPosition(struct node *head, int data, int pos){
    struct node *temp = head;
    struct node *temp2 = NULL;
    struct node *ptr = (struct node*) malloc(sizeof(struct node));

    ptr -> prev = NULL;
    ptr -> data = data;
    ptr -> next = NULL;

    while(pos != 1){
        temp = temp -> next;
        pos--; 
    }

    temp2 = temp -> next;

    temp -> next = ptr;
    ptr -> prev = temp;
    
    temp2 -> prev = ptr;
    ptr -> next = temp2;

    return head;
}

int main(){

    struct node *head = (struct node*) malloc(sizeof(struct node));
    struct node *first = (struct node*) malloc(sizeof(struct node));
    struct node *second = (struct node*) malloc(sizeof(struct node));

    head -> prev = NULL;
    head -> data = 25;
    head -> next = first;

    first -> prev = head;
    first -> data = 30;
    first -> next = second;

    second -> prev = first;
    second -> data = 35;
    second -> next = NULL;

    head = insertionAtPosition(head, 32, 2);
    displaylist(head);

    free(second);
    free(first);
    free(head);

    return 0;
}