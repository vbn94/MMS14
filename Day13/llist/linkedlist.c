#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
} node_t;

void push(node_t** head, int val){
    node_t* element = malloc(sizeof(node_t));
    element->value = val; 
    element->next = *head;
    *head = element;
}

  // head-> 5 -> 6 -> 10 -> 20 -> 45 -> NULL
void printNums(node_t* head){
    node_t* current = head;
    while (current != NULL){
        printf("%d ", current->value); // 5 6 10
        current = current->next;
    }
    putchar('\n');
}

void pop(node_t** head){
    if (*head == NULL){
        return;
    }
    node_t* temp = *head;
    *head = (*head)->next; 
    free(temp);
}

void freeList(node_t** head){
    node_t* current = *head;
    while (current != NULL){
        node_t* temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}

int main(){
    node_t* head = NULL;
    pop(&head);
    push(&head, 45);
    push(&head, 23);
    push(&head, 1500);
    printNums(head);
    pop(&head);
    printNums(head);
    freeList(&head);
    return 0;
}