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

struct node* insertNewNode(struct node *head, int data){
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    // struct node *temp2 = NULL;

    temp -> prev = NULL;
    temp -> data = data;
    temp -> next = NULL;

    // temp2 = head;
    head = temp;  

    return head;
}

int main(){

    struct node *head = (struct node*) malloc(sizeof(struct node));

    int data = 90;
    head = insertNewNode(head, data);
    // head = insertNewNode(head, 10);
    // head = insertNewNode(head, 20);
    // printf("%d\n", head -> data);

    displaylist(head);

    free(head);

    return 0;
}