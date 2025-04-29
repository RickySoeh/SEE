#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int data;
    char name[50];
    struct node *prev, *next;
};

void displaylist(struct node *head){
    struct node *ptr = head;

    if(head == NULL){
        printf("Empty\n");
    }

    while(ptr != NULL){
        printf("%s : %d\n", ptr -> name, ptr -> data);
        ptr = ptr -> next;
    }
}

struct node *pushhead(struct node *head, int data, char name[]){
    struct node *ptr = (struct node*) malloc(sizeof(struct node));

    if(head == NULL){      // Apakah Linked list ada data atau tidak?

        ptr -> prev = NULL;
        ptr -> data = data;
        strcpy(ptr -> name, name);
        ptr -> next = NULL;

        head = ptr;
        return head;
    }

    ptr -> next = head;
    ptr -> data = data;
    strcpy(ptr -> name, name);
    ptr -> prev = NULL;

    head -> prev = ptr;
    head = ptr;

    return head;
}

struct node *pushtail(struct node *head, int data, char name[]){
    struct node *ptr = head;
    struct node *temp = (struct node*) malloc (sizeof(struct node));

    if(head == NULL){     // Apakah Linked list ada data atau tidak?

        ptr -> prev = NULL;
        ptr -> data = data;
        strcpy(ptr -> name, name);
        ptr -> next = NULL;

        head = ptr;
        return head;
    }

    temp -> prev = NULL;
    temp -> data = data;
    strcpy(temp -> name, name);
    temp -> next = NULL;

    while(ptr -> next != NULL){
        ptr = ptr -> next;
    }

    ptr -> next = temp;
    temp -> prev = ptr;

    ptr = NULL;
    free(ptr);

    return head;
}

struct node *pushmid(struct node *head, int data, char name[], int pos){
    struct node *ptr = head;
    // struct node *temp = (struct node*) malloc (sizeof(struct node));
    // struct node *temp2 = NULL;

    if(head == NULL){        // Apakah Linked list ada data atau tidak?

        ptr -> prev = NULL;
        ptr -> data = data;
        strcpy(ptr -> name, name);
        ptr -> next = NULL;

        head = ptr;
        return head;
    }

    else if(pos == 1){    // Apakah Linked list node yang mau dimasukkin posisi pertama 
        head = pushhead(head, data, name);
        return head;
    }

    else{                  // Diantara di paling belakang atau di tengah2 posisinya
        
        temp -> prev = NULL;
        temp -> data = data;
        strcpy(temp -> name, name);
        temp -> next = NULL;

        pos-=2;      // Before     
        // pos--;    // After     

        while(pos != 0 && ptr -> next != NULL){
            ptr = ptr -> next;
            pos--; 
        }

        if(ptr -> next == NULL){                // Misalkan Posisi yang diinginkan tidak valid dalam linked list: pos > jumlah node
            head = pushtail(head, data, name);
            return head;
        }

        else{                                   // Masukin ditengah (Push Mid)
            temp2 = ptr -> next;

            ptr -> next = temp;
            temp -> prev = ptr;

            temp -> next = temp2;
            temp2 -> prev = temp;

            temp2 = ptr = NULL;

            free(temp2);
            free(ptr);
            return head;
        }
    }
}

struct node *pophead(struct node *head){
    struct node *ptr = head -> next;

    if(head == NULL){      // Apakah ada node di linked list  
        return head;
    }
    if(head -> next = NULL){    // Apakah nodenya cuman satu 
        free(head);
        head = NULL;
        return head;
    }

    head = ptr;
    ptr = head -> prev;
    head -> prev = NULL;
    free(ptr);

    return head;
}

struct node *poptail(struct node *head){
    struct node *ptr = head;

    if(head == NULL){
        return head;
    }
    if(head -> next == NULL){
        free(head);
        head = NULL;
        return head;
    }

    while(ptr -> next != NULL){
        ptr = ptr -> next;
    }

    ptr -> prev -> next = NULL;
    free(ptr);

    return head;
}

struct node *popmid(struct node *head, int data, int pos){
    struct node *ptr = head;

    if (head == NULL){
        return head;
    }

    else if(head -> next == NULL){
        head = pophead(head);
        return head;
    }

    while(pos != 0 && ptr -> next != NULL){
        pos--;
        ptr = ptr -> next;
    }

    if(ptr -> next == NULL){
        head = poptail(head);
        return head;
    }
    else{
        ptr -> prev -> next = ptr -> next;
        ptr -> next -> prev = ptr -> prev;

        free(ptr);
        return head;
    }
}

void print(){
    printf("Select an option:\n");
    printf("1. Add data at the beginning\n");
    printf("2. Add data at the end\n");
    printf("3. Add data at a position\n");
    printf("4. Pop the beginning\n");
    printf("5. Pop the end\n");

}

int main(){

    struct node *head = NULL;

    // print();

    head = pushhead(head, 40, "Joshua");      // Stephane -> bradley ->Ricky -> josh -> mario -> hosea ->joe - mike
    head = pushhead(head, 50, "Ricky");
    head = pushhead(head, 30, "Stephane");

    // head = pushtail(head, 60, "Mario");
    // head = pushtail(head, 80, "Joe");
    // head = pushtail(head, 70, "Michael");

    head = pushmid(head, 10, "Bradley", 2);
    // head = pushmid(head, 90, "Justin", 5);
    head = pushmid(head, 20, "Hosea", 6);

    // head = pushmid(head, 100, "Cahyo", 2);

    // head = pophead(head);
    // head = pophead(head);

    // head = poptail(head);
    // head = poptail(head);

    displaylist(head);

    return 0;
}