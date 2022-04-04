#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct Book {
    char title[100];
    int pages; 
} Book;

typedef struct node {
    Book data;
    struct node* next;
} node_t;

void push(node_t** head, Book b){
    node_t* node = malloc(sizeof(node_t));
    node->data = b;
    node->next = *head;
    *head = node;
}

void printBooks(node_t* head){
    node_t* current = head;
    while (current){
        printf("Title: %20s, Pages: %d\n", current->data.title, current->data.pages);
        current = current->next;
    }
}

int main(void){
    node_t* ll = NULL;
    /*Book books[2] = {
        {.title="C programming lang", .pages=300},
        {.title="TLCL", .pages=500}
    };
    FILE *f = fopen("books.data", "wb");
    fwrite(books, sizeof(Book), 2, f);
    fclose(f);*/

    Book book;
    FILE *f = fopen("books.data", "rb");
    while(fread(&book, sizeof(Book), 1, f)){
        push(&ll, book);
    }
    fclose(f);
    printBooks(ll);
    return EXIT_SUCCESS;
}