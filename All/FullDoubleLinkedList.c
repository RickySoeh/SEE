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

struct node* insertepmtylist(struct node *head, int data){
    struct node *ptr = (struct node*) malloc(sizeof(struct node));

    ptr -> prev = NULL;
    ptr -> data = data;
    ptr -> next = NULL;

    return ptr;
}

struct node* insertAtEnd(struct node *head, int data){
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

struct node* insertAtBeginning(struct node *head, int data){
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    struct node *ptr = head;

    temp -> data = data;

    ptr -> prev = temp;
    temp -> next = ptr;
    head = temp;

    return head;
}

struct node* insertAtPosition(struct node *head, int data, int pos){
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    struct node *temp2 = NULL;
    struct node *ptr = head;

    if(pos <= 0){
        return head;
    }

    temp -> data = data;

    pos--;
    while(pos != 1){
        ptr = ptr -> next;
        pos--;
    }

    temp2 = ptr -> next;
    temp -> prev = ptr;

    ptr -> next = temp;
    temp -> next = temp2;
    temp2 -> prev = temp;
    
    return head;
}

int main(){

    struct node *head = (struct node*) malloc(sizeof(struct node));

    int N;
    printf("Insert amount of nodes: ");
    scanf("%d", &N);

    int data;
    scanf("%d", &data);

    struct node *keep = insertepmtylist(head, data);
    head = keep;

    int C;
    int count = 0;
    for (int i = 0; i < N; i++){

        printf("Choose insertion place"); puts("");
        printf("1. At Beginning\n");
        printf("2. At End\n");
        printf("3. At a certain Position\n");

        scanf("%d", &C); getchar();

        while(C != 1 && C != 2 && C != 3){
            system("cls");
            printf("Invalid");
            puts("");
            printf("Please choose a VALID option...\n");
            puts("");
            printf("Choose insertion place"); puts("");
            printf("1. At Beginning\n");
            printf("2. At End\n");
            printf("3. At a certain Position\n");

            scanf("%d", &C); getchar();
        }

        int D;
        printf("Insert data: "); 
        scanf("%d", &D); getchar();

        int P;
        if(C == 1){
            head = insertAtBeginning(head, D);
        }
        else if(C == 2){
            head = insertAtEnd(head, D);
        }
        else if(C == 3){
            printf("Enter a position: ");
            scanf("%d", &P); getchar();

            struct node *ptr = head;

            while(ptr != NULL){
                count++;
                ptr = ptr -> next;
            }

            while(count < P){
                printf("Invalid");
                puts("");
                printf("Enter a position: ");
                scanf("%d", &P); getchar();
            }
            
            if(P == 1){
                head = insertAtBeginning(head, D);
            }
            else{
                head = insertAtPosition(head, D, P);
            }

        }
    }

    displaylist(head);
    
    struct node *temp = head;
    while(temp != NULL){
        struct node *temp2 = temp;
        temp = temp -> next;
        free(temp2);
    }  

    return 0;
}