#include <stdio.h>
#include <stdlib.h>

typedef struct nodes {
    int data;
    struct nodes* next;
} node_sll;

typedef struct noded {
    int data;
    struct noded* prev;
    struct noded* next;
} node_dll;

typedef struct nodex {
    int data;
    struct node* pnx; // prev,next -> xor
} node_xll;

void push(node_dll** head, int data){
    node_dll* node = malloc(sizeof(node_dll));
    node->data = data;
    node->next = *head;
    node->prev = NULL;
    if (*head != NULL){
        (*head)->prev = node;
    }
    *head = node;
}

void print_elements(node_dll* head){
    node_dll* current = head;
    while (current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    putchar('\n');
}

void freeList(node_dll** head){
    node_dll* current = *head;
    while (current != NULL){
        if (current->prev != NULL){
            free(current->prev);
        }
        current = current->next;
    }
    free(current);
    *head = NULL;
}

int main(){
   /* node_dll* dll = NULL;
    push(&dll, 10);
    push(&dll, 20);
    push(&dll, 50);
    push(&dll, 100);
    print_elements(dll);*/
    int a = 3456435;
    a ^= a;
    printf("a = %d\n", a);
    return 0;
}