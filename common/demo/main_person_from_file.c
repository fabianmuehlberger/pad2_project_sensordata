#include <stdio.h>
#include <stdlib.h>
#include <list/list.h>
#include <person/person.h>


int main(int argc, char **argv) {
    char *filename = "../../names.txt";
    if(argc > 1){
        filename = argv[1];
    }        
    printf("reading file: %s\n", filename);
    struct Entry *head = NULL;
    head = read(filename, &fscanf_person);
    print(head, &print_person);
    clear(head, &free_person);
    return 0;
}
