#include <stdio.h>

typedef struct {
    char title[101];
    int pages;
    double price;
} Book;

int main(){
    /*Book books[] = 
    {  {.title="C programming lang", .pages=300, .price=25.20},
       {.title="Book 2", .pages=200, .price=34.20}
    };*/
    Book book;
    FILE* fp = fopen("file.data", "rb");
    while (fread(&book, sizeof(Book), 1, fp) != 0){
    }
    fclose(fp);
    return 0;
}