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

size_t listCount(node_t* head){
    size_t cnt = 0;
    node_t* current = head;
    while (current){
        cnt++;
        current = current->next;
    }
    return cnt;
}

int* listToArray(node_t* head){
    int* arr = malloc(listCount(head) * sizeof(int));
    node_t* current = head;
    int i = 0;
    while (current){
        arr[i] = current->value;
        current = current->next;
        i++;
    }
    return arr;
}

int getMid(node_t* head){
    node_t *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->value;
}

int main(){
    node_t* head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    push(&head, 6);
    push(&head, 7);
    push(&head, 8);
    printf("%d\n", getMid(head));
    //printNums(head);
    freeList(&head);
    return 0;
}