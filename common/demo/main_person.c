#include <stdio.h>
#include <stdlib.h>
#include <list/list.h>
#include <person/person.h>


int main(int argc, char **argv) {
    struct Entry *head = NULL;
    head = add(head, allocate_person("Thomas", 32));
    head = add(head, allocate_person("Max", 43));
    head = add(head, allocate_person("Klaus", 44));
    print(head, &print_person);
	clear(head, &free_person);
    return 0;
}
