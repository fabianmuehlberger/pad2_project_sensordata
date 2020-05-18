#include <string.h>
#include <stdlib.h>
#include "person/person.h"

struct Person* allocate_person(const char *name, int alter){
    struct Person *person = malloc(sizeof(struct Person));
	size_t count = strlen(name);
	person->name = malloc(sizeof(char) * (count + 1));
	strcpy(person->name, name);
    person->alter = alter;
	return person;
}


void free_person(void* data){
    struct Person *person = data;
    free(person->name);
    free(person);
}



void* fscanf_person(FILE *file){    
    char name[0xFF];
    int alter;
    int n;
    struct Person *person = NULL;
    if ((n = fscanf(file, "%d,%s", &alter, name)) > 0){
        printf ("%d, %s,%d\n", n, name, alter);
        person = allocate_person(name, alter);
    }
    return person;
}

void print_person(void* data){
    struct Person *person = data;
    printf("%10s %3d", person->name, person->alter);
}
