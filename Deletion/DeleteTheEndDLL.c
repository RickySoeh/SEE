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

struct node* deleteTheEnd(struct node *head){
    struct node *temp = head;

    while(temp -> next != NULL){
        temp = temp -> next;
    }

    temp -> prev -> next = NULL;
    free(temp);

    return head;
}

int main(){

    struct node *head = (struct node*) malloc(sizeof(struct node));
    struct node *first = (struct node*) malloc(sizeof(struct node));
    struct node *second = (struct node*) malloc(sizeof(struct node));

    head -> prev = NULL;
    head -> data = 10;
    head -> next = first;

    first -> prev = head;
    first -> data = 20;
    first -> next = second;

    second -> prev = first;
    second -> data = 30;
    second -> next = NULL;

    head = deleteTheEnd(head);  
    displaylist(head);

    free(second);
    free(first);
    free(head);

    return 0;
}