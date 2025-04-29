#include <stdio.h>
#include <stdlib.h>

// Double Linked List : a collection of nodes that can move forward and backwards

//   __________________          __________________           __________________           __________________
//  | NULL | 23 | 2000 |------->| 2000 | 54 | 3000 |-------->| 3000 | 78 | 4000 |-------->|      | 90 | NULL |
//  |______|____|______|<-------|______|____|______|<--------|______|____|______|<--------|______|____|______|         
//    1000                        2000                         3000                         4000
//     ^
//     |  
//   ______
//  | 1000 |
//    head

// There needs to be two self referntial pointer one for next and one for the previous one

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

int main(){

    struct node *head = (struct node*) malloc(sizeof(struct node));

    // The first node in a double linked list that isnt head always has a prev taht is NULL
    head -> prev = NULL;
    head -> data = 10;
    head -> next = NULL;

    printf("%d\n", head -> data);

    return 0;
}