#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    long long int price;   
    char type[50];
    char detail[50];
    struct node *prev, *next;
};
  
struct node *pushtail(struct node *head, long long int price, char type[], char detail[]){
    struct node *ptr = (struct node*) malloc (sizeof(struct node));
    struct node *temp = head;

    ptr -> price = price;
    strcpy(ptr -> type, type);
    strcpy(ptr -> detail, detail);
    ptr -> next = ptr -> prev = NULL;

    if(head == NULL){
        head = ptr;
        return head;
    }
    else{
        while(temp -> next != NULL){
            temp = temp -> next;
        }

        temp -> next = ptr;
        ptr -> prev = temp;
        
        return head;
    }
}

struct node *pophead(struct node *head){
    struct node *ptr = head;
    if(head == NULL){
        return head;
    }   
    else if(head -> next == NULL){
        head -> price = 0;
        strcpy(head -> detail, "");
        return head;
    }
    else{
        head -> price = 0;
        strcpy(head -> detail, "");
        return head;
    }
}

struct node *poptail(struct node *head){
    struct node *ptr = head;
    if(head == NULL){
        return head;
    }
    else if(head -> next == NULL){
        head -> price = 0;
        strcpy(head -> detail, "");
        return head;
    }
    else{
        while(ptr -> next != NULL){
            ptr = ptr -> next;
        }

        ptr -> price = 0;
        strcpy(ptr -> detail, "");
        return head;
    }
}

struct node *popmid(struct node *head, int pos){
    struct node *ptr = head;
    if(head == NULL){
        return head;
    }
    else if(head -> next == NULL){
        head = pophead(head);
        return head;
    }
    else{
        while(pos != 0){
            ptr = ptr -> next;
            pos--;
        }

        ptr -> price = 0;
        strcpy(ptr -> detail, "");
        return head;
    }
}

void printAll(struct node *head){
    long long int Arr[4] = {0};
    struct node *temp = head;

    while(temp != NULL){
        if(strcmp(temp -> type, "food") == 0){
            Arr[0] += temp -> price;
        }
        else if(strcmp(temp -> type, "house") == 0){
            Arr[1] += temp -> price;
        }
        else if(strcmp(temp -> type, "entertainment") == 0){
            Arr[2] += temp -> price;
        }
        else if(strcmp(temp -> type, "other") == 0){
            Arr[3] += temp -> price;
        }
        temp = temp -> next;
    }

    printf("food: %lld\n", Arr[0]);
    printf("house: %lld\n", Arr[1]);
    printf("entertainment: %lld\n", Arr[2]);
    printf("other: %lld\n", Arr[3]);
}

void printTransaction(struct node *head){
    struct node *temp = head;
    while(temp != NULL){
        if(temp -> price != 0){
            printf("%s (%s): %lld\n", temp -> detail, temp -> type, temp -> price);
        }
        temp = temp -> next;
    }
}

int main(){

    struct node *head = NULL;

    long long int balance;
    int amount;

    scanf("%lld", &balance);
    scanf("%d", &amount);

    char type[50];
    char detail[50];
    long long int price;

    long long int sum = 0;

    for (int i = 0; i < amount; i++){
        scanf("%s %s %lld", type, detail, &price);
        getchar();

        sum += price;
        head = pushtail(head, price, type, detail);
    }

    char deleted[50];
    scanf("%s", deleted); getchar();

    struct node *temp = head;
    int pos = 0;
    while((strcmp(deleted, temp -> detail) != 0) && temp != NULL){
        temp = temp -> next;
        pos++;
    }

    sum -= temp -> price;

    if(pos == 0){
        pophead(head);
    }
    else{
        if(temp -> next == NULL){
            poptail(head);
        }
        else{
            popmid(head, pos);
        }
    }

    printf("Account Balance: %lld\n", balance - sum);
    printAll(head);
    printTransaction(head);

    return 0;
}