#include <stdio.h>

typedef struct node {
    int val;
    struct node* next;
} node_t;

node_t *createNode(int val){
    node_t* node = malloc(sizeof(node_t));
    node->val = val; 
    node->next = NULL;
}

void push(node_t** head, int val){
    node_t* newnode = createNode(val);
    newnode->next = *head;
    *head = newnode;
}

int main(){
    node_t* llist = NULL;
    push(&llist, 10);
    push(&llist, 20);
    push(&llist, 30);
    return 0;
}