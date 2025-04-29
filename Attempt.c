#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int data;
    char name[100];
    struct node *next, *prev;
};

void displaylist(struct node *head){
    struct node *ptr = head;
    printf("The linked list elements are: ");
    if(head == NULL){
        printf("Empty");
        return;
    }

    while(ptr != NULL){
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    }

    puts("");
}

struct node *add_new(struct node *head, int data){
    struct node *temp = (struct node*) malloc(sizeof(struct node));

    temp -> prev = NULL;
    temp -> data = data;
    temp -> next = NULL;

    return temp;
}

struct node *addfirst(struct node *head, int data){
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    struct node *ptr = head;

    temp -> data = data;
    
    ptr -> prev = temp;
    temp -> next = head;

    head = temp;
    return head;
}

struct node *addlast(struct node *head, int data){
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    struct node *ptr = head;

    temp -> data = data;
    temp -> prev = NULL;
    temp -> next = NULL;

    while(ptr -> next != NULL){
        ptr = ptr -> next;
    }

    ptr -> next = temp;
    temp -> prev = ptr;

    return head;
}

struct node *addpos(struct node *head, int data, int pos){
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    struct node *ptr = head;
    struct node *temp2 = NULL;
    
    pos--;
    while(pos != 0){
        ptr = ptr -> next;
        pos--;
    }

    temp -> data = data;

    temp2 = ptr -> next;   
    ptr -> next = temp;
    temp -> prev = ptr;

    temp -> next = temp2;
    temp2 -> prev = temp;

    temp2 = NULL;
    return head;
}

struct node *delfirst(struct node *head){
    struct node *temp = head;

    temp -> next -> prev = NULL;
    head = temp -> next;

    free(temp);
    return head;
}

struct node *dellast(struct node *head){
    struct node *temp = head;

    while(temp -> next != NULL){
        temp = temp -> next;
    }

    temp -> prev -> next = NULL;
    free(temp);

    return head;
}

int main(){

    struct node *head = NULL;
    int data;

    scanf("%d", &data);
    head = add_new(head, data);

    int num;

    printf("Choose an option:\n");
    printf("1. Add at the beginning\n");
    printf("2. Add at the end\n");
    printf("3. Add at a position\n");
    printf("4. Delete the beginning\n");
    printf("5. Delete the end\n");
    printf("6. Display List\n");
    printf("7. Exit\n");

    printf("Your choice: ");
    scanf("%d", &num);
    
    int number;
    int pos;

    while(num == 1 || num == 2 || num == 3 || num == 4 || num == 5 || num == 6){
        if(num == 1){
            printf("Input Data: ");
            scanf("%d", &number); getchar();
            head = addfirst(head, number);

            printf("Successfully Added!\n");
            printf("\n\n\n\n\n\n");
        }
        else if(num == 2){
            printf("Input Data: ");
            scanf("%d", &number); getchar();
            head = addlast(head, number);

            printf("Successfully Added!\n");
            printf("\n\n\n\n\n\n");
        }
        else if(num == 3){
            printf("Input Data: ");
            scanf("%d", &number); getchar();
            printf("Input Position: ");
            scanf("%d", &pos); getchar();
            head = addpos(head, number, pos);

            printf("Successfully Added!\n");
            printf("\n\n\n\n\n\n");
        }
        else if(num == 4){
            head = delfirst(head);
            printf("Deletion Successful!\n");
            printf("\n\n\n\n\n\n");
        }
        else if(num == 5){
            head = dellast(head);
            printf("Deletion Successful!\n");
            printf("\n\n\n\n\n\n");
        }
        else if(num == 6){
            displaylist(head);
            printf("\n\n\n\n\n\n");
        }
        else if(num == 7){
            break;
        }

        printf("Choose an option:\n");
        printf("1. Add at the beginning\n");
        printf("2. Add at the end\n");
        printf("3. Add at a position\n");
        printf("4. Delete the beginning\n");
        printf("5. Delete the end\n");
        printf("6. Display List\n");
        printf("7. Exit\n");

        printf("Your choice: ");
        scanf("%d", &num); getchar();

    }

    system("cls");
    printf("Program Exited Succesfully!\n");
    printf("Press enter to continue...\n");

    return 0;
}