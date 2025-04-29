#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int data;
    char name[50];
    struct node *prev, *next;
}*head = NULL, *tail = NULL;

void PushHead(char name[], int data){
    struct node *newNode = (node*) malloc(sizeof(node));

    newNode -> next = newNode -> prev = NULL;
    newNode -> data = data;
    strcpy(newNode -> name, name);

    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        head -> prev = newNode;
        newNode -> next = head;
        head = newNode;
    }
}

void PushTail(char name[], int data){
    struct node *newNode = (node*) malloc(sizeof(node));

    newNode -> data = data;
    strcpy(newNode -> name, name);
    newNode -> next = newNode -> prev = NULL;

    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail -> next = newNode;
        newNode -> prev = tail;
        tail = newNode;
    }
}

void PushMid(char name[], int data){
    struct node *newNode = (node*) malloc(sizeof(node));
    struct node *temp = head;

    newNode -> data = data;
    strcpy(newNode -> name, name);
    newNode -> next = newNode -> prev = NULL;

    if(head == NULL){
        head = tail = newNode;
    }
    else if(head == tail){
        PushTail(name, data);
    }
    else{
        // while((strcmp(newNode -> name, temp -> name) != 0) && temp -> next != NULL){
        //     temp = temp -> next;
        // }

        while((newNode -> data >= temp -> data) && temp -> next != NULL){
            temp = temp -> next;
        }

        if(temp == tail){
            PushTail(name, data);
        }
        else{
            // After
            // newNode -> next = temp -> next;
            // temp -> next -> prev = newNode;
            // temp -> next = newNode;
            // newNode -> prev = temp;
        
            // Before
            newNode -> next = temp;
            newNode -> prev = temp -> prev;
            temp -> prev -> next = newNode;
            temp -> prev = newNode;
        }
    }
}

void print(){
    struct node *temp = head;   
    if(head == NULL){
        printf("Empty\n");
    }
    else{
        while(temp != NULL){
            printf("%d %s\n", temp -> data, temp -> name);
            temp = temp -> next;
        }
    }
}

void PopHead(){
    if(head == NULL){
        return;
    }
    else if(head == tail){
        free(head);
        head = tail = NULL;
    }
    else{
        head = head -> next;
        free(head -> prev);
    }
}

void PopTail(){
    if(head == NULL){
        return;
    }
    else if(head == tail){
        free(head);
        head = tail = NULL;
    }
    else{
        tail = tail -> prev;
        free(tail -> next);
        tail -> next = NULL;
    }
}

void PopMid(char name[], int data){
    struct node *temp = head;
    struct node *temp2 = NULL;
    if(head == NULL){
        return;
    }
    else if(head == tail){
        free(head);
    }
    else{
        while((strcmp(temp -> name, name) != 0) && temp -> next != NULL){
            temp = temp -> next;
        }

        if(temp == tail){
            PopTail();
        }
        else{
            temp -> prev -> next = temp -> next;
            temp -> next -> prev = temp -> prev;
            free(temp);
        }
    }
}

int main(){

    // PushHead("Josh", 18);
    // PushHead("Mike", 19);
    // PushHead("Hosi", 20);
    
    // PushTail("Rick", 21);
    // PushTail("Nico", 22);

    // PushMid("Step", 23);

    PushHead("Josh", 1);
    PushHead("Mike", 1);
    PushHead("Hosi", 1);
    
    PushTail("Rick", 2);
    PushTail("Nico", 2);

    PushMid("Step", 1);

    PopTail();
    PopHead();
    PopMid("Step", 1);
    
    print();

    return 0;
}