#include <stdio.h>
#include <stdlib.h>
#include "list/list.h"

struct Entry* add(struct Entry* head, void *data) {
    struct Entry *newEntry = malloc(sizeof(struct Entry));
	if (newEntry == NULL) return NULL;
    newEntry->data = data;
    newEntry->next = head;
    head = newEntry;

    return head;
}


void print(const struct Entry* list, void (*print_data)(void*)){
	if(list == NULL) return;
    struct Person *data = list->data;
    print_data(data);
    printf("%p %p\n", list, list->next);
    print(list->next, print_data);
}

void clear(struct Entry* list, void (*free_data)(void*)){
	if(list == NULL) return;
    clear(list->next, free_data);
	free_data(list->data);
	free(list);
}

struct Entry* read(const char *filename, void* (*read_data)(FILE*)){
    FILE *myfile_to_read = fopen(filename, "r") ;
    char name[0xFF];
    int alter;
    int n;
    struct Entry *head = NULL;
    void *data = NULL;
    do {
        data = read_data(myfile_to_read);
        if(data != NULL) head = add(head, data);
    } while(data != NULL);
    return head;
};
