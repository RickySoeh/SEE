#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    struct node *prev, *next;
    long long int price;
    char type[50];
    char detail[50];
};

struct node *pushtail(struct node *head, char type[], char detail[], long long int price){
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    struct node *ptr = head;

    temp -> next = temp -> prev = NULL;
    strcpy(temp -> type, type);
    strcpy(temp -> detail, detail);
    temp -> price = price;

    if(head == NULL){
        head = temp;
        return head;
    }
    else{
        while(ptr -> next != NULL){
            ptr = ptr -> next;
        }
        
        ptr -> next = temp;
        temp -> prev = ptr;

        return head;
    }
}


struct node *pophead(struct node *head){
    if(head == NULL){
        return head;
    }
    else{
        strcpy(head -> detail, "");
        head -> price = 0;
        return head;
    }
}

struct node *poptail(struct node *head){
    struct node *ptr = head;
    if(head == NULL){
        return head;
    }
    else if(head -> next == NULL){
        pophead(head);
    }
    else{
        while(ptr -> next != NULL){
            ptr = ptr -> next;
        }

        strcpy(ptr -> detail, "");
        ptr -> price = 0;

        return head;
    }
}

struct node *popmid(struct node *head){
    if(head == NULL){
        return head;
    }
    else if(head -> next = NULL){
        pophead(head);
    }
    else{
        
    }
}

int main(){




    return 0;
}