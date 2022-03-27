#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
} node_t;

void push(node_t** head, int val){
    node_t* el = malloc(sizeof(node_t));
    el->value = val;
    el->next = *head;
    *head = el;
}

void freeList(node_t** head){
    node_t* temp;
    while (*head != NULL){
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    *head = NULL;
}

void printList(node_t* head){
    node_t* current = head;
    while (current){
        printf("%d ", current->value);
        current = current->next;
    }
    putchar('\n');
}

int main(){
    node_t* llist = NULL;
    push(&llist, 20);
    push(&llist, 2);
    push(&llist, 5);
    push(&llist, -20);
    freeList(&llist);
    printList(llist);
    return 0;
}