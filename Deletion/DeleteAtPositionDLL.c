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

struct node *deleteAtPosition(struct node *head, int pos){
    struct node *temp = head;
    struct node *temp2 = NULL;

    pos--;
    while(pos != 0){
        temp = temp -> next; 
        pos--;
    }

    temp2 = temp -> next;
    temp -> prev -> next = temp2;
    temp2 -> prev = temp -> prev;

    free(temp);

    return head;


}

int main(){

    struct node *head = (struct node*) malloc(sizeof(struct node));
    struct node *first = (struct node*) malloc(sizeof(struct node));
    struct node *second = (struct node*) malloc(sizeof(struct node));
    struct node *third = (struct node*) malloc(sizeof(struct node));

    head -> prev = NULL;
    head -> data = 10;
    head -> next = first;

    first -> prev = head;
    first -> data = 20;
    first -> next = second;

    second -> prev = first;
    second -> data = 30;
    second -> next = third;

    third -> prev = second;
    third -> data = 40;
    third -> next = NULL;

    int pos = 2;
    head = deleteAtPosition(head, pos);

    displaylist(head);

    free(third);
    free(second);
    free(first);
    free(head);

    return 0;
}